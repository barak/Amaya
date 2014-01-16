/*
 *
 *  (c) COPYRIGHT INRIA and W3C, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 *
 * Authors: V. Quint
 *          I. Vatton - new version of table management
 */

/* Amaya includes  */
#define THOT_EXPORT extern
#include "amaya.h"
#include "fetchXMLname_f.h"
#include "undo.h"
#include "MathML.h"

#include "EDITORactions_f.h"
#include "HTMLedit_f.h"
#include "HTMLtable_f.h"
#include "MathMLbuilder_f.h"
#include "Mathedit_f.h"

static Element      CurrentColumn = NULL;
static Element      CurrentTable = NULL;
static int          PreviousColspan;
static int          PreviousRowspan;

/*----------------------------------------------------------------------
  GetSiblingRow
  returns the sibling row before or after the cuttent row.
  ----------------------------------------------------------------------*/
Element GetSiblingRow (Element row, ThotBool before, ThotBool inMath)
{
  ElementType         elType;
  SSchema             rowSS;

  if (row)
    {
      rowSS = TtaGetElementType(row).ElSSchema;
      do
	{
	  if (before)
	    TtaPreviousSibling (&row);
	  else
	    TtaNextSibling (&row);
	  elType = TtaGetElementType (row);
	  if (elType.ElSSchema == rowSS &&
	      (inMath && (elType.ElTypeNum == MathML_EL_MTR ||
			  elType.ElTypeNum == MathML_EL_MLABELEDTR)) ||
	      (!inMath && elType.ElTypeNum == HTML_EL_Table_row))
	    return row;
	} 
      while (row);
    }
  return row;
}

/*----------------------------------------------------------------------
  GetSiblingCell
  returns the sibling cell before or after the current cell.
  ----------------------------------------------------------------------*/
static Element GetSiblingCell (Element cell, ThotBool before, ThotBool inMath)
{
  ElementType         elType;
  SSchema             cellSS;

  if (cell)
    {
      cellSS = TtaGetElementType(cell).ElSSchema;
      do
	{
	  if (before)
	    TtaPreviousSibling (&cell);
	  else
	    TtaNextSibling (&cell);
	  elType = TtaGetElementType (cell);
	  if (elType.ElSSchema == cellSS &&
	      ((inMath && elType.ElTypeNum == MathML_EL_MTD) ||
	       (!inMath && (elType.ElTypeNum == HTML_EL_Data_cell ||
			    elType.ElTypeNum == HTML_EL_Heading_cell))))
	    return cell;
	} 
      while (cell);
    }
  return cell;
}

/*----------------------------------------------------------------------
  GetFirstCellOfRow
  returns the first cell contained in a given row.
  Element row must be a table row.
  ----------------------------------------------------------------------*/
static Element GetFirstCellOfRow (Element row, ThotBool inMath)
{
  Element     firstCell, el;
  ElementType rowType, elType;

  firstCell = NULL;
  if (row)
    {
      rowType = TtaGetElementType (row);
      el = TtaGetFirstChild (row);
      while (!firstCell && el)
	{
	  elType = TtaGetElementType (el);
	  if (elType.ElSSchema == rowType.ElSSchema &&
	      ((inMath && (elType.ElTypeNum == MathML_EL_MTD ||
			   elType.ElTypeNum == MathML_EL_RowLabel)) ||
	       (!inMath && (elType.ElTypeNum == HTML_EL_Data_cell ||
			    elType.ElTypeNum == HTML_EL_Heading_cell ||
			    elType.ElTypeNum == HTML_EL_Table_cell))))
	    firstCell = el;
	  else
	    TtaNextSibling (&el);
	}
    }
  return firstCell;
}

/*----------------------------------------------------------------------
   SetRowExt
   Set the attribute RowExt of cell "cell" in row "row" according to span.
  ----------------------------------------------------------------------*/
int SetRowExt (Element cell, int span, Document doc, ThotBool inMath)
{
   Element             row, spannedrow, nextspannedrow;
   ElementType         elType;
   AttributeType       attrType;
   Attribute           attr;
   int                 overflow;

   overflow = 0;
   row = TtaGetParent (cell);
   elType = TtaGetElementType (row);
   attrType.AttrSSchema = elType.ElSSchema;
   if (inMath)
     attrType.AttrTypeNum = MathML_ATTR_MRowExt;
   else
     attrType.AttrTypeNum = HTML_ATTR_RowExt;

   if (span == 1 || span < 0)
     /* remove attribute RowExt if the cell has such an attribute */
     {
       attr = TtaGetAttribute (cell, attrType);
       if (attr)
	 TtaRemoveAttribute (cell, attr, doc);
     }
   else
     {
       if (span == 0)
	 /* "infinite" span. The cell spans to the last row in its block
	    of rows */
	 span = THOT_MAXINT;
       spannedrow = row;
       while (span > 0 && spannedrow != NULL)
	 {
	   if (span != THOT_MAXINT)
	     span--;
	   nextspannedrow = GetSiblingRow (spannedrow, FALSE, inMath);
	   if (span == 0 || nextspannedrow == NULL)
	     /* that the last row spanned by the cell */
	     {
	       attr = TtaGetAttribute (cell, attrType);
	       if (attr)
		 {
		   if (spannedrow == row)
		     /* there is actually no spanning */
		     {
		       TtaRemoveAttribute (cell, attr, doc);
		       attr = NULL;
		     }
		 }
	       else if (spannedrow != row)
		 {
		   attr = TtaNewAttribute (attrType);
		   if (attr != NULL)
		     TtaAttachAttribute (cell, attr, doc);
		 }
	       if (attr)
		 TtaSetAttributeReference (attr, cell, doc, spannedrow);
	       if (span != THOT_MAXINT)
	         overflow = span;
	     }
	   spannedrow = nextspannedrow;
	 }
     }
   return overflow;
}

/*----------------------------------------------------------------------
   SetColExt
   Sets the attribute ColExt of cell "cell" according to span.
   If the value of span is greater than the number of available cells,
   return this difference.
  ----------------------------------------------------------------------*/
int SetColExt (Element cell, int span, Document doc, ThotBool inMath,
		ThotBool deletingLastCol)
{
  ElementType         elType;
  Element             colHead, nextColHead, prevColHead;
  AttributeType       attrType, refColType;
  Attribute           attr, refColAttr;
  int                 i, overflow;

  overflow = 0;
  elType = TtaGetElementType (cell);
  attrType.AttrSSchema = elType.ElSSchema;
  refColType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    {
      attrType.AttrTypeNum = MathML_ATTR_MColExt;
      refColType.AttrTypeNum = MathML_ATTR_MRef_column;
    }
  else
    {
      attrType.AttrTypeNum = HTML_ATTR_ColExt;
      refColType.AttrTypeNum = HTML_ATTR_Ref_column;
    }
  if (span == 1 || span < 0)
    /* remove attribute ColExt */
    {
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
	TtaRemoveAttribute (cell, attr, doc);
    }
  else
    {
      /* set attribute ColExt */
      attr = TtaGetAttribute (cell, attrType);
      if (!attr)
	{
	  attr = TtaNewAttribute (attrType);
	  if (attr)
	    TtaAttachAttribute (cell, attr, doc);
	}
      if (attr)
	{
	  refColAttr = TtaGetAttribute (cell, refColType);
	  if (refColAttr)
	    {
	      TtaGiveReferenceAttributeValue (refColAttr, &colHead);
	      if (colHead)
		{
		  nextColHead = colHead;
		  prevColHead = NULL;
		  for (i = 0; (i < span || span == 0) && nextColHead; i++)
		    {
		      colHead = nextColHead;
		      TtaNextSibling (&nextColHead);
		      if (nextColHead)
			prevColHead = colHead;
		    }
		  if (i < span && span != 0)
		    /* the value of span is wrong. It's greater than the
		       number of columns */
		    overflow = span - i;
		  if (deletingLastCol && span == 0)
		    colHead = prevColHead;
		  TtaSetAttributeReference (attr, cell, doc, colHead);
		}
	    }
	}
    }
  return overflow;
}

/*----------------------------------------------------------------------
   GetCellFromColumnHead
   returns the cell that corresponds to the Column_head element colhead
   in a given row.
  ----------------------------------------------------------------------*/
Element GetCellFromColumnHead (Element row, Element colhead, ThotBool inMath)
{
   Element             cell, currentcolhead;
   ThotBool            found;
   ElementType         elType;
   AttributeType       attrType;
   Attribute           attr;

   cell = NULL;
   /* if it's not a row, return immediately with NULL */
   elType = TtaGetElementType (row);
   if ((inMath && (elType.ElTypeNum == MathML_EL_MTR ||
		   elType.ElTypeNum == MathML_EL_MLABELEDTR)) ||
       (!inMath && elType.ElTypeNum == HTML_EL_Table_row))
     {
       attrType.AttrSSchema = elType.ElSSchema;
       if (inMath)
	 attrType.AttrTypeNum = MathML_ATTR_MRef_column;
       else
	 attrType.AttrTypeNum = HTML_ATTR_Ref_column;

       cell = GetFirstCellOfRow (row, inMath);
       found = FALSE;
       while (cell && !found)
	 {
	   attr = TtaGetAttribute (cell, attrType);
	   if (attr != NULL)
	     {
	       TtaGiveReferenceAttributeValue (attr, &currentcolhead);
	       if (currentcolhead == colhead)
		 found = TRUE;
	     }
	   if (!found)
	     cell = GetSiblingCell (cell, FALSE, inMath);
	 }
     }
   return cell;
}

/*----------------------------------------------------------------------
   GetCloseCell
   returns the cell that corresponds to the Column_head element colhead
   or a previous or next colhead in a given row.
   - When the parameter before is TRUE, a previous cell is returned.
     The parameter spanupdate returns TRUE if the previous cell is extended
     (add = TRUE) or reduced (add = FALSE) and the parameter rowspan
     returns its rowspan value (1 by default).
   - When the parameter before is FALSE, the next cell is returned.
  ----------------------------------------------------------------------*/
static Element GetCloseCell (Element row, Element colhead,
			     Document doc, ThotBool before, ThotBool add,
			     ThotBool inMath, ThotBool *spanupdate,
			     int *rowspan, ThotBool deletingLastCol)
{
  Element             col, cell;
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrType, attrTypeRef;
  int                 colspan, pos;

  *spanupdate = FALSE;
  *rowspan = 1;
  col = colhead;
  elType = TtaGetElementType (col);
  cell = GetCellFromColumnHead (row, colhead, inMath);
  pos = 0;
  while (!cell && col)
    {
      /* no cell related to this column in this row */
      if (before)
	TtaPreviousSibling (&col);
      else
	TtaNextSibling (&col);
      cell = GetCellFromColumnHead (row, col, inMath);
      pos++;
    }

  if (cell && before)
    {
      /* get the colspan value of the element */
      attrType.AttrSSchema = elType.ElSSchema;
      attrTypeRef.AttrSSchema = elType.ElSSchema;
      if (inMath)
	{
	  attrTypeRef.AttrTypeNum = MathML_ATTR_MColExt;
	  attrType.AttrTypeNum = MathML_ATTR_columnspan;
	}
      else
	{
	  attrTypeRef.AttrTypeNum = HTML_ATTR_ColExt;
	  attrType.AttrTypeNum = HTML_ATTR_colspan_;
	}
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
	{
	  colspan = TtaGetAttributeValue (attr);
	  if (colspan < 0)
	    colspan = 1;
	  if (colspan == 0 ||  /* 0 means infinite span */
	      (add && colspan - pos > 1) ||
	      (!add && colspan - pos >= 1))
	    {
	      if (colspan > 0)
		if (!add && colspan == 2)
		  {
		    colspan--;
		    TtaRemoveAttribute (cell, attr, doc);
		    attr = TtaGetAttribute (cell, attrTypeRef);
		    if (attr)
		      TtaRemoveAttribute (cell, attr, doc);
		  }
		else
		  {
		    if (add)
		      colspan++;
		    else
		      colspan--;
		    TtaSetAttributeValue (attr, colspan, cell, doc);
		  }
	      if ((!add && colspan > 0 && colspan - pos == 0) ||
		  colspan == 0)
		SetColExt (cell, colspan, doc, inMath, deletingLastCol);
	      *spanupdate = TRUE;
	      /* check its rowspan attribute */
	      if (inMath)
		attrType.AttrTypeNum = MathML_ATTR_rowspan_;
	      else
		attrType.AttrTypeNum = HTML_ATTR_rowspan_;
	      attr = TtaGetAttribute (cell, attrType);
	      if (attr)
		/* this cell has an attribute rowspan */
		*rowspan = TtaGetAttributeValue (attr);
	      if (*rowspan < 0)
		*rowspan = 1;
	    }
	}
    }
  return (cell);
}

/*----------------------------------------------------------------------
   LinkCellToColumnHead link a cell to the Column_head representing the
   column it belongs to.
  ----------------------------------------------------------------------*/
static void LinkCellToColumnHead (Element cell, Element colhead,
				      Document doc, ThotBool inMath)
{
  ElementType         elType;
  AttributeType       attrType;
  Attribute           attr;

  if (cell == NULL || colhead == NULL)
    return;
  elType = TtaGetElementType (cell);
  attrType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    attrType.AttrTypeNum = MathML_ATTR_MRef_column;
  else
    attrType.AttrTypeNum = HTML_ATTR_Ref_column;
  attr = TtaGetAttribute (cell, attrType);
  if (attr == NULL)
    {
      attr = TtaNewAttribute (attrType);
      if (attr)
	TtaAttachAttribute (cell, attr, doc);
    }
  if (attr)
    TtaSetAttributeReference (attr, cell, doc, colhead);
}

/*----------------------------------------------------------------------
   AddEmptyCellInRow add an empty cell element in the given row and relates
   it to the given Column_head colhead.
   The parameter sibling gives the cell which will precede or follow the new
   cell according to the before value.
   withUndo indicate whether the new empty cell must be registered in the
   undo queue or not.
   Return the created empty cell.
  ----------------------------------------------------------------------*/
static Element AddEmptyCellInRow (Element row, Element colhead,
				  Element sibling, ThotBool before,
				  Document doc, ThotBool inMath,
				  ThotBool placeholder, ThotBool withUndo)
{
  Element             lastcell, constr;
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrType;

  lastcell = NULL;
  if (row == NULL)
    return (NULL);

  elType = TtaGetElementType (row);
  if (inMath)
    elType.ElTypeNum = MathML_EL_MTD;
  else
    elType.ElTypeNum = HTML_EL_Data_cell;
  lastcell = TtaNewTree (doc, elType, "");
  if (lastcell)
    {
      if (sibling)
	TtaInsertSibling (lastcell, sibling, before, doc);
      else
	TtaInsertFirstChild (&lastcell, row, doc);
      LinkCellToColumnHead (lastcell, colhead, doc, inMath);
      if (inMath && placeholder)
	/* put attribute IntPlaceholder on the empty Construct that has
	   been created in the new cell */
	{
	  elType.ElTypeNum = MathML_EL_Construct;
	  constr = TtaSearchTypedElement (elType, SearchInTree, lastcell);
	  if (constr)
	    {
	      attrType.AttrSSchema = elType.ElSSchema;
	      attrType.AttrTypeNum = MathML_ATTR_IntPlaceholder;
	      attr = TtaNewAttribute (attrType);
	      if (attr)
		{
		  TtaAttachAttribute (constr, attr, doc);
		  TtaSetAttributeValue (attr,
			   MathML_ATTR_IntPlaceholder_VAL_yes_, constr, doc);
		}
	    }
	}
      if (withUndo)
	TtaRegisterElementCreate (lastcell, doc);
    }
  return (lastcell);
}

/*----------------------------------------------------------------------
  CreateCellsInRowGroup
  ----------------------------------------------------------------------*/
static void CreateCellsInRowGroup (Element group, Element prevCol,
				   Element nextCol, Element colhead,
				   Document doc, ThotBool inMath,
				   ThotBool last)
{
  Element          row, child;
  ElementType      elType;
  int              rowspan;
  ThotBool         span;

  row = TtaGetFirstChild (group);
  /* skip the first elements that are now rows */
  if (row)
    elType = TtaGetElementType (row);
  while (row && elType.ElTypeNum != HTML_EL_Table_row)
    {
      TtaNextSibling (&row);
      if (row)
	elType = TtaGetElementType (row);
    }
  /* process all rows in this group */
  while (row)
    {
      span = FALSE;
      rowspan = 1;
      /* get the sibling cell */
      if (last)
	child = TtaGetLastChild (row);
      else
	/* look for the previous cell */
	child = GetCloseCell (row, prevCol, doc, TRUE, TRUE, inMath,
			      &span, &rowspan, FALSE);
      if (child)
	{
	  if (!span)
	    /* add a new cell after */
	    AddEmptyCellInRow (row, colhead, child, FALSE, doc,
			       inMath, FALSE, TRUE);
	}
      else
	{
	  /* look for the next cell */
	  child = GetCloseCell (row, nextCol, doc, FALSE, TRUE, inMath,
				&span, &rowspan, FALSE);
	  /* add before */
	  AddEmptyCellInRow (row, colhead, child, TRUE, doc, inMath,
			     FALSE, TRUE);
	}
      if (rowspan == 0)
	rowspan = THOT_MAXINT;
      while (rowspan >= 1 && row)
	{
	  row = GetSiblingRow (row, FALSE, inMath);
	  rowspan--;
	}
    }
}

/*----------------------------------------------------------------------
  NewColumnHead creates a new Column_head and returns it.   
  If generateEmptyCells == TRUE, create an additional empty cell in all
  rows, except the row indicated.
  If last == TRUE when lastcolhead is the last current column.
  The parameter before indicates if the lastcolhead precedes or follows
  the new created Column_head. It should be FALSE when last is TRUE.
  ----------------------------------------------------------------------*/
Element NewColumnHead (Element lastcolhead, ThotBool before,
		       ThotBool last, Element row, Document doc,
		       ThotBool inMath, ThotBool generateEmptyCells)
{
  Element             colhead, currentrow, firstrow;
  Element             group, groupdone, block;
  Element             prevCol, nextCol;
  Element             table, child;
  ElementType         elType;
  int                 rowspan;
  ThotBool            select, span;

  if (lastcolhead == NULL)
    return NULL;
  select = (row == NULL);
  span = FALSE;
  firstrow = NULL;
  /* create a new column head */
  elType = TtaGetElementType (lastcolhead);
  colhead = TtaNewTree (doc, elType, "");
  if (colhead != NULL)
    {
      /* insert the new column head */
      prevCol = nextCol = lastcolhead;
      if (before)
	TtaPreviousSibling (&prevCol);
      else
	TtaNextSibling (&nextCol);
      TtaInsertSibling (colhead, lastcolhead, before, doc);
      TtaRegisterElementCreate (colhead, doc);
      if (inMath)
	elType.ElTypeNum = MathML_EL_MTABLE;
      else
	elType.ElTypeNum = HTML_EL_Table_;
      table = TtaGetTypedAncestor (lastcolhead, elType);
      if (generateEmptyCells)
	/* add empty cells to all other rows */
	{
	  if (inMath)
	    elType.ElTypeNum = MathML_EL_TableRow;
	  else
	    elType.ElTypeNum = HTML_EL_Table_row;
	  if (row)
	    /* get the first row in the same group of rows */
	    {
	      group = TtaGetParent (row);
	      currentrow = TtaSearchTypedElement (elType, SearchInTree, group);
	    }
	  else
	    /* get the first row of the table */
	    currentrow = TtaSearchTypedElement (elType, SearchInTree, table);
	  firstrow = currentrow;

	  while (currentrow)
	    {
	      rowspan = 1;
	      if (currentrow == row && last)
		/* we are not supposed to create more rows. Stop */
		currentrow = NULL;
	      /* don't process the row containing the initial cell */
	      else if (currentrow != row)
		{
		  /* get the sibling cell */
		  if (last)
		    child = TtaGetLastChild (currentrow);
		  else
		    /* look for the previous cell */
		    child = GetCloseCell (currentrow, prevCol, doc, TRUE, TRUE,
					  inMath, &span, &rowspan, FALSE);
		  if (child)
		    {
		      if (!span)
			{
			  if (select && row == NULL)
			    /* first row where a cell is created */
			    row = currentrow;
			  /* add a new cell after */
			  AddEmptyCellInRow (currentrow, colhead, child, FALSE,
					     doc, inMath, FALSE, TRUE);
			  TtaChangeInfoLastRegisteredElem (doc, 3);
			}
		    }
		  else
		    {
		      /* look for the next cell */
		      child = GetCloseCell (currentrow, nextCol, doc, FALSE,
					 TRUE, inMath, &span, &rowspan, FALSE);
		      if (select && row == NULL)
			/* first row where a cell is created */
			row = currentrow;
		      /* add a cell before */
		      AddEmptyCellInRow (currentrow, colhead, child, TRUE, doc,
					 inMath, FALSE, TRUE);
		      TtaChangeInfoLastRegisteredElem (doc, 3);
		    }
		  if (rowspan == 0)
		    rowspan = THOT_MAXINT;
		}
	      /* find the next row where a cell has to be created. Skip the
	         spanned rows */
	      while (rowspan >= 1 && currentrow)
		{
		  currentrow = GetSiblingRow (currentrow, FALSE, inMath);
		  rowspan--;
		}
	    }

	  if (!inMath)
	    {
	      groupdone = TtaGetParent (row);	/* done with this group */
	      /* process the other row groups */
	      /* visit all children of the Table element */
	      block = TtaGetFirstChild (table);
	      while (block)
		{
		  elType = TtaGetElementType (block);
		  if (elType.ElTypeNum == HTML_EL_thead ||
		      elType.ElTypeNum == HTML_EL_tfoot)
		    {
		      /* this block is a thead or tfoot element */
		      group = block;
		      if (group != groupdone)
			CreateCellsInRowGroup (group, prevCol, nextCol,
					       colhead, doc, inMath, last);
		      else if (last)
			block = NULL;
		    }
		  else if (elType.ElTypeNum == HTML_EL_Table_body)
		    {
		      /* this child is the Table_body element */
		      /* get the first tbody element */
		      group = TtaGetFirstChild (block);
		      /* process all tbody elements */
		      while (group != NULL)
			{
			  if (group != groupdone)
			    CreateCellsInRowGroup (group, prevCol, nextCol,
						   colhead, doc, inMath, last);
			  if (last)
			    {
			      group = NULL;
			      block = NULL;
			    }
			  else
			    TtaNextSibling (&group);
			}
		    }
		  if (block)
		    TtaNextSibling (&block);
		}
	    }
	  HandleColAndRowAlignAttributes (firstrow, doc);
	}
    }
  if (select)
    {
      child = GetCellFromColumnHead (row, colhead, inMath);
      child = TtaGetFirstChild (child);
      if (child)
	TtaSelectElement (doc, child);
    }
  return colhead;
}

/*----------------------------------------------------------------------
  RemoveColumn remove the current colhead if it's empty.
  The parameter ifEmpty makes removing optional.
  Returns TRUE if the column has been removed.
  ----------------------------------------------------------------------*/
ThotBool RemoveColumn (Element colhead, Document doc, ThotBool ifEmpty,
		       ThotBool inMath)
{
  Element             row, firstrow;
  Element             cell, group, table;
  ElementType         elType;
  AttributeType       attrType;
  Attribute           attr;
  int                 rowType, colspan;
  ThotBool            empty, span;

  empty = FALSE; /* return TRUE if the column is deleted */
  if (colhead == NULL)
    return (empty);

  /* check if the column becomes empty */
  elType = TtaGetElementType (colhead);
  attrType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_MTABLE;
      rowType = MathML_EL_TableRow;
      attrType.AttrTypeNum = MathML_ATTR_columnspan;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Table_;
      rowType = HTML_EL_Table_row;
      attrType.AttrTypeNum = HTML_ATTR_colspan_;
    }

  table = TtaGetTypedAncestor (colhead, elType);
  elType.ElTypeNum = rowType;
  firstrow = TtaSearchTypedElement (elType, SearchInTree, table);
  if (colhead != NULL && firstrow != NULL)
    {
      empty = TRUE;  /* TRUE when all cells are empty */
      if (ifEmpty)
	{
	  row = firstrow;
	  /* the rows group could be thead, tbody, tfoot */
	  group = TtaGetParent (row);
	  while (row && empty)
	    {
	      cell = GetCellFromColumnHead (row, colhead, inMath);
	      if (cell != NULL && TtaGetElementVolume (cell) != 0)
		empty = FALSE;
	      else
		{
		row = GetSiblingRow (row, FALSE, inMath);
	        /* do we have to get a new group of rows */
	        if (row == NULL && !inMath)
		  {
		  elType = TtaGetElementType (group);
		  if (elType.ElTypeNum == HTML_EL_tbody)
		    {
		      row = group;
		      group = TtaGetParent (group);
		      TtaNextSibling (&row);
		      if (row != NULL)
			group = row;
		      else
			TtaNextSibling (&group);
		    }
		  else
		    {
		      TtaNextSibling (&group);
		      if (group != NULL)
			{
			  elType = TtaGetElementType (group);
			  if (elType.ElTypeNum == HTML_EL_Table_body)
			    group = TtaGetFirstChild (group);
			}
		    }
		  if (group != NULL)
		    row = TtaGetFirstChild (group);
		  else
		    row = NULL;
		  }
		}
	    }
	}

      if (empty)
	{
	  span = FALSE; /* TRUE when a cell with a span value is deleted */
	  /* remove the current column */
	  row = firstrow;
	  /* the rows group could be thead, tbody, or tfoot */
	  group = TtaGetParent (row);
	  while (row != NULL)
	    {
	      cell = GetCellFromColumnHead (row, colhead, inMath);
	      if (cell != NULL)
		{
		  if (!inMath)
		    {
		      /* look at whether it's a spanning column */
		      attr = TtaGetAttribute (cell, attrType);
		      if (attr)
			{
			  colspan = TtaGetAttributeValue (attr);
			  if (colspan == 0 || colspan > 1)
			    /* colspan = 0 means infinite span */
			    span = TRUE;
			}
		    }
		  /* register the deleted cells only if the column is
		     deleted explicitely by the user */
		  if (!ifEmpty)
		    if (TtaPrepareUndo (doc))
		      {
		        TtaRegisterElementDelete (cell, doc);
                        /* change the value of "info" in the latest cell
			   deletion recorded in the Undo queue. The goal is to
			   allow procedure CellPasted to regenerate only one
			   column head when undoing the operation */
			TtaChangeInfoLastRegisteredElem (doc, 3);
		      }
		  TtaDeleteTree (cell, doc);
		}
	      row = GetSiblingRow (row, FALSE, inMath);
	      /* do we have to get a new group of rows */
	      if (row == NULL && !inMath)
		{
		  elType = TtaGetElementType (group);
		  if (elType.ElTypeNum == HTML_EL_tbody)
		    {
		      row = group;
		      group = TtaGetParent (group);
		      TtaNextSibling (&row);
		      if (row != NULL)
			group = row;
		      else
			TtaNextSibling (&group);
		    }
		  else
		    {
		      TtaNextSibling (&group);
		      if (group != NULL)
			{
			  elType = TtaGetElementType (group);
			  if (elType.ElTypeNum == HTML_EL_Table_body)
			    group = TtaGetFirstChild (group);
			}
		    }
		  if (group != NULL)
		    row = TtaGetFirstChild (group);
		  else
		    row = NULL;
		}
	    }
	  TtaDeleteTree (colhead, doc);
	  if (!ifEmpty)
	    if (TtaPrepareUndo (doc))
	      /* The value of "info" in the latest cell deletion recorded in
		 the Undo queue should be 4 to allow procedure CellPasted to
		 regenerate a column head for the last cell when undoing
		 the operation */
		TtaChangeInfoLastRegisteredElem (doc, 4);
	  if (span)
	     CheckAllRows (table, doc, FALSE, FALSE);
	}
    }
  return (empty);
}

#define MAX_COLS 100
/*----------------------------------------------------------------------
  CheckAllRows
  ----------------------------------------------------------------------*/
void CheckAllRows (Element table, Document doc, ThotBool placeholder,
		   ThotBool deleteLastEmptyColumns)
{
  Element            *colElement, *delayedColExt;
  Element             row, nextRow, firstrow, colhead, prevColhead;
  Element             cell, nextCell, group, prevGroup, new_, prev, el, next;
  ElementType         elType;
  AttributeType       attrTypeHSpan, attrTypeVSpan, attrType;
  Attribute           attr;
  SSchema             tableSS;
  int                *colVSpan;
  int                 span, cRef, cNumber, cDelayed, overflow;
  int                 i, rowType;
  ThotBool            inMath;

  if (table == NULL)
    return;
  /* get some memory to store the list of colheads */
  i = sizeof (Element) * MAX_COLS;
  colElement = (Element*)TtaGetMemory (i);
  memset (colElement, 0, i);
  delayedColExt = (Element*)TtaGetMemory (i);
  memset (delayedColExt, 0, i);
  i = sizeof (int) * MAX_COLS;
  colVSpan = (int *)TtaGetMemory (i);
  memset (colVSpan, 0, i);
  elType = TtaGetElementType (table);
  tableSS = elType.ElSSchema;
  attrType.AttrSSchema = tableSS;
  attrTypeHSpan.AttrSSchema = tableSS;
  attrTypeVSpan.AttrSSchema = tableSS;
  inMath = TtaSameSSchemas (tableSS, TtaGetSSchema ("MathML", doc));
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_MColumn_head;
      rowType = MathML_EL_TableRow;
      attrTypeHSpan.AttrTypeNum = MathML_ATTR_columnspan;
      attrTypeVSpan.AttrTypeNum = MathML_ATTR_rowspan_;
      attrType.AttrTypeNum = MathML_ATTR_MColExt;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Column_head;
      rowType = HTML_EL_Table_row;
      attrTypeHSpan.AttrTypeNum = HTML_ATTR_colspan_;
      attrTypeVSpan.AttrTypeNum = HTML_ATTR_rowspan_;
      attrType.AttrTypeNum = HTML_ATTR_ColExt;
    }

  colhead = TtaSearchTypedElement (elType, SearchInTree, table);
  cNumber = 0;
  cDelayed = 0;
  while (colhead != 0 && cNumber < MAX_COLS)
    {
      colElement[cNumber] = colhead;
      colVSpan[cNumber] = 0;
      TtaNextSibling (&colhead);
      cNumber++;
    }

  /* remove text elements at the first level */
  el = TtaGetFirstChild (table);
  while (el)
    {
      next = el; TtaNextSibling (&next);
      if (TtaGetElementType (el).ElTypeNum == HTML_EL_TEXT_UNIT)
	TtaDeleteTree (el, doc);
      el = next;
    }

  cell = NULL;
  elType.ElTypeNum = rowType;
  firstrow = TtaSearchTypedElement (elType, SearchInTree, table);
  if (cNumber != 0 && firstrow != NULL)
    {
    row = firstrow;
    /* the rows group could be thead, tbody, tfoot */
    group = TtaGetParent (row);
    while (row)
      {
      nextRow = row;
      TtaNextSibling (&nextRow);
      elType = TtaGetElementType (row);
      if ((!inMath && elType.ElTypeNum == rowType) ||
	  (inMath && (elType.ElTypeNum == MathML_EL_MTR ||
		      elType.ElTypeNum == MathML_EL_MLABELEDTR)))
	{
	/* treat all cells in the row */
	cRef = 0;
	cell = NULL;
	/* get the first cell in the row, ignoring other elements such as
	   comments or elements from other namespaces */
        nextCell = GetFirstCellOfRow (row, inMath);
	if (nextCell && inMath &&
	    TtaGetElementType(row).ElTypeNum == MathML_EL_MLABELEDTR)
	  /* skip the first significant child of the row: it's a label */
	  {
	  /* skip comments and PIs first */
	  do
	    {
	    elType = TtaGetElementType (nextCell);
	    if (elType.ElTypeNum == MathML_EL_XMLcomment ||
		elType.ElTypeNum == MathML_EL_XMLPI)
	      TtaNextSibling (&nextCell);
	    }
	  while (nextCell &&
		 (elType.ElTypeNum == MathML_EL_XMLcomment ||
		  elType.ElTypeNum == MathML_EL_XMLPI));
	  /* skip the following element */
	  nextCell = GetSiblingCell (nextCell, FALSE, inMath);
	  }
	while (nextCell)
	  {
	  cell = nextCell;
          TtaNextSibling (&nextCell);
	  elType = TtaGetElementType (cell);
	  if (!inMath && elType.ElTypeNum == HTML_EL_Table_cell)
	    {
	    /* replace a Table_cell by a Data_cell */
	    elType.ElTypeNum = HTML_EL_Data_cell;
	    new_ = TtaNewTree (doc, elType, "");
	    TtaInsertFirstChild (&new_, cell, doc);
	    cell = new_;
	    }
	  
	  /* process only cell elements */
	  if ((inMath && elType.ElTypeNum == MathML_EL_MTD) ||
	      (!inMath && (elType.ElTypeNum == HTML_EL_Data_cell ||
			   elType.ElTypeNum == HTML_EL_Heading_cell)))
	    {
	    /* is there any rowspan attribute in previous row */
	    while (cRef < cNumber && colVSpan[cRef] > 0)
	      {
		if (colVSpan[cRef] < THOT_MAXINT)
		  colVSpan[cRef]--;
		cRef++;
	      }
	    
	    if (cRef == cNumber && cRef < MAX_COLS)
	      {
	      /* there is no Column_head for that cell */
	      /* Create an additional Column_head */
	      colElement[cRef] = NewColumnHead (colElement[cRef - 1], FALSE,
						TRUE, row, doc, inMath, TRUE);
	      colVSpan[cRef] = 0;
	      cNumber++;
	      }
	    
	    if (cRef < cNumber)
	      {
	      /* link the cell to its corresponding Column_head */
	      LinkCellToColumnHead (cell, colElement[cRef], doc, inMath);

	      /* is there an attribute rowspan for that cell ? */
	      attr = TtaGetAttribute (cell, attrTypeVSpan);
	      if (attr == NULL)
		span = 1;
	      else
		{
		  span = TtaGetAttributeValue (attr);
		  /* Set the attribute RowExt if row span > 1 */
		  if (span > 1)
		    colVSpan[cRef] = span - 1;
		  else if (span == 0)
		    colVSpan[cRef] = THOT_MAXINT;
		}
	      overflow = SetRowExt (cell, span, doc, inMath);
	      if (overflow > 0 && attr)
		/* spanning value is too high. update it */
		TtaSetAttributeValue (attr, span-overflow, cell, doc);

	      /* if there an attribute colspan for that cell,
		 update attribute ColExt */
	      attr = TtaGetAttribute (cell, attrTypeHSpan);
	      if (attr == NULL)
		/* no colspan attribute */
		span = 1;
	      else
		{
		span = TtaGetAttributeValue (attr);
		if (span == 0)
		  /* infinite span */
		  span = THOT_MAXINT;
		if (span > 1)
		  {
		  i = 1;
		  while (i < span && cRef + 1 < cNumber)
		    {
		      cRef++;
		      colVSpan[cRef] = colVSpan[cRef-1];
		      i++;
		    }
		  if (GetSiblingCell (cell, FALSE, inMath))
		    /* There are more cells in this row, after the spanning
		       cell. Create additional Column_heads for the spanning
		       cell, except if spanning is "infinite". */
		    {
		    if (span < THOT_MAXINT)
		      while (i < span)
			{
			if (cRef + 1 < MAX_COLS)
			  {
			  cRef++;
			  colElement[cRef] = NewColumnHead (colElement[cRef-1],
					  FALSE, TRUE, row, doc, inMath, TRUE);
			  cNumber++;
			  }
			colVSpan[cRef] = colVSpan[cRef-1];
			i++;
			}
		    }
		  else if (i < span)
		    {
		      /* The colspan cannot be applied now */
		      if (cDelayed < MAX_COLS)
		        delayedColExt[cDelayed++] = cell;
		      span = 1;
		    }
		  
		  }
		}
	      SetColExt (cell, span, doc, inMath, FALSE);

	      cRef++;
	      }
	    }

	  /* accept comments, PIs and invalid elements */
	  else if ((!inMath &&
		    elType.ElTypeNum != HTML_EL_Invalid_element &&
		    elType.ElTypeNum != HTML_EL_Comment_ &&
		    elType.ElTypeNum != HTML_EL_XMLPI) ||
		   (inMath &&
		    elType.ElTypeNum != MathML_EL_XMLcomment &&
		    elType.ElTypeNum != MathML_EL_XMLPI))
	    /* Delete any other type of element */
	    TtaDeleteTree (cell, doc);
	  }
	
	/* check missing cells */
	while (cRef < cNumber)
	  {
	  if (colVSpan[cRef] > 0)
	    {
	      if (colVSpan[cRef] < THOT_MAXINT)
		colVSpan[cRef]--;
	    }
	  else
	    cell = AddEmptyCellInRow (row, colElement[cRef], cell, FALSE, doc,
				      inMath, placeholder, TRUE);
	  cRef++;
	  }
	}
      /* accept comments, PIs and invalid elements */
      else if ((!inMath &&
		elType.ElTypeNum != HTML_EL_Invalid_element &&
		elType.ElTypeNum != HTML_EL_Comment_ &&
		elType.ElTypeNum != HTML_EL_XMLPI) ||
	       (inMath &&
		elType.ElTypeNum != MathML_EL_XMLcomment &&
		elType.ElTypeNum != MathML_EL_XMLPI))
	/* Delete any other type of element */
	TtaDeleteTree (row, doc);
      row = nextRow;

      /* do we have to get a new group of rows */
      if (row == NULL && !inMath)
	{
	elType = TtaGetElementType (group);
	if (elType.ElTypeNum == HTML_EL_tbody)
	  /* this is a tbody. Is there a sibling tboby in the same
	     Table_body parent? */
	  {
	  row = group;
	  group = TtaGetParent (group); /* the Table_body parent */
	  TtaNextSibling (&row); /* next sibling of the current tbody */
	  if (row != NULL)
	    {
	    /* skip comments and other unsignificant elements, until we get
	       a sibling tbody */
	    elType = TtaGetElementType (row);
	    while (row && (elType.ElSSchema != tableSS ||
			   elType.ElTypeNum != HTML_EL_tbody))
	      {
		prev = row;
		TtaNextSibling (&row);
		/* remove text leaves between tbody elements */
		if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
		  TtaDeleteTree (prev, doc);
		if (row)
		  elType = TtaGetElementType (row);
	      }
	    if (row)
	      group = row;
	    }
	  if (row == NULL)
	    /* there is no sibling tbody. Get the next sibling of the
	       Table_body element */
	    TtaNextSibling (&group);
	  }
	else
	  {
	  TtaNextSibling (&group);
	  if (group != NULL)
	    {
	    elType = TtaGetElementType (group);
	    if (elType.ElTypeNum == HTML_EL_Table_body)
	      group = TtaGetFirstChild (group);
	    }
	  }
	if (group != NULL)
	  {
	  elType = TtaGetElementType (group);
	  /* skip comments, PIs and invalid elements */
	  while (group &&
		 (elType.ElTypeNum == HTML_EL_TEXT_UNIT ||
		  elType.ElTypeNum == HTML_EL_Invalid_element ||
		  elType.ElTypeNum == HTML_EL_Comment_ ||
		  elType.ElTypeNum == HTML_EL_XMLPI))
	    {
	      prevGroup = group;
	      TtaNextSibling (&group);
	      if (elType.ElTypeNum == HTML_EL_TEXT_UNIT)
		TtaDeleteTree (prevGroup, doc);
	      if (group)
		elType = TtaGetElementType (group);
	    }
	  if (group)
	    row = TtaGetFirstChild (group);
	  else
	    row = NULL;
	  }
	else
	  /* no more group */
	  row = NULL;
	if (row)
	  /* we are starting with a new group of rows. Ignore vertical 
	     spanning from previous group */
	  for (i = 0; i < cNumber; i++)
	    colVSpan[i] = 0;
	}
      }
    }

  /* if there are some empty columns at the end, remove them */
  if (deleteLastEmptyColumns && cNumber > 0)
    {
    /* start with the last column of the table */
    colhead = colElement[cNumber - 1];
    while (colhead)
      {
      /* get the previous column head before it is deleted */
      prevColhead = colhead;
      TtaPreviousSibling (&prevColhead);
      /* remove this column if it is empty */
      if (!RemoveColumn (colhead, doc, TRUE, inMath))
	/* this column is not empty and has not been removed. Stop */
	colhead = NULL;
      else
	/* the column was empty and has been removed */
	colhead = prevColhead;     
      }
    }

  /* apply delayed colspan */
  if (cDelayed > 0)
    {
      i = 0;
      while (i < cDelayed)
	{
	  attr = TtaGetAttribute (delayedColExt[i], attrTypeHSpan);
	  if (attr)
	    {
	      span = TtaGetAttributeValue (attr);
	      ChangeColspan (delayedColExt[i], 1, &span, doc);
	      overflow = SetColExt (delayedColExt[i], span, doc, inMath,FALSE);
	      if (overflow > 0)
		/* spanning value is too great. update it */
		TtaSetAttributeValue (attr, span-overflow, delayedColExt[i],
				      doc);
	    }
	  i++;
	}
    }

  TtaFreeMemory (colElement);
  TtaFreeMemory (delayedColExt);
  TtaFreeMemory (colVSpan);
}

/*----------------------------------------------------------------------
   CheckTable      Check a table and create the missing elements.  
  ----------------------------------------------------------------------*/
void CheckTable (Element table, Document doc)
{
  ElementType         elType;
  Element             el, columnHeads, thead, tfoot, firstcolhead,
                      tbody, Tablebody, prevrow,
                      prevEl, nextEl, enclosingTable;
  AttributeType       attrType;
  Attribute           attr;
  ThotBool            previousStructureChecking;
  ThotBool            before, inMath;

  firstcolhead = NULL;
  previousStructureChecking = 0;
  if (table)
    {
      /* what are the children of element table? */
      columnHeads = NULL;
      thead = NULL;
      tfoot = NULL;
      Tablebody = NULL;
      elType = TtaGetElementType (table);
      inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
      el = TtaGetFirstChild (table);
      while (el)
	{
	  elType = TtaGetElementType (el);
	  if ((inMath && elType.ElTypeNum == MathML_EL_MTable_head) ||
	      (!inMath && elType.ElTypeNum == HTML_EL_Table_head))
	    columnHeads = el;
	  else if ((inMath && elType.ElTypeNum == MathML_EL_MTable_body) ||
		   (!inMath && elType.ElTypeNum == HTML_EL_Table_body))
	    {
	      if (Tablebody == NULL)
		Tablebody = el;
	    }
	  else if (!inMath && elType.ElTypeNum == HTML_EL_thead)
	    thead = el;
	  else if (!inMath && elType.ElTypeNum == HTML_EL_tfoot)
	    tfoot = el;
	  TtaNextSibling (&el);
	}

      if (columnHeads != NULL)
	/* this table has already been checked */
	return;

      /* if this table is within another table and if it has no border
	 attribute, create an attribute border=0 to avoid inheritance
	 of the the border attribute from the enclosing table */
      elType = TtaGetElementType (table);
      enclosingTable = TtaGetTypedAncestor (table, elType);
      if (!inMath && enclosingTable)
	/* there is an enclosing table */
	{
	  attrType.AttrSSchema = elType.ElSSchema;
	  attrType.AttrTypeNum = HTML_ATTR_Border;
	  if (TtaGetAttribute (enclosingTable, attrType) != NULL)
	    /* the enclosing table has a Border attribute */
	    if (TtaGetAttribute (table, attrType) == NULL)
	      /* the current table has no Border attribute */
	      {
		attr = TtaNewAttribute (attrType);
		TtaAttachAttribute (table, attr, doc);
		TtaSetAttributeValue (attr, 0, table, doc);
	      }
	}

      /* disable document structure checking */
      previousStructureChecking = TtaGetStructureChecking (doc);
      TtaSetStructureChecking (FALSE, doc);

      /* create a Table_head element with a first Column_head */
      elType = TtaGetElementType (table);
      if (inMath)
	elType.ElTypeNum = MathML_EL_MTable_head;
      else
	elType.ElTypeNum = HTML_EL_Table_head;
      columnHeads = TtaNewTree (doc, elType, "");
      if (columnHeads)
	{
	  firstcolhead = TtaGetFirstChild (columnHeads);
	  el = TtaGetFirstChild (table);
	  if (el == NULL)
	    TtaInsertFirstChild (&columnHeads, table, doc);
	  else
	    {
	      /* skip elements Comment and Invalid_element and insert the new
	         element Table_head, after the element caption if it is
		 present or as the first child if there is no caption */
	      while (el)
		{
		  elType = TtaGetElementType (el);
		  if (elType.ElTypeNum == HTML_EL_Invalid_element ||
		      elType.ElTypeNum == HTML_EL_Comment_ ||
		      elType.ElTypeNum == HTML_EL_XMLPI)
		    TtaNextSibling (&el);
		  else
		    {
		      before = (inMath || elType.ElTypeNum != HTML_EL_CAPTION);
		      TtaInsertSibling (columnHeads, el, before, doc);
		      el = NULL;
		    }
		}
	    }

	  if (Tablebody == NULL)
	    {
	      /* There is no Table_body element. Create a Table_body element */
	      if (inMath)
		elType.ElTypeNum = MathML_EL_MTable_body;
	      else
		elType.ElTypeNum = HTML_EL_Table_body;
	      Tablebody = TtaNewElement (doc, elType);
	      if (Tablebody != NULL)
		{
		  if (thead != NULL)
		    TtaInsertSibling (Tablebody, thead, FALSE, doc);
		  else
		    TtaInsertSibling (Tablebody, columnHeads, FALSE, doc);
		  /* collect all Table_row elements and put them in the new
		     Table_body */
		  tbody = NULL;
		  el = Tablebody;
		  TtaNextSibling (&el);
		  prevrow = NULL;
		  prevEl = NULL;
		  attrType.AttrSSchema = elType.ElSSchema;
		  while (el != NULL)
		    {
		      elType = TtaGetElementType (el);
		      nextEl = el;
		      TtaNextSibling (&nextEl);
		      if ((inMath && elType.ElTypeNum == MathML_EL_TableRow) ||
			  (!inMath && elType.ElTypeNum == HTML_EL_Table_row))
			{
			  TtaRemoveTree (el, doc);
			  if (prevrow == NULL)
			    {
			      /* create a tbody element */
			      elType.ElTypeNum = HTML_EL_tbody;
			      tbody = TtaNewElement (doc, elType);
			      if (prevEl == NULL)
				TtaInsertFirstChild (&tbody, Tablebody, doc);
			      else
				TtaInsertSibling (tbody, prevEl, FALSE, doc);
			      TtaInsertFirstChild (&el, tbody, doc);
			    }
			  else
			    TtaInsertSibling (el, prevEl, FALSE, doc);
			  prevrow = el;
			  prevEl = el;
			}
		      else
			{
			  if (!inMath && elType.ElTypeNum == HTML_EL_tbody)
			    {
			      if (prevrow != NULL)
				prevEl = TtaGetParent (prevrow);
			      prevrow = NULL;
			    }
			  TtaRemoveTree (el, doc);
			  if (prevEl == NULL)
			    TtaInsertFirstChild (&el, Tablebody, doc);
			  else
			    TtaInsertSibling (el, prevEl, FALSE, doc);
			  prevEl = el;
			}
		      el = nextEl;
		    }
		}
	    }

	  /* if there is a tfoot element, put it after the Tablebody element */
          if (tfoot && Tablebody)
	    {
	      TtaRemoveTree (tfoot, doc);
	      TtaInsertSibling (tfoot, Tablebody, FALSE, doc);
	    }
	  /* associate each cell with a column */
	  CheckAllRows (table, doc, FALSE, FALSE);
	}
    }
  /* resume document structure checking */
  TtaSetStructureChecking (previousStructureChecking, doc);
}

/*----------------------------------------------------------------------
   SpanningCellForRow
   returns the cell in the column represented by colhead that spans the row
   element. Return NULL if there is no spanning cell in this column for
   that row.
   If a spanning cell is found, parameter colspan returns its colspan value.
   If update is TRUE, the spanning of the cell is increased (if we are adding
   a new row) or decreased (when removing a row).
  ----------------------------------------------------------------------*/
static Element SpanningCellForRow (Element row, Element colhead,
				   Document doc, ThotBool inMath,
				   ThotBool update, ThotBool addRow,
				   int *colspan)
{
  Element             cell, currentRow, lastRow;
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrType;
  int                 rowspan, pos;
  ThotBool            lastRemoved, newLastRow;

  *colspan = 1;
  if (row == NULL)
    return NULL;
  elType = TtaGetElementType (row);

  /* look at the rows before the row of interest and find the first row
     that contains a cell for the column of interest */
  pos = 0;
  cell = NULL;
  currentRow = row;
  do
    {
      currentRow = GetSiblingRow (currentRow, TRUE, inMath);
      if (currentRow)
	{
	  cell = GetCellFromColumnHead (currentRow, colhead, inMath);
	  pos++;
	}
    }
  while (!cell && currentRow);

  if (cell)
    /* we have found a cell in a row above (currentRow) */
    {
      /* check the rowspan attribute of the cell */
      attrType.AttrSSchema = elType.ElSSchema;
      if (inMath)
	attrType.AttrTypeNum = MathML_ATTR_rowspan_;
      else
	attrType.AttrTypeNum = HTML_ATTR_rowspan_;
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
	/* this cell has a rowspan attribute */
	{
	  rowspan = TtaGetAttributeValue (attr);
	  if (rowspan == 0 || rowspan - pos > 0)
	    /* this cell spans the row of interest */
	    /* rowspan = 0 means that the cell spans to the end of the
	       current rows group */
	    {
	    if (update)
              {
	      lastRemoved = FALSE;
              newLastRow = FALSE;
	      if (rowspan == 0)
		{
		  if (!GetSiblingRow (row, FALSE, inMath))
		    /* the cell is spanning to the last row and we are
		       changing the last row */
		    {
		      if (addRow)
			newLastRow = TRUE;
		      else
			lastRemoved = TRUE;
		    }
		} 
	      else
		/* update the spanning */
		if (addRow)
		  rowspan++;
		else
		  {
		    rowspan--;
		    if (rowspan - pos == 0)
		      /* we are removing the last row spanned by the cell */
		      lastRemoved = TRUE;
		  }
	      if (rowspan == 1)
	        /* no spanning any more */
		{
		  /* do not register this deletion of attribute rowspan in the
		     undo queue: undo, when undoing a row creation, would send
		     the event for the attribute before the row is actually
		     removed. RowDeleted called by undo will do the job */
		  if (!addRow)
		    TtaRegisterAttributeDelete (attr, cell, doc);
		  TtaRemoveAttribute (cell, attr, doc);
		  if (inMath)
		    attrType.AttrTypeNum = MathML_ATTR_MRowExt;
		  else
		    attrType.AttrTypeNum = HTML_ATTR_RowExt;
		  attr = TtaGetAttribute (cell, attrType);
		  if (attr)
		    TtaRemoveAttribute (cell, attr, doc);
		  lastRemoved = FALSE;
		}
	      else if (rowspan != 0)
		{
		  /* do not register this change of attribute rowspan in the
		     undo queue: undo, when undoing a row creation, would send
		     the event for the attribute before the row is actually
		     removed. RowDeleted called by undo will do the job */
		  if (!addRow)
		    TtaRegisterAttributeReplace (attr, cell, doc);
		  TtaSetAttributeValue (attr, rowspan, cell, doc);
		}
	      lastRow = NULL;
	      if (newLastRow)
		lastRow = row;
	      if (lastRemoved)
		lastRow = GetSiblingRow (row, TRUE, inMath);
	      if (lastRow)
		/* update the RowExt attribute */
		{
		  if (inMath)
		    attrType.AttrTypeNum = MathML_ATTR_MRowExt;
		  else
		    attrType.AttrTypeNum = HTML_ATTR_RowExt;
		  attr = TtaGetAttribute (cell, attrType);
		  if (attr)
		    {
		      if (currentRow == lastRow)
			{
			  TtaRemoveAttribute (cell, attr, doc);
			  attr = NULL;
			}
		    }
		  else if (currentRow != lastRow)
		    {
		      attr = TtaNewAttribute (attrType);
		      if (attr != NULL)
			TtaAttachAttribute (cell, attr, doc);
		    }
		  if (attr)
		    TtaSetAttributeReference (attr, cell, doc, lastRow);
		}
	      /* we have finished updating */
	      }
	    /* get the colspan value of the rowspanning cell */
	    if (inMath)
	      attrType.AttrTypeNum = MathML_ATTR_columnspan;
	    else
	      attrType.AttrTypeNum = HTML_ATTR_colspan_;
	    attr = TtaGetAttribute (cell, attrType);
	    if (attr)
	      /* this cell has an attribute colspan */
	      *colspan = TtaGetAttributeValue (attr);
	    if (*colspan < 0)
	      *colspan = 1;
	    }
	  else
	    cell = NULL;
	}
      else
	cell = NULL;
    }
  return (cell);
}

/*----------------------------------------------------------------------
  NewCell  a new cell has been created or pasted in a HTML table.
  Link it to its column head.
  If generateColumn is TRUE, the new cell generates a new column head.
  If generateEmptyCells is TRUE, generate empty cells for the same column
  in other rows.
  ----------------------------------------------------------------------*/
void NewCell (Element cell, Document doc, ThotBool generateColumn,
	      ThotBool generateEmptyCells, ThotBool check)
{
  Element             newcell, row, colhead, lastColhead, chead, pcell,
                      spannedCell;
  ElementType         elType;
  AttributeType       attrTypeCspan, attrTypeRspan, attrTypeRefC;
  Attribute           attr;
  DisplayMode         dispMode;
  int                 span, i, col;
  ThotBool            before, inMath;

  dispMode = TtaGetDisplayMode (doc);
  if (dispMode == DisplayImmediately)
    TtaSetDisplayMode (doc, DeferredDisplay);
  lastColhead = NULL;
  elType = TtaGetElementType (cell);
  attrTypeCspan.AttrSSchema = elType.ElSSchema;
  attrTypeRspan.AttrSSchema = elType.ElSSchema;
  attrTypeRefC.AttrSSchema = elType.ElSSchema;
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  if (!inMath && elType.ElTypeNum == HTML_EL_Table_cell)
    /* change the cell into a Data_cell */
    {
      elType.ElTypeNum = HTML_EL_Data_cell;
      newcell = TtaNewTree (doc, elType, "");
      TtaInsertFirstChild (&newcell, cell, doc);
      cell = newcell;
    }
  else
    newcell = cell;
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_TableRow;
      attrTypeRefC.AttrTypeNum = MathML_ATTR_MRef_column;
      attrTypeCspan.AttrTypeNum = MathML_ATTR_columnspan;
      attrTypeRspan.AttrTypeNum = MathML_ATTR_rowspan_;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Table_row;
      attrTypeRefC.AttrTypeNum = HTML_ATTR_Ref_column;
      attrTypeCspan.AttrTypeNum = HTML_ATTR_colspan_;
      attrTypeRspan.AttrTypeNum = HTML_ATTR_rowspan_;
    }
  /* get the enclosing row element */
  row = TtaGetTypedAncestor (cell, elType);
  /* locate the previous or the next column head */
  colhead = NULL;
  cell = GetSiblingCell (newcell, TRUE, inMath);
  if (cell == NULL)
    /* no cell before the new cell. Try after the new cell */
    {
      cell = GetSiblingCell (newcell, FALSE, inMath);
      before = TRUE;
      if (cell)
	/* there is a following cell. Get its column head */
	{
	  attr = TtaGetAttribute (cell, attrTypeRefC);
	  if (attr)
	    {
	      TtaGiveReferenceAttributeValue (attr, &colhead);
	      if (colhead)
		/* the column head is found */
		{
		  /* if there are some cells spanning from above rows,
		     skip them. Check previous column heads. */
		  chead = colhead;
		  TtaPreviousSibling (&chead);
		  col = 1;
		  while (chead)
		    {
		      pcell = SpanningCellForRow (row, chead, doc, inMath,
						  FALSE, FALSE, &span);
		      if (pcell)
			/* there is a cell linked to that column head that
			   spans our row */
			{
			  if (span == col)
			    /* its colspan make it touch our cell */
			    colhead = chead;
			  else if (span < col)
			    /* it leaves room for the new cell. stop */
			    chead = NULL;
			}
		      if (chead)
			{
			  TtaPreviousSibling (&chead);
			  col++;
			}
		    }

		  attr = TtaGetAttribute (newcell, attrTypeCspan);
		  if (attr)
		    /* the new cell has an attribute colspan */
		    {
		      span = TtaGetAttributeValue (attr);
		      /* ignore span if zero: there is a cell after this
			 newcell with an "infinite" span. Strange */
		      if (span > 1)
			/* skip the previous column heads according to the
			   span of the new cell */
			{
			  for (i = 1; i < span && colhead; i++)
			    {
			      lastColhead = colhead;
			      TtaPreviousSibling (&colhead);
			    }
			  if (!colhead)
			    colhead = lastColhead;
			}
		    }
		}
	    }
	}
    }
  else
    /* there is a cell before the new cell */
    {
      before = FALSE;
      /* get its column head */
      attr = TtaGetAttribute (cell, attrTypeRefC);
      if (attr != NULL)
	{
	  TtaGiveReferenceAttributeValue (attr, &colhead);
	  if (colhead)
	    {
	      /*if this cell has an attribute colspan, skip some column heads*/
	      attr = TtaGetAttribute (cell, attrTypeCspan);
	      if (attr)
		{
		  span = TtaGetAttributeValue (attr);
		  if (span == 0)
		    /* colspan is zero: the new cell would be after this
		       supposed infinite cell */
		    {
		      span = 1;
		      do
			{
			  lastColhead = colhead;
			  TtaNextSibling (&colhead);
			  if (colhead)
			    span++;
			}
		      while (colhead);
		      colhead = lastColhead;
		      /* Change colspan to its actual value */
		      TtaRegisterAttributeReplace (attr, cell, doc);
		      TtaSetAttributeValue (attr, span, cell, doc);
		    }
		  else
		    {
		      for (i = 1; i < span && colhead; i++)
			{
			  lastColhead = colhead;
			  TtaNextSibling (&colhead);
			}
		      if (!colhead)
			colhead = lastColhead;
		    }
		}
	      /* if it's the creation of a new column, create the new
                 column here. Otherwise take the existing cells into
	         account */
	      if (!generateColumn)
	        /* if there are some cells spanning from above rows,
		   skip them */
	        do
		  {
		  chead = colhead;
		  TtaNextSibling (&chead);
		  if (chead)
		    pcell = SpanningCellForRow (row, chead, doc, inMath, FALSE,
						FALSE, &span);
		  else
		    pcell = NULL;
		  if (pcell)
		    {
		      colhead = chead;
		      /* if this cell has an attribute colspan, skip some
			 column heads */
		      attr = TtaGetAttribute (pcell, attrTypeCspan);
		      if (attr)
			{
			  span = TtaGetAttributeValue (attr);
			  if (span > 1)
			    {
			      for (i = 1; i < span && colhead; i++)
				{
				  lastColhead = colhead;
				  TtaNextSibling (&colhead);
				}
			      if (!colhead)
				colhead = lastColhead;
			    }
			}
		    }
		  }
	        while (pcell);
	    }
	}
    }

  if (colhead)
    {
      if (generateColumn)
	/* generate the new column */
	colhead = NewColumnHead (colhead, before, FALSE, row, doc, inMath,
				 generateEmptyCells);
      else if (before)
	/* select the previous column */
	TtaPreviousSibling (&colhead);
      else
	/* select the next column */
	TtaNextSibling (&colhead);
      /* next pasted cells with info = 3 should be linked to this column */
      CurrentColumn = colhead;
      pcell = NULL;
      if (check)
	{
	  /* is a cell already linked to this column head? */
	  attr = TtaGetAttribute (newcell, attrTypeRefC);
	  if (attr)
	    TtaRemoveAttribute (newcell, attr, doc);
	  pcell = GetCellFromColumnHead (row, colhead, inMath);
	  if (pcell)
	    {
	      attr = TtaGetAttribute (pcell, attrTypeRefC);
	      if (attr)
		TtaRemoveAttribute (pcell, attr, doc);
	    }
	}
      /* link the new cell to the new colhead */
      LinkCellToColumnHead (newcell, colhead, doc, inMath);
      if (check)
	{
	  if (pcell)
	    /* link the cell that was there before to its right column */
	    NewCell (pcell, doc, FALSE, FALSE, TRUE);
	  /* do the cell span vertically? */
	  attr = TtaGetAttribute (newcell, attrTypeRspan);
	  if (attr)
	    {
	      span = TtaGetAttributeValue (attr);
	      while ((span > 1 || span == 0) && row)
		{
		  row = GetSiblingRow (row, FALSE, inMath);
		  if (row)
		    {
		      spannedCell = GetCellFromColumnHead (row, colhead, inMath);
		      if (spannedCell)
			NewCell (spannedCell, doc, FALSE, FALSE, TRUE);
		      if (span > 1)
			span--;
		    }
		} 
	    } 
	}
    }
   TtaSetDisplayMode (doc, dispMode);
}

/*----------------------------------------------------------------------
   CellCreated
   a new cell has been created in a table
  ----------------------------------------------------------------------*/
void CellCreated (NotifyElement * event)
{
  Element             cell, row;
  Document            doc;

  if (event->info == 1)
    /* the creation is already done by undo */
    return;
  cell = event->element;
  doc = event->document;
  row = TtaGetParent (cell);
  /* the creation of the cell must be registered after
     the created colhead */
  TtaCancelLastRegisteredOperation (doc);
  NewCell (cell, doc, TRUE, TRUE, FALSE);
  TtaRegisterElementCreate (cell, doc);
  /* change the value of "info" in the latest cell
     deletion recorded in the Undo queue. The goal is to
     allow procedure CellPasted to regenerate only one
     column head when undoing the operation */
  TtaChangeInfoLastRegisteredElem (doc, 3);
}

/*----------------------------------------------------------------------
   CellPasted                                              
  ----------------------------------------------------------------------*/
void CellPasted (NotifyElement * event)
{
  Element             cell, row;
  ElementType         elType;
  Document            doc;
  AttributeType       rowspanType;
  Attribute           attr;
  int                 span, overflow;
  ThotBool            inMath;

  cell = event->element;
  doc = event->document;
  elType = TtaGetElementType (cell);
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  row = TtaGetParent (cell);
  /* regenerate the corresponding ColumnHead except if it's called by
     undo for reinserting the cells deleted by a "Delete Column"
     command (only the first reinserted cell has to create a ColumnHead)
     See function RemoveColumn above */
  if (event->info == 3)
    {
      /* undoing the deletion of any other cell in a "delete column" command,
	 or pasting any other cell.
	 Link the restored cell with the corresponding ColumnHead */
      elType = TtaGetElementType (cell);
      inMath = TtaSameSSchemas (elType.ElSSchema,
				TtaGetSSchema ("MathML", doc));
      LinkCellToColumnHead (cell, CurrentColumn, doc, inMath);
    }
  else
    /* undoing/redoing. Link the cell with ColumnHead elements, but do not
       generate empty cells in other rows */
    NewCell (cell, doc, FALSE, FALSE, TRUE);

  /* update row extensions */
  rowspanType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    rowspanType.AttrTypeNum = MathML_ATTR_rowspan_;
  else
    rowspanType.AttrTypeNum = HTML_ATTR_rowspan_;
  attr = TtaGetAttribute (cell, rowspanType);
  if (!attr)
    span = 1;
  else
    {
      span = TtaGetAttributeValue (attr);
      if (span < 0)
	span = 1;
    }
  if (span > 1 || span == 0)
    {
      overflow = SetRowExt (cell, span, doc, inMath);
      if (overflow > 0)
	/* spanning value is too high. Update it */
	{
	  span -= overflow;
	  if (span == 1 || span < 0)
	    {
	      if (attr)
		TtaRemoveAttribute (cell, attr, doc);
	    }
	  else if (attr)
	    TtaSetAttributeValue (attr, span, cell, doc);
	}
    }

  HandleColAndRowAlignAttributes (row, doc);
  /* Check attribute NAME or ID in order to make sure that its value */
  /* is unique in the document */
  MakeUniqueName (cell, doc, TRUE, TRUE);
}

/*----------------------------------------------------------------------
   UpdateRowspanForRow
   A new row has been created by the user (if addRow) or will be deleted
   (if not addRow). Take care of the rowspan attribute of the previous rows
   for creating cells in the row if it's a new row,
   or create empty cells in the next rows according of the rowspan attribute
   of the deleted row.
  ----------------------------------------------------------------------*/
static void UpdateRowspanForRow (Element row, Document doc, ThotBool inMath,
				 ThotBool addRow, ThotBool updateRow)
{
  Element             colhead, cell, prev, table;
  ElementType         elType;
  int                 colspan, i;

  elType = TtaGetElementType (row);
  if (inMath)
    elType.ElTypeNum = MathML_EL_MTABLE;
  else
    elType.ElTypeNum = HTML_EL_Table_;
  table = TtaGetTypedAncestor (row, elType);
  /* get the first column */
  if (inMath)
    elType.ElTypeNum = MathML_EL_MColumn_head;
  else
    elType.ElTypeNum = HTML_EL_Column_head;
  /* get the first column head */
  colhead = TtaSearchTypedElement (elType, SearchInTree, table);
  /* check the cells for all columns */
  cell = NULL;
  while (colhead)
    {
      /* is there a cell in a row above that spans the current row? */
      prev = SpanningCellForRow (row, colhead, doc, inMath, TRUE, addRow,
				 &colspan);
      if (updateRow)
	{
	  if (addRow && !prev)
	    /* we are creating a new row and no cell from a row above is
	       covering the current cell position. Create an empty cell at
	       that position */
	    cell = AddEmptyCellInRow (row, colhead, cell, FALSE, doc, inMath,
				      FALSE, FALSE);
	  else if (!addRow)
	    /* we are deleting a row */
	    {
	      if (prev)
		/* a cell from a row above is covering the current cell
		   position. Create an empty cell to allow this row to be
		   pasted correctly later */
		{
		  if (colspan > 0)
		    for (i = 1; i <= colspan; i++)
		      cell = AddEmptyCellInRow (row, colhead, cell, FALSE, doc,
						inMath, FALSE, TRUE);
		}
	      else
		cell = GetCellFromColumnHead (row, colhead, inMath);
	    }
	}
      if (colspan == 0)
	/* the spanning cell extends to the end of the table. No need to
	   look further */
	colhead = NULL;
      else
	while (colspan >= 1 && colhead)
	  {
	    TtaNextSibling (&colhead);
	    colspan--;
	  }
    }
}

/*----------------------------------------------------------------------
   DeleteRow
   A table row will be deleted by the user
  ----------------------------------------------------------------------*/
ThotBool DeleteRow (NotifyElement *event)
{
  Element             row, cell;
  ElementType         elType;
  Attribute           attr;
  AttributeType       rowspanType;
  Document            doc;
  int                 rowspan, newRowspan;
  ThotBool            inMath;

  row = event->element;
  doc = event->document;
  elType = TtaGetElementType (row);
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  /* decrease the value of the rowspan attribute of cells from rows above
     that span the deleted row */
  UpdateRowspanForRow (row, doc, inMath, FALSE, TRUE);
  /* create empty cells in the following rows, where cells of the deleted
     row span the following rows */
  rowspanType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    rowspanType.AttrTypeNum = MathML_ATTR_rowspan_;
  else
    rowspanType.AttrTypeNum = HTML_ATTR_rowspan_;
  cell = GetFirstCellOfRow (row, inMath);
  while (cell)
    {
      /* check the rowspan attribute of that cell */
      attr = TtaGetAttribute (cell, rowspanType);
      if (attr)
	/* this cell has an attribute rowspan */
	{
	  rowspan = TtaGetAttributeValue (attr);
	  if (rowspan < 0)
	    rowspan = 1;
	}
      else
	rowspan = 1;
      if (rowspan > 1 || rowspan == 0)
	{
	  newRowspan = 1;
	  ChangeRowspan (cell, rowspan, &newRowspan, doc);
	  TtaRegisterAttributeDelete (attr, cell, doc);
	  TtaRemoveAttribute (cell, attr, doc);
	}
      cell = GetSiblingCell (cell, FALSE, inMath);
    }
  return FALSE;		/* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
   RowDeleted
   A table row has been deleted by the user
  ----------------------------------------------------------------------*/
void RowDeleted (NotifyElement *event)
{
  Element             rowgroup;
  Document            doc;

  doc = event->document;
  rowgroup = event->element;
  if (rowgroup == NULL)
    /* the rowgroup doesn't exist */
    return;
  HandleColAndRowAlignAttributes (rowgroup, doc);
}

/*----------------------------------------------------------------------
  ClearColumn
  A column will be deleted. Take care of the colspan attribute of the
  cells in this column.
  Reduce the colspan attribute of the cells of the previous columns that
  span this column.
  ----------------------------------------------------------------------*/
static void ClearColumn (Element colhead, Document doc)
{
  Element             cell, prevCell, row, nextColhead, prev, table;
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrTypeC, attrTypeR;
  int                 rowspan, colspan, rs, cs;
  ThotBool            span, inMath;

  elType = TtaGetElementType (colhead);
  elType.ElTypeNum = HTML_EL_Table_;
  table = TtaGetTypedAncestor (colhead, elType);
  attrTypeC.AttrSSchema = elType.ElSSchema;
  attrTypeR.AttrSSchema = elType.ElSSchema;
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema("MathML",doc));
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_TableRow;
      attrTypeC.AttrTypeNum = MathML_ATTR_columnspan;
      attrTypeR.AttrTypeNum = MathML_ATTR_rowspan_;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Table_row;
      attrTypeC.AttrTypeNum = HTML_ATTR_colspan_;
      attrTypeR.AttrTypeNum = HTML_ATTR_rowspan_;
    }
  nextColhead = colhead;
  TtaNextSibling (&nextColhead);

  /* get the first row in the table */
  row = TtaSearchTypedElement (elType, SearchInTree, table);
  /* check all cells of the column */
  while (row)
    {
      /* check if the cell has span values */
      rowspan = 1;
      colspan = 1;
      cell = GetCellFromColumnHead (row, colhead, inMath);
      if (cell)
	{
	  attr = TtaGetAttribute (cell, attrTypeC);
	  if (attr)
	    /* there is a colspan attribute */
	    colspan = TtaGetAttributeValue (attr);
	  if (colspan > 1 || colspan == 0)
	    {
	      cs = 1;
	      ChangeColspan (cell, colspan, &cs, doc);
	      TtaRegisterAttributeDelete (attr, cell, doc);
	      TtaRemoveAttribute (cell, attr, doc);
	    }
	  attr = TtaGetAttribute (cell, attrTypeR);
	  if (attr)
	    /* there is a rowspan */
	    {
	      rowspan = TtaGetAttributeValue (attr);
	      if (rowspan < 0)
		rowspan = 1;
	    }
	}
      else
	/* no cell for the column in that row. Get the previous cell in
	   the same row and update its colspan attribute. */
	prevCell = GetCloseCell (row, colhead, doc, TRUE, FALSE, inMath,
				 &span, &rs, nextColhead==NULL);
      prev = row;
      if (rowspan == 0)
	rowspan = THOT_MAXINT;
      while (rowspan >= 1 && row)
	{
	  row = GetSiblingRow (row, FALSE, inMath);
	  if (row)
	    {
	      if (rowspan < THOT_MAXINT)
		rowspan--;
	      if (!cell && rowspan >= 1)
		prevCell = GetCloseCell (row, colhead, doc, TRUE, FALSE,
					 inMath, &span, &rs, FALSE);
	    }
	}
      if (row == NULL)
	{
	  prev = TtaGetParent (prev);
	  while (prev && row == NULL)
	    {
	      TtaNextSibling (&prev);
	      row = TtaSearchTypedElementInTree (elType, SearchForward, prev,
						 prev);
	    }
	}
    }
}

/*----------------------------------------------------------------------
  DeleteColumn
  A column will be deleted by the user.
  ----------------------------------------------------------------------*/
ThotBool DeleteColumn (NotifyElement * event)
{
  ClearColumn (event->element, event->document);
  return FALSE;		/* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
   ColumnDeleted
   A column in a MathML table has been deleted
  ----------------------------------------------------------------------*/
void ColumnDeleted (NotifyElement *event)
{
  Element             colhead, table;
  ElementType         elType;

  colhead = event->element;
  elType = TtaGetElementType (colhead);
  elType.ElTypeNum = MathML_EL_MTABLE;
  table = TtaGetTypedAncestor (colhead, elType);
  if (table)
    HandleColAndRowAlignAttributes (table, event->document);
}

/*----------------------------------------------------------------------
  ColumnPasted
  This function is called when pasting a column or undoing the creation of a
  column in a table.
  ----------------------------------------------------------------------*/
void ColumnPasted (NotifyElement * event)
{
  Element         prevColhead, row, prev, table, prevCell;
  ElementType     elType;
  Document        doc;
  int             rowspan;
  ThotBool        inMath, span;

  CurrentColumn = event->element;
  prevColhead = CurrentColumn;
  TtaPreviousSibling (&prevColhead);
  if (prevColhead)
    {
      doc = event->document;
      elType = TtaGetElementType (CurrentColumn);
      elType.ElTypeNum = HTML_EL_Table_;
      table = TtaGetTypedAncestor (CurrentColumn, elType);
      inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema("MathML",doc));
      if (inMath)
	elType.ElTypeNum = MathML_EL_TableRow;
      else
	elType.ElTypeNum = HTML_EL_Table_row;
      /* get the first row in the table */
      row = TtaSearchTypedElement (elType, SearchInTree, table);
      /* check all rows of the table */
      while (row)
	{
	  prevCell = GetCloseCell (row, prevColhead, doc, TRUE, TRUE, inMath,
				   &span, &rowspan, FALSE);
	  prev = row;
	  if (rowspan == 0)
	    rowspan = THOT_MAXINT;
	  while (rowspan >= 1 && row)
	    {
	      row = GetSiblingRow (row, FALSE, inMath);
	      if (row && rowspan < THOT_MAXINT)
		rowspan--;
	    }
	  if (!row)
	    /* last row of the current block. Get the first row in the next
	       block, if any */
	    {
	      prev = TtaGetParent (prev);
	      while (prev && row == NULL)
		{
		  TtaNextSibling (&prev);
		  row = TtaSearchTypedElementInTree (elType, SearchForward,
						     prev, prev);
		}
	    }
	}
    }
}

/*----------------------------------------------------------------------
  TableCreated                                             
  ----------------------------------------------------------------------*/
void TableCreated (NotifyElement * event)
{
  if (CurrentTable != event->element)
    {
      CurrentTable = event->element;
    }
}

/*----------------------------------------------------------------------
  TablePasted                                             
  ----------------------------------------------------------------------*/
void TablePasted (NotifyElement * event)
{
  Element             el;
  ElementType         elType;
  AttributeType       attrType;
  Attribute           attr;
  Document            doc;
  char                *stylebuff;
  int                 border, len;

  el = event->element;
  doc = event->document;
  elType = TtaGetElementType (el);
  attrType.AttrSSchema = elType.ElSSchema;
  attrType.AttrTypeNum = HTML_ATTR_Border;
  if (el == CurrentTable)
    /* table created */
    border = 1;
  else
    border = 0;
  if (TtaGetDocumentProfile(doc) == L_Basic)
    {
      /* remove the border attribute within basic XHTML documents */
      attr = TtaGetAttribute (el, attrType);
      if (attr)
	{
	  border = TtaGetAttributeValue (attr);
	  TtaRemoveAttribute (el, attr, doc);
	}
      if (border)
	{
	  /* generate a border style */
	  attrType.AttrTypeNum = HTML_ATTR_Style_;
	  attr = TtaNewAttribute (attrType);
	  if (attr == NULL)
	    {
	      TtaAttachAttribute (el, attr, doc);
	      len = 0;
	      stylebuff = (char *)TtaGetMemory (50);
	      stylebuff[0] = EOS;
	    }
	  else
	    {
	      len = TtaGetTextAttributeLength (attr);
	      stylebuff = (char *)TtaGetMemory (len + 50);
	      TtaGiveTextAttributeValue (attr, stylebuff, &len);
	    }
	  sprintf (&stylebuff[len], "border: solid %dpx", border);
	  TtaSetAttributeText (attr, stylebuff, el, doc);
	  TtaFreeMemory (stylebuff);
	}
    }
  else if (border)
    {
      /* add a default border */
      attr = TtaGetAttribute (el, attrType);
      if (attr == NULL)
	{
	  attr = TtaNewAttribute (attrType);
	  TtaAttachAttribute (el, attr, doc);
	}
      TtaSetAttributeValue (attr, 1, el, doc);
    }

  if (el == CurrentTable)
    {
      CheckTable (el, doc);
      CurrentTable = NULL;
    }
  else
    /* associate each cell with a column */
    CheckAllRows (el, doc, FALSE, FALSE);
}

/*----------------------------------------------------------------------
  CopyRow:
  A table row has been copied. Generate empty cells in the copy where the
  row is crossed by spanning cells from the rows above.
  This function is called only by command Copy, not by command Cut.
  ----------------------------------------------------------------------*/
void CopyRow (Element copyRow, Element origRow, Document doc)
{
  Element       prevCopyCell, copyCell, origCell, colhead, table;
  ElementType   elType, cellType;
  Attribute     attr;
  AttributeType attrType;
  int           colspan;
  ThotBool      inMath;

  elType = TtaGetElementType (origRow);
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  attrType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_MTABLE;
      attrType.AttrTypeNum = MathML_ATTR_columnspan;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Table_;
      attrType.AttrTypeNum = HTML_ATTR_colspan_;
    }
  /* get the table to which the original row belongs */
  table = TtaGetTypedAncestor (origRow, elType);
  /* get the first column head of this table */
  if (inMath)
    elType.ElTypeNum = MathML_EL_MColumn_head;
  else
    elType.ElTypeNum = HTML_EL_Column_head;
  colhead = TtaSearchTypedElement (elType, SearchInTree, table);
  /* get prepared for the generation of empty cells */
  cellType.ElSSchema = elType.ElSSchema;
  if (inMath)
    cellType.ElTypeNum = MathML_EL_MTD;
  else
    cellType.ElTypeNum = HTML_EL_Data_cell;

  /* check all column heads of the original table */
  prevCopyCell = NULL;
  while (colhead)
    {
      colspan = 1;
      /* is there a cell linked to that column head in the original row? */
      origCell = GetCellFromColumnHead (origRow, colhead, inMath);
      if (!origCell)
	/* no cell at that position in the original table */
	{
	  /* create an empty cell at the same position in the copy */
	  copyCell = TtaNewTree (doc, cellType, "");
	  if (copyCell)
	    {
	      if (prevCopyCell)
		TtaInsertSibling (copyCell, prevCopyCell, FALSE, doc);
	      else
		TtaInsertFirstChild (&copyCell, copyRow, doc);
	      prevCopyCell = copyCell;
	    }
	}
      else
	/* there is a cell at that position in the original row */
	{
	  if (prevCopyCell)
	    /* we have already processed some cells in the copy row.
	       skip one */
	    prevCopyCell = GetSiblingCell (prevCopyCell, FALSE, inMath);
	  else
	    /* we have not processed any cell in the copy row yet */
	    /* get the first cell in the copy row */
	    {
	      prevCopyCell = GetFirstCellOfRow (copyRow, inMath);
	      if (prevCopyCell && inMath)
		{
		  elType = TtaGetElementType (prevCopyCell);
		  if (elType.ElTypeNum == MathML_EL_RowLabel)
		    /* we are copying a mlabeledtr element. Skip the first
		       cell in the row: it's the label */
		    prevCopyCell = GetSiblingCell(prevCopyCell, FALSE, inMath);
		}
	    }
	  /* get the value of the colspan attribute for the current cell */
	  attr = TtaGetAttribute (origCell, attrType);
	  if (attr)
	    /* there is a colspan attribute */
	    {
	      colspan = TtaGetAttributeValue (attr);
	      if (colspan < 0)
		colspan = 1;
	    }
	}
      if (colspan == 0)
	/* this cell spans all the rest of the row. Stop */
	colhead = NULL;
      else
	/* skip a number of column heads equal to the spanning of the cell */
	while (colspan >= 1 && colhead)
	  {
	    TtaNextSibling (&colhead);
	    colspan--;
	  }
    }
}

/*----------------------------------------------------------------------
  CopyCell:
  A cell has been copied while copying a row or a column.
  Remove the rowspan and RowExt attributes (if copying a row)
  or the colspan and ColExt attributes (if copying a column).
  ----------------------------------------------------------------------*/
void CopyCell (Element cell, Document doc, ThotBool inRow)
{
  ElementType         elType;
  Attribute           attr;
  AttributeType       attrType, attrTypeR;
  ThotBool            inMath;
  
  elType = TtaGetElementType (cell);
  attrType.AttrSSchema = elType.ElSSchema;
  attrTypeR.AttrSSchema = elType.ElSSchema;
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  if (inRow)
    {
      if (inMath)
	{
	  attrType.AttrTypeNum = MathML_ATTR_rowspan_;
	  attrTypeR.AttrTypeNum = MathML_ATTR_MRowExt;
	}
      else
	{
	  attrType.AttrTypeNum = HTML_ATTR_rowspan_;
	  attrTypeR.AttrTypeNum = HTML_ATTR_RowExt;
	}
      /* remove the rowspan attribute of the copy */
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
	TtaRemoveAttribute (cell, attr, doc);
      /* remove the refext attribute of the copy */
      attr = TtaGetAttribute (cell, attrTypeR);
      if (attr)
	TtaRemoveAttribute (cell, attr, doc);
    }
  else
    {
      if (inMath)
	{
	  attrType.AttrTypeNum = MathML_ATTR_columnspan;
	  attrTypeR.AttrTypeNum = MathML_ATTR_MColExt;
	}
      else
	{
	  attrType.AttrTypeNum = HTML_ATTR_colspan_;
	  attrTypeR.AttrTypeNum = HTML_ATTR_ColExt;
	}
      /* remove the colspan attribute of the copy */
      attr = TtaGetAttribute (cell, attrType);
      if (attr)
	TtaRemoveAttribute (cell, attr, doc);
      /* remove the refext attribute of the copy */
      attr = TtaGetAttribute (cell, attrTypeR);
      if (attr)
	TtaRemoveAttribute (cell, attr, doc);
    }
}

/*----------------------------------------------------------------------
  NextCellInColumn:
  Return the cell in column colHead and in the row that follows the
  given row. If there is no cell at that position, create an empty
  cell and return it. In that case the value returned for fake is TRUE.
  If a cell exists, the value returned for fake is FALSE.
  If row is NULL, get the first row of the table and return the cell
  in that row and in the given column (or an empty cell).
  If row is the last row of the table, return cell = NULL and row = NULL.
  ----------------------------------------------------------------------*/
void NextCellInColumn (Element* cell, Element* row, Element colHead,
		       Document doc, ThotBool* fake)
{
  Element             nextCell, table, block, nextBlock, parent;
  ElementType         elType, blockType;
  Attribute           attr;
  AttributeType       attrType;
  int                 rowType;
  ThotBool            inMath;

  nextCell = NULL;
  *fake = FALSE;
  if (colHead)
    {
      elType = TtaGetElementType (colHead);
      inMath = strcmp ((char *)TtaGetSSchemaName (elType.ElSSchema), "MathML") == 0;
      if (*row)
        /* get the row that follows the given row in the same table */
	{
	  /* in MathML table, there are no blocks. All rows are siblings */
	  block = NULL;
	  if (!inMath)
	    /* remember the parent (a block) of the given row */
	    block = TtaGetParent (*row);
          /* get the next row among the siblings */
	  *row = GetSiblingRow (*row, FALSE, inMath);
	  if (*row == NULL && !inMath && block)
	    /* there is no sibling row. let's check the next block (thead,
	       tbody, tfoot) */
	    {
	      /* remember the type of the block of the current row */
	      blockType = TtaGetElementType (block);
	      /* get the sibling block */
	      nextBlock = block;
	      do
		{
		  TtaNextSibling (&nextBlock);
		  if (nextBlock)
		    elType = TtaGetElementType (nextBlock);
		}
	      while (nextBlock && (elType.ElTypeNum != HTML_EL_thead &&
				   elType.ElTypeNum != HTML_EL_tfoot &&
				   elType.ElTypeNum != HTML_EL_tbody &&
				   elType.ElTypeNum != HTML_EL_Table_body));
	      if (!nextBlock && blockType.ElTypeNum == HTML_EL_tbody)
		/* there is no sibling block, but the block was a tbody */
		/* skip the Table_body parent and get the following block */
		{
		  parent = TtaGetParent (block);
		  elType = TtaGetElementType (parent);
		  if (elType.ElTypeNum == HTML_EL_Table_body)
		    {
		      /* get the block (thead or tfoot) that follows the
			 Table_body */
		      nextBlock = parent;
		      do
			{
			  TtaNextSibling (&nextBlock);
			  if (nextBlock)
			    elType = TtaGetElementType (nextBlock);
			}
		      while (nextBlock && (elType.ElTypeNum != HTML_EL_thead &&
					   elType.ElTypeNum != HTML_EL_tfoot));
		    }
		}
	      if (nextBlock && elType.ElTypeNum == HTML_EL_Table_body)
		/* if the block found is a Table_body, get its first tbody
		   child */
		{
		  nextBlock = TtaGetFirstChild (nextBlock);
		  if (nextBlock)
		    elType = TtaGetElementType (nextBlock);
		  while (nextBlock && elType.ElTypeNum != HTML_EL_tbody)
		    {
		      TtaNextSibling (&nextBlock);
		      if (nextBlock)
			elType = TtaGetElementType (nextBlock);
		    }
		}
	      if (nextBlock)
		/* we have found a block. Get the first row in its children */
		{
		  *row = TtaGetFirstChild (nextBlock);
		  if (*row)
		    elType = TtaGetElementType (*row);
		  while (*row && elType.ElTypeNum != HTML_EL_Table_row)
		    {
		      TtaNextSibling (row);
		      if (*row)
			elType = TtaGetElementType (*row);
		    }
		}
	    }
	}
      else
	/* Parameter row is NULL. Get the first row in the table */
	{
	  if (inMath)
	    {
	      elType.ElTypeNum = MathML_EL_MTABLE;
	      rowType = MathML_EL_TableRow;
	    }
	  else
	    {
	      elType.ElTypeNum = HTML_EL_Table_;
	      rowType = HTML_EL_Table_row;
	    }
	  table = TtaGetTypedAncestor (colHead, elType);
	  elType.ElTypeNum = rowType;
	  *row = TtaSearchTypedElement (elType, SearchInTree, table);
	} 
      if (*row)
	/* we have found a row. Get the cell in that row that is linked to
	   the given column head */
	{
	  elType = TtaGetElementType (colHead);
	  nextCell = GetCellFromColumnHead (*row, colHead, inMath);
	  if (!nextCell)
	    /* there is no cell at that position in the table */
	    {
	      *fake = TRUE;
	      if (inMath)
	        elType.ElTypeNum = MathML_EL_MTD;
	      else
		elType.ElTypeNum = HTML_EL_Data_cell;
	      /* generate an empty cell */
	      nextCell = TtaNewTree (doc, elType, "");
	    }
	  else
	    /* there is a cell in the table */
	    {
	      /* if this cell has a rowspan attribute, return the row
		 corresponding to the bottom of the cell */
	      attrType.AttrSSchema = elType.ElSSchema;
	      if (inMath)
		attrType.AttrTypeNum = MathML_ATTR_MRowExt;
	      else
		attrType.AttrTypeNum = HTML_ATTR_RowExt;
	      attr = TtaGetAttribute (nextCell, attrType);
	      if (attr)
		TtaGiveReferenceAttributeValue (attr, row);
	    }
	}
    }
  *cell = nextCell;
}

/*----------------------------------------------------------------------
   TablebodyDeleted                                             
  ----------------------------------------------------------------------*/
void TablebodyDeleted (NotifyElement * event)
{
  Element             sibling, table;
  ElementType	      elType;
  Document            doc;
  ThotBool	      empty;

  if (event->info == 2)
     /* call from the Return key. Don't do anything */
     return;
  doc = event->document;
  table = event->element;
  sibling = TtaGetFirstChild (table);
  empty = TRUE;
  while (sibling != NULL && empty)
    {
      elType = TtaGetElementType (sibling);
      if (elType.ElTypeNum == HTML_EL_CAPTION ||
	  elType.ElTypeNum == HTML_EL_thead ||
	  elType.ElTypeNum == HTML_EL_Table_body ||
	  elType.ElTypeNum == HTML_EL_tfoot)
	if (TtaGetElementVolume (sibling) > 0)
	  empty = FALSE;
      TtaNextSibling (&sibling);
    }
  if (empty)
    {
      if (TtaPrepareUndo (doc))
	  /* register that the table is deleted */
	  TtaRegisterElementDelete (table, doc);
      TtaDeleteTree (table, doc);
    }
}

/*----------------------------------------------------------------------
   RowCreated                                              
  ----------------------------------------------------------------------*/
void RowCreated (NotifyElement *event)
{
  Element             row, table;
  Element             cell;
  ElementType         elType;
  Document            doc;
  ThotBool            inMath;

  row = event->element;
  doc = event->document;
  elType = TtaGetElementType (row);
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  if (inMath)
    {
      if (elType.ElTypeNum == MathML_EL_MLABELEDTR ||
	  elType.ElTypeNum == MathML_EL_TableRow)
	/* change a mlabeledtr into a mtr */
	TtaChangeElementType (row, MathML_EL_MTR);
      elType.ElTypeNum = MathML_EL_MTABLE;
    }
  else
    elType.ElTypeNum = HTML_EL_Table_;
  table = TtaGetTypedAncestor (row, elType);
  /* remove the cell created by the editor */
  cell = GetFirstCellOfRow (row, inMath);
  if (cell)
    TtaDeleteTree (cell, doc);
  UpdateRowspanForRow (row, doc, inMath, TRUE, TRUE);
  HandleColAndRowAlignAttributes (row, doc);
}

/*----------------------------------------------------------------------
   RowPasted
   A row with its cells has been pasted in a table. The cells have no rowspan
   attributes (such attributes have been removed when copying or deleting
   the row), but they may have colspan attributes. There is no "hole" in the
   pasted row: all empty positions in the original row left by cells spanning
   vertically from other rows have been filled by empty cells when copying or
   deleting the row, but the pasted row may be too short (or too long) if it
   comes from another table.
  ----------------------------------------------------------------------*/
void RowPasted (NotifyElement * event)
{
  Element             row, table, colhead, prevCell, cell, nextCell,
                      spanningCell;
  ElementType         elType;
  Attribute           attr;
  AttributeType       colspanType;
  Document            doc;
  int                 colspan, length, nPosTaken, ncol;
  ThotBool            inMath, cellLinked, closeCurrentCell;

  row = event->element;   /* the pasted row */
  doc = event->document;
  elType = TtaGetElementType (row);
  inMath = TtaSameSSchemas (elType.ElSSchema, TtaGetSSchema ("MathML", doc));
  attr = NULL;
  colspan = 1;
  /* get the table element that contains the pasted row */
  if (inMath)
    elType.ElTypeNum = MathML_EL_MTABLE;
  else
    elType.ElTypeNum = HTML_EL_Table_;
  table = TtaGetTypedAncestor (row, elType);

  /* prepare some attribute and element types */
  colspanType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    {
      elType.ElTypeNum = MathML_EL_MColumn_head;
      colspanType.AttrTypeNum = MathML_ATTR_columnspan;
    }
  else
    {
      elType.ElTypeNum = HTML_EL_Column_head;
      colspanType.AttrTypeNum = HTML_ATTR_colspan_;
    }

  /* get the first column head in the table */
  colhead = TtaSearchTypedElement (elType, SearchInTree, table);

  /* get the first cell in the pasted row */
  prevCell = NULL;
  cell = GetFirstCellOfRow (row, inMath);
  if (cell && inMath)
    {
      elType = TtaGetElementType (cell);
      if (elType.ElTypeNum == MathML_EL_RowLabel)
	/* we are pasting a mlabeledtr element. ignore the first element
	   in the row: it's the label */
	cell = GetSiblingCell (cell, FALSE, inMath);
    }
  nextCell = NULL;
  cellLinked = FALSE;

  /* length (number of columns) of the current cell in the pasted row */
  length = 0;  /* we don't know yet */
  ncol = 0;
  /* number of positions (columns) taken in the pasted row by a cell spanning
     from above */
  nPosTaken = 0;

  /* check each column, one after the other, but stop if a cell from a row
     above spans vertically the pasted row and spans horizontally up to
     the last column */
  while (colhead && nPosTaken != THOT_MAXINT)
    {
      closeCurrentCell = FALSE;
      if (length == 0 && cell)
	/* we are handling a new cell. Get its length */
	{
	  colspan = 1;       /* default length of a cell */
	  attr = TtaGetAttribute (cell, colspanType);
	  if (attr)
	    {
	      colspan = TtaGetAttributeValue (attr);
	      if (colspan < 0)
		colspan = 1;
	    }
	  if (colspan == 0)
	    length = THOT_MAXINT;
	  else
	    length = colspan;
	}
      if (nPosTaken == 0)
	/* this position is not taken by a vertically spanning cell from a
	   previous column. Check the vertically spanning cells for this
	   column */
	{
	  spanningCell = SpanningCellForRow (row, colhead, doc, inMath, TRUE,
					     TRUE, &nPosTaken);
	  if (!spanningCell)
	    nPosTaken = 0;
	  else
	    if (nPosTaken == 0)
	      nPosTaken = THOT_MAXINT;
	}
      if (nPosTaken == 0)
	/* this position is free */
	{
	  if (cell)
	    /* link the current cell of the pasted row with this column head */
	    {
	      if (!cellLinked)
		{
		  LinkCellToColumnHead (cell, colhead, doc, inMath);
		  cellLinked = TRUE;
		  ncol = 0;
		}
	    }
	  else
	    /* no more cells in the pasted row. Add an empty cell for this
	       column */
	    {
	      cell = AddEmptyCellInRow (row, colhead, prevCell, FALSE, doc,
					inMath, FALSE, FALSE);
	      attr = NULL;
	      colspan = 1; length = 0;
	      cellLinked = TRUE;
	      closeCurrentCell = TRUE;
	    }
	}
      else
	/* this position is taken by a cell spanning from above */
	{
	  /* if a cell has been linked to a column head, this cell can't
	     span further than the current column */
	  if (cellLinked)
	    closeCurrentCell = TRUE;
	}

      if (colhead)
	/* make one step: go to the next column of the table */
	{
	  TtaNextSibling (&colhead);
	  if (cellLinked && !closeCurrentCell)
	    /* update the current length of the cell */
	    ncol++;
	  if (!colhead)
	    /* last column. the current cell has to be closed */
	    closeCurrentCell = TRUE;
	  else
	    {
	      if (nPosTaken > 0 && nPosTaken != THOT_MAXINT)
		nPosTaken--;
	    }
	  if (length > 0 && length != THOT_MAXINT)
	    length--;
	  if (length == 0)
	    closeCurrentCell = TRUE;
	}

      if (closeCurrentCell)
	/* close the current cell in the pasted row */
	{
	  nextCell = GetSiblingCell (cell, FALSE, inMath);
	  if (cellLinked)
	    /* the cell had at least one free position */
	    {
	      /* set the new value of colspan to the number of columns we
		 have encountered since the cell was linked to its column
		 head, except if we have reached the last column of the table
		 and the original colspan of the cell was 0 */
	      if (colhead || colspan != 0)
		colspan = ncol;
	      /* set the new colspan of the cell */
	      if (colspan == 1)
		{
		  if (attr)
		    TtaRemoveAttribute (cell, attr, doc);
		}
	      else
		{
		  if (!attr)
		    {
		      attr = TtaNewAttribute (colspanType);
		      if (attr)
			TtaAttachAttribute (cell, attr, doc);
		    }
		  if (attr)
		    TtaSetAttributeValue (attr, colspan, cell, doc);
		}
	      SetColExt (cell, colspan, doc, inMath, FALSE);
	      prevCell = cell;
	    }
	  else
	    /* no free position found for the cell. Delete it */
	    TtaDeleteTree (cell, doc);
	  /* handle now the next cell, which is not linked to any column head
	     yet (perhaps, there is no room for it, we will see) */
	  cell = nextCell;
	  cellLinked = FALSE;
	  length = 0;   /* we don't know yet the actual length of this cell */
	}
    }

  /* we have checked all columns of the table */
  /* if there are extra cells in the pasted row, delete them */
  while (cell)
    {
      nextCell = GetSiblingCell (cell, FALSE, inMath);
      TtaDeleteTree (cell, doc);
      cell = nextCell;
    }
  HandleColAndRowAlignAttributes (row, doc);
  /* Check attribute NAME or ID in order to make sure that its value */
  /* is unique in the document */
  MakeUniqueName (row, doc, TRUE, TRUE);
}

/*----------------------------------------------------------------------
   MoveCellContents
   Move all children of element nextCell as siblings of element previous
   (if it is not NULL) or as children of element cell (if previous is NULL),
   and delete element nextCell.
   When returning, previous is the latest element moved.
  ----------------------------------------------------------------------*/
static void MoveCellContents (Element nextCell, Element cell,
			      Element* previous, Document doc, ThotBool inMath)
{
  Element             child, nextChild;
  ElementType         elType;

  TtaRegisterElementDelete (nextCell, doc);
  if (TtaGetElementVolume (nextCell) == 0)
    /* empty cell */
    child = NULL;
  else
    {
      child = TtaGetFirstChild (nextCell);
      if (inMath)
	/* get the first element contained in the CellWrapper */
	child = TtaGetFirstChild (child);
    }
  /* move the contents of this cell to the cell whose attribute colspan
     has changed */
  while (child)
    {
      nextChild = child;  TtaNextSibling (&nextChild);
      TtaRemoveTree (child, doc);
      if (!inMath && *previous)
	/* if it's a pseudo-paragraph, change it into a
	   paragraph */
	{
	  elType = TtaGetElementType (child);
	  if (elType.ElTypeNum == HTML_EL_Pseudo_paragraph)
	    TtaChangeElementType (child, HTML_EL_Paragraph);
	}
      if (*previous)
	TtaInsertSibling (child, *previous, FALSE, doc);
      else
	TtaInsertFirstChild (&child, cell, doc);
      TtaRegisterElementCreate (child, doc);
      *previous = child;
      child = nextChild;
    }
  /* delete the cell */
  TtaDeleteTree (nextCell, doc);
}

/*----------------------------------------------------------------------
  GetActualColspan
  Return the number of columns comprised between the beginning of the cell
  and the end of the table.
  ----------------------------------------------------------------------*/
int GetActualColspan (Element cell, ThotBool inMath)
{
  Element            colhead;
  ElementType        elType;
  Attribute          attr;
  AttributeType      attrType;
  int                span;

  elType = TtaGetElementType (cell);
  attrType.AttrSSchema = elType.ElSSchema;
  if (inMath)
    attrType.AttrTypeNum = MathML_ATTR_MRef_column;
  else
    attrType.AttrTypeNum = HTML_ATTR_Ref_column;
  attr = TtaGetAttribute (cell, attrType);
  if (attr)
    TtaGiveReferenceAttributeValue (attr, &colhead);
  span = 1;
  while (colhead)
    {
      TtaNextSibling (&colhead);
      if (colhead)
	span++;
    }
  return span;
}

/*----------------------------------------------------------------------
   ChangeColspan
   The value of the colspan attribute has changed from oldspan to newspan
   for the given cell. Add new empty cells (if newspan < oldspan) after
   element cell or merge the following cells (if oldspan > newspan).
   When merging cells on the right, one or several columns may become empty.
   Such columns are deleted and the value of newspan is decreased accordingly.
  ----------------------------------------------------------------------*/
void ChangeColspan (Element cell, int oldspan, int* newspan, Document doc)
{
  Element             table, nextCell, previous, colHead, curColHead, cHead,
                      prevColHead, row, curRow, prevCell;
  ElementType         tableType;
  AttributeType       attrType, rowspanType, colspanType;
  Attribute           attr, attrRowspan;
  int                 ncol, nrow, i, j, rowspan, curColspan, curRowspan,
                      updatedColspan, newRowspan, newColspan;
  ThotBool            inMath;

  updatedColspan = *newspan;
  if (oldspan == *newspan)
    /* no change */
    return;
  if (cell == NULL)
    return;

  tableType = TtaGetElementType (cell);
  attrType.AttrSSchema = tableType.ElSSchema;
  rowspanType.AttrSSchema = tableType.ElSSchema;
  colspanType.AttrSSchema = tableType.ElSSchema;
  inMath = TtaSameSSchemas (tableType.ElSSchema, TtaGetSSchema ("MathML",doc));
  if (inMath)
    {
      tableType.ElTypeNum = MathML_EL_MTABLE;
      attrType.AttrTypeNum = MathML_ATTR_MRef_column;
      rowspanType.AttrTypeNum = MathML_ATTR_rowspan_;
      colspanType.AttrTypeNum = MathML_ATTR_columnspan;
    }
  else
    {
      tableType.ElTypeNum = HTML_EL_Table_;
      attrType.AttrTypeNum = HTML_ATTR_Ref_column;
      rowspanType.AttrTypeNum = HTML_ATTR_rowspan_;
      colspanType.AttrTypeNum = HTML_ATTR_colspan_;
    }
  table = TtaGetTypedAncestor (cell, tableType);
  row = TtaGetParent (cell);

  /* get the rowspan value of the cell */
  attr = TtaGetAttribute (cell, rowspanType);
  if (attr)
    {
      rowspan = TtaGetAttributeValue (attr);
      if (rowspan < 0)
	rowspan = 1;
    }
  else
    rowspan = 1;
  /* get the column of the cell */
  attr = TtaGetAttribute (cell, attrType);
  if (attr)
    TtaGiveReferenceAttributeValue (attr, &colHead);
  else
    return;

  if ((*newspan > oldspan && oldspan > 0) || *newspan == 0)
    /* merge with cells in following columns */
    {
      previous = TtaGetLastChild (cell);
      if (inMath)
	/* get the last element contained in the CellWrapper */
	previous = TtaGetLastChild (previous);
      curColHead = colHead;
      ncol = 0;
      while (curColHead && (ncol < *newspan || *newspan == 0))
	{
	  ncol++; /* count columns */
	  if (ncol <= oldspan)
	    TtaNextSibling (&curColHead);
	  else
	    {
	      curRow = row; nrow = 0;
	      while (curRow && (nrow < rowspan || rowspan == 0))
		{
		  nrow++;
		  nextCell = GetCellFromColumnHead (curRow, curColHead,inMath);
		  if (nextCell)
		    {
		      /* get the colspan value of the current cell */
		      attr = TtaGetAttribute (nextCell, colspanType);
		      if (attr)
			{
			  curColspan = TtaGetAttributeValue (attr);
			  if (curColspan < 0)
			    curColspan = 1;
			}
		      else
			curColspan = 1;
		      /* get the rowspan value of the current cell */
		      attrRowspan = TtaGetAttribute (nextCell, rowspanType);
		      if (attrRowspan)
			{
			  curRowspan = TtaGetAttributeValue (attrRowspan);
			  if (curRowspan < 0)
			    curRowspan = 1;
			}
		      else
			curRowspan = 1;
		      if (*newspan > 0 &&
			  (curColspan > *newspan - ncol + 1 || curColspan ==0))
			/* this cell is deeper than the extended cell */
			{
			  newColspan = *newspan - ncol + 1;
			  /* create empty cells to fill the extra depth */
			  ChangeColspan (nextCell, curColspan, &newColspan,
					 doc);
			}
		      /* if this cell extends beyound the limit of the
			 extension of the cell of interest, fill the holes
			 with empty cells */
		      if ((curRowspan == 0 ||
			   nrow + curRowspan - 1 > rowspan) &&
			  rowspan > 0)
			{
			  newRowspan = rowspan - nrow + 1;
			  ChangeRowspan (nextCell, curRowspan, &newRowspan,
					 doc);
			  /* update the rowspan attribute to allow undo to
			     work properly */
			  if (newRowspan > 1)
			    {
			      if (attrRowspan)
				{
				  TtaRegisterAttributeReplace (attrRowspan,
							       nextCell, doc);
				  TtaSetAttributeValue (attrRowspan,newRowspan,
							nextCell, doc);
				}
			    }
			  else if (newRowspan == 1)
			    if (attrRowspan)
			      {
				TtaRegisterAttributeDelete (attrRowspan,
							    nextCell, doc);
			        TtaRemoveAttribute (nextCell, attrRowspan,doc);
			      }
			}
		      /* merge a cell from that column */
		      MoveCellContents (nextCell, cell, &previous, doc,inMath);
		    }
		  curRow = GetSiblingRow (curRow, FALSE, inMath);
		}
	      prevColHead = curColHead;
	      TtaNextSibling (&curColHead);
	      if (!TtaGetFirstReferringAttribute (prevColHead, attrType))
		/* there is no cell left in the current column. Delete it */
		{
		  ClearColumn (prevColHead, doc);
		  TtaRegisterElementDelete (prevColHead, doc);
		  TtaDeleteTree (prevColHead, doc);
		  if (updatedColspan > 1)
		    updatedColspan--;
		}
	    }
	}
    }
  else
    /* generate empty cells */
    {
      /* process all rows covered by the cell (due to attribute rowspan) */
      curRow = row; i = 0;
      while (curRow && (i < rowspan || rowspan == 0))
	{
	  i++;
	  if (curRow == row)
	    prevCell = cell;
	  else
	    {
	      cHead = colHead;
	      prevCell = NULL;
	      do
		{
		  TtaPreviousSibling (&cHead);
		  if (cHead)
		    prevCell = GetCellFromColumnHead (curRow, cHead,
						      inMath);
		}
	      while (cHead && !prevCell);
	    }
	  cHead = colHead;
	  /* skip the columns covered by the cell with its new colspan */
	  for (j = 0; j < *newspan && cHead; j++)
	    TtaNextSibling (&cHead);
	  /* add new empty cells to fill the space left by reducing the
	     colspan value */
	  for (ncol = 0; (oldspan == 0 || ncol < oldspan - *newspan) && cHead;
	       ncol++)
	    {
	      prevCell = AddEmptyCellInRow (curRow, cHead, prevCell, FALSE,
					    doc, inMath, FALSE, TRUE);
	      TtaNextSibling (&cHead);
	    }
	  /* next sibling of current row */
	  curRow = GetSiblingRow (curRow, FALSE, inMath);
	}
    }
  *newspan = updatedColspan;
}

/*----------------------------------------------------------------------
   ColspanCreated
   An attribute colspan has just been created by the user.
  ----------------------------------------------------------------------*/
void ColspanCreated (NotifyAttribute * event)
{
  Element             cell;
  Attribute           attr;
  Document            doc;
  int                 span, max, overflow;
  ThotBool            inMath;

  doc = event->document;
  cell = event->element;
  attr = event->attribute;
  inMath = TtaSameSSchemas (TtaGetElementType (cell).ElSSchema,
			    TtaGetSSchema ("MathML", doc));
  span = TtaGetAttributeValue (attr);
  if (span < 0 || span == 1)
    /* invalid value. Change it to 2 */
    {
      span = 2;
      TtaSetAttributeValue (attr, span, cell, doc);
    }
  else
    {
      max = GetActualColspan (cell, inMath);
      if (span > max)
	{
	  span = max;
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
    }
  /* for undo operations just restore the col extension */
  if (event->info != 1)
    {
      /* the creation of the attribute with its value has already been
	 registered in the history by the Thot editor. We need to cancel that
	 record and do as if the attribute was created after the registration
	 of the deletion of cells done by ChangeColspan.
         That way, when undoing the attribute creation, the deleted cells can
	 be restored correctly */
      TtaCancelLastRegisteredOperation (doc);
      ChangeColspan (cell, 1, &span, doc);
      TtaRegisterAttributeCreate (attr, cell, doc);
    }
  overflow = SetColExt (cell, span, doc, inMath, FALSE);
}

/*----------------------------------------------------------------------
   RegisterColspan                                         
  ----------------------------------------------------------------------*/
ThotBool RegisterColspan (NotifyAttribute * event)
{
  PreviousColspan = TtaGetAttributeValue (event->attribute);
  if (PreviousColspan < 0)
    PreviousColspan = 1;
  return FALSE;		/* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
   ColspanModified                                         
  ----------------------------------------------------------------------*/
void ColspanModified (NotifyAttribute * event)
{
  Element             cell;
  Attribute           attr;
  Document            doc;
  int                 span, max, overflow;
  ThotBool            inMath;

  doc = event->document;
  cell = event->element;
  attr = event->attribute;
  inMath = TtaSameSSchemas (TtaGetElementType (cell).ElSSchema,
			    TtaGetSSchema ("MathML", doc));
  span = TtaGetAttributeValue (attr);
  if (span == 1)
    /* keep the previous value to restore it when undoing the change */
    TtaSetAttributeValue (attr, PreviousColspan, cell, doc);
  else if (span < 0)
    /* invalid value, keep the previous value */
    {
      span = PreviousColspan;
      TtaSetAttributeValue (attr, span, cell, doc);
    }
  else
    {
      max = GetActualColspan (cell, inMath);
      if (span > max)
	{
	  span = max;
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
    }
  if (span != PreviousColspan || span == 0)
    {
      /* for undo operations just restore the col extension */
      if (event->info != 1)
	{
	  /* the previous value of the attribute has already been registered
	     in the history by the Thot editor. We need to cancel that record
	     and to register the old value of the attribute after the
	     registration of the creation or deletion of cells done by
             ChangeColspan. That way, when undoing the attribute modification,
	     the deletion or creation of cells can be undone correctly */
	  TtaCancelLastRegisteredAttrOperation (doc);
	  ChangeColspan (cell, PreviousColspan, &span, doc);
	  TtaSetAttributeValue (attr, PreviousColspan, cell, doc);
	  TtaRegisterAttributeReplace (attr, cell, doc);
	  /* now, we can restore the new value */
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
      overflow = SetColExt (cell, span, doc, inMath, FALSE);
    }
  if (span < 0 || span == 1)
    /* invalid value */
    {
      TtaRegisterAttributeDelete (attr, cell, doc);
      TtaRemoveAttribute (cell, attr, doc);
    }
}

/*----------------------------------------------------------------------
   ColspanDeleted
  ----------------------------------------------------------------------*/
void ColspanDeleted (NotifyAttribute * event)
{
  ElementType         elType;
  ThotBool            inMath;
  int                 newColspan;

  if (PreviousColspan > 1 || PreviousColspan == 0)
    {
      /* for undo operations just restore the col extension */
      if (event->info != 1)
	{
	  newColspan = 1;
	  ChangeColspan (event->element, PreviousColspan, &newColspan,
			 event->document);
	}
      elType = TtaGetElementType (event->element);
      inMath = TtaSameSSchemas (elType.ElSSchema,
				TtaGetSSchema ("MathML", event->document));
      SetColExt (event->element, 1, event->document, inMath, FALSE);
    }
}

/*----------------------------------------------------------------------
  GetActualRowspan
  Return the number of rows comprised between the beginning of the cell
  and the end of the rows group.
  ----------------------------------------------------------------------*/
int GetActualRowspan (Element cell, ThotBool inMath)
{
  Element            row;
  int                span;

  row = TtaGetParent (cell);
  span = 1;
  while (row)
    {
      row = GetSiblingRow (row, FALSE, inMath);
      if (row)
	span++;
    }
  return span;
}

/*----------------------------------------------------------------------
   ChangeRowspan
   The value of the rowspan attribute has changed from oldspan to newspan
   for the given cell. Add new empty cells (if newspan < oldspan) below
   the cell or merge the cells below (if oldspan > newspan).
   When merging cells below, one or several rows may become empty. Such
   rows are deleted and the value of newspan is decreased accordingly.
  ----------------------------------------------------------------------*/
void ChangeRowspan (Element cell, int oldspan, int* newspan, Document doc)
{
  Element             table, row, prevRow, previous, nextCell, prevCell,
                      colHead, curColHead, siblingColhead;
  ElementType         tableType;
  AttributeType       attrType, colspanType, rowspanType;
  Attribute           attr, attrColspan;
  int                 i, nrows, ncol, colspan, curColspan, curRowspan,
                      updatedRowspan, newRowspan, newColspan;
  ThotBool            inMath, before = FALSE;

  updatedRowspan = *newspan;
  if (oldspan == *newspan)
    /* no change */
    return;
  if (cell == NULL)
    return;

  tableType = TtaGetElementType (cell);
  attrType.AttrSSchema = tableType.ElSSchema;
  colspanType.AttrSSchema = tableType.ElSSchema;
  rowspanType.AttrSSchema = tableType.ElSSchema;
  inMath = TtaSameSSchemas (tableType.ElSSchema, TtaGetSSchema ("MathML",doc));
  if (inMath)
    {
      tableType.ElTypeNum = MathML_EL_MTABLE;
      attrType.AttrTypeNum = MathML_ATTR_MRef_column;
      colspanType.AttrTypeNum = MathML_ATTR_columnspan;
      rowspanType.AttrTypeNum = MathML_ATTR_rowspan_;
    }
  else
    {
      tableType.ElTypeNum = HTML_EL_Table_;
      attrType.AttrTypeNum = HTML_ATTR_Ref_column;
      colspanType.AttrTypeNum = HTML_ATTR_colspan_;
      rowspanType.AttrTypeNum = HTML_ATTR_rowspan_;
    }
  table = TtaGetTypedAncestor (cell, tableType);
  row = TtaGetParent (cell);

  /* get the colspan value of the cell */
  attr = TtaGetAttribute (cell, colspanType);
  if (attr)
    {
      colspan = TtaGetAttributeValue (attr);
      if (colspan < 0)
	colspan = 1;
    }
  else
    colspan = 1;
  /* get the column of the cell */
  attr = TtaGetAttribute (cell, attrType);
  if (attr)
    TtaGiveReferenceAttributeValue (attr, &colHead);
  else
    return;

  nrows = 0;
  if ((*newspan > oldspan && oldspan > 0) || *newspan == 0)
    /* merge with cells in the following rows */
    {
      previous = TtaGetLastChild (cell);
      if (inMath)
	/* get the last element contained in the CellWrapper */
	previous = TtaGetLastChild (previous);
      while (row && (nrows < *newspan || *newspan == 0))
	{
	  nrows++; /* count rows */
	  if (nrows <= oldspan)
	    row = GetSiblingRow (row, FALSE, inMath);
	  else
	    {
	      curColHead = colHead; ncol = 0;
	      while (curColHead && (ncol < colspan || colspan == 0))
		{
		  ncol++;
		  nextCell = GetCellFromColumnHead (row, curColHead, inMath);
		  if (nextCell)
		    {
		      /* get the colspan value of the current cell */
		      attrColspan = TtaGetAttribute (nextCell, colspanType);
		      if (attrColspan)
			{
			  curColspan = TtaGetAttributeValue (attrColspan);
			  if (curColspan < 0)
			    curColspan = 1;
			}
		      else
			curColspan = 1;
		      /* get the rowspan value of the current cell */
		      attr = TtaGetAttribute (nextCell, rowspanType);
		      if (attr)
			{
			  curRowspan = TtaGetAttributeValue (attr);
			  if (curRowspan < 0)
			    curRowspan = 1;
			}
		      else
			curRowspan = 1;
		      if (colspan > 0 &&
			  (curColspan > colspan || curColspan == 0))
			/* this cell is wider than the extended cell */
			/* create empty cells to fill the extra width */
			{
			  newColspan = colspan - ncol + 1;
			  ChangeColspan (nextCell, curColspan, &newColspan,
					 doc);
			  /* update the colspan attribute to allow undo to
			     work properly */
			  if (newColspan > 1)
			    {
			      if (attrColspan)
				{
				  TtaRegisterAttributeReplace (attrColspan,
							       nextCell, doc);
				  TtaSetAttributeValue (attrColspan,newColspan,
							nextCell, doc);
				}
			    }
			  else if (newColspan == 1)
			    if (attrColspan)
			      {
				TtaRegisterAttributeDelete (attrColspan,
							    nextCell, doc);
				TtaRemoveAttribute (nextCell, attrColspan,doc);
			      }
			}
		      /* if this cell extends beyound the limit of the
			 extension of the cell of interest, fill the holes
			 with empty cells */
		      if ((curRowspan == 0 ||
			   nrows + curRowspan - 1 > *newspan) &&
			  *newspan >  0)
			{
			  newRowspan = *newspan - nrows + 1;
			  ChangeRowspan (nextCell, curRowspan, &newRowspan,
					 doc);
			}
		      /* merge a cell from that row */
		      MoveCellContents (nextCell, cell, &previous, doc,inMath);
		    }
		  TtaNextSibling (&curColHead);
		}
	      prevRow = row;
	      row = GetSiblingRow (row, FALSE, inMath);
	      if (!GetFirstCellOfRow (prevRow, inMath))
		/* there is no cell left in the current row. Delete it */
		{
		  /* decrease the value of the rowspan attribute of cells from
		     rows above that span the deleted row */
		  UpdateRowspanForRow (prevRow, doc, inMath, FALSE, FALSE);
		  TtaRegisterElementDelete (prevRow, doc);
		  TtaDeleteTree (prevRow, doc);
		  if (updatedRowspan > 1)
		    updatedRowspan--;
		}
	    }
	}
    }
  else if ((*newspan < oldspan && *newspan > 0) || oldspan == 0)
    /* generate empty cells */
    {
      while (row && (nrows < oldspan || oldspan == 0))
	{
	  nrows++;
	  if (nrows > *newspan)
	    {
	      prevCell = NULL;
	      siblingColhead = colHead;
	      TtaPreviousSibling (&siblingColhead);
	      if (siblingColhead)
		{
		  prevCell = GetCellFromColumnHead (row, siblingColhead,
						    inMath);
		  if (prevCell)
		    before = FALSE;
		}
	      if (!prevCell)
		{
		  before = TRUE;
		  siblingColhead = colHead;
		  while (siblingColhead && !prevCell)
		    {
		      TtaNextSibling (&siblingColhead);
		      prevCell = GetCellFromColumnHead (row,siblingColhead,
							inMath);
		    }
		}
	      curColHead = colHead;
	      for (i = 0; (i < colspan || colspan == 0) && curColHead; i++)
		{
		  prevCell = AddEmptyCellInRow (row, curColHead, prevCell,
					     before, doc, inMath, FALSE, TRUE);
		  before = FALSE;
		  TtaNextSibling (&curColHead);
		}
	    }
	  row = GetSiblingRow (row, FALSE, inMath);
	}
    }
  *newspan = updatedRowspan;
}

/*----------------------------------------------------------------------
   RowspanCreated                                          
  ----------------------------------------------------------------------*/
void RowspanCreated (NotifyAttribute * event)
{
  Element             cell;
  Attribute           attr;
  Document            doc;
  int                 span, max;
  ThotBool            inMath;

  doc = event->document;
  cell = event->element;
  attr = event->attribute;
  inMath = TtaSameSSchemas (TtaGetElementType (cell).ElSSchema,
			    TtaGetSSchema ("MathML", doc));
  span = TtaGetAttributeValue (attr);
  if (span < 0 || span == 1)
    /* invalid value. Change it to 2 */
    {
      span = 2;
      TtaSetAttributeValue (attr, span, cell, doc);
    }
  else
    {
      max = GetActualRowspan (cell, inMath);
      if (span > max)
	{
	  span = max;
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
    }
  /* for undo operations just restore the row extension */
  if (event->info != 1)
    {
      /* the creation of the attribute has already been registered
	 in the history by the Thot editor. We need to cancel that record
	 and do as if the attribute was created after the registration of
         the deletion of cells done by ChangeRowspan.
         That way, when undoing the attribute creation, the deleted cells can
	 be restored correctly */
      TtaCancelLastRegisteredOperation (doc);
      ChangeRowspan (cell, 1, &span, doc);
      TtaRegisterAttributeCreate (attr, cell, doc);
    }
  SetRowExt (cell, span, doc, inMath);
}

/*----------------------------------------------------------------------
   RegisterRowspan                                         
  ----------------------------------------------------------------------*/
ThotBool RegisterRowspan (NotifyAttribute * event)
{
  PreviousRowspan = TtaGetAttributeValue (event->attribute);
  if (PreviousRowspan < 0)
    PreviousRowspan = 1;
  return FALSE;		/* let Thot perform normal operation */
}

/*----------------------------------------------------------------------
   RowspanModified                                         
  ----------------------------------------------------------------------*/
void RowspanModified (NotifyAttribute * event)
{
  Element             cell;
  Attribute           attr;
  Document            doc;
  int                 span, max;
  ThotBool            inMath;

  doc = event->document;
  cell = event->element;
  attr = event->attribute;
  inMath = TtaSameSSchemas (TtaGetElementType (cell).ElSSchema,
			    TtaGetSSchema ("MathML", doc));
  span = TtaGetAttributeValue (attr);
  if (span == 1)
    /* keep the previous value to restore it when undoing the change */
    TtaSetAttributeValue (attr, PreviousRowspan, cell, doc);
  else if (span < 0)
    /* invalid value, keep the previous value */
    {
      span = PreviousRowspan;
      TtaSetAttributeValue (attr, span, cell, doc);
    }
  else
    {
      max = GetActualRowspan (cell, inMath);
      if (span > max)
	{
	  span = max;
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
    }
  if (span != PreviousRowspan)
    {
      /* for undo operations just restore the row extension */
      if (event->info != 1)
	{
	  /* the previous value of the attribute has already been registered
	     in the history by the Thot editor. We need to cancel that record
	     and to register itthe old value of the attribute after the
	     registration of the creation or deletion of cells done by
	     ChangeRowspan. That way, when undoing the attribute modification,
	     the deletion or creation of cells can be undone correctly */
          TtaCancelLastRegisteredOperation (doc);
	  ChangeRowspan (cell, PreviousRowspan, &span, doc);
	  TtaSetAttributeValue (attr, PreviousRowspan, cell, doc);
	  TtaRegisterAttributeReplace (attr, cell, doc);
	  /* now, we can restore the new value */
	  TtaSetAttributeValue (attr, span, cell, doc);
	}
      SetRowExt (cell, span, doc, inMath);
    }
  if (span < 0 || span == 1)
    /* invalid value */
    {
      TtaRegisterAttributeDelete (attr, cell, doc);
      TtaRemoveAttribute (cell, attr, doc);
    }
}

/*----------------------------------------------------------------------
   RowspanDeleted
  ----------------------------------------------------------------------*/
void RowspanDeleted (NotifyAttribute * event)
{
  ElementType         elType;
  ThotBool            inMath;
  int                 newRowspan;

  if (PreviousRowspan > 1 || PreviousRowspan == 0)
    {
      /* for undo operations just restore the row extension */
      if (event->info != 1)
	{
	  newRowspan = 1;
	  ChangeRowspan (event->element, PreviousRowspan, &newRowspan,
			 event->document);
	}
      elType = TtaGetElementType (event->element);
      inMath = TtaSameSSchemas (elType.ElSSchema,
				TtaGetSSchema ("MathML", event->document));
      SetRowExt (event->element, 1, event->document, inMath);
    }
}
