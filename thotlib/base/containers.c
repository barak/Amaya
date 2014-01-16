/*
 *
 *  COPYRIGHT INRIA and W3C, 1996-2005
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */
 
/*
 * Authors: Emilien Kia
 *
 */
#include "thot_sys.h"
#include "containers.h"

#include "application.h"


/*------------------------------------------------------------------------------
 * Generic container
 *----------------------------------------------------------------------------*/

/**
 * Return the element of a node.
 * @param node Node from which get the element.
 * @return Element of the node.
 */
ContainerElement ContainerNode_GetElement(ContainerNode node)
{
  return node->elem;
}

/**
 * Delete an element from a container node.
 * @param container Container of the element
 * @param node Node from which element must be delete.
 */
void Container_DeleteElement(Container container, ContainerNode node)
{
  if(container && node && node->elem && container->destroyElement)
    container->destroyElement(node);
}

/**
 * Delete a node from a container.
 * @param container Container of the node
 * @param node Node to delete.
 */
void Container_DeleteNode(Container container, ContainerNode node)
{
  if(node)
  {
    if(container && node->elem && container->destroyElement)
      container->destroyElement(node);
    TtaFreeMemory(node);
  }
}

/*------------------------------------------------------------------------------
 * Generic forward iterator
 *----------------------------------------------------------------------------*/

/**
 * Create a forward iterator.
 * You can use TtaFreeMemory to delete it.
 * @param container Container on which iterate.
 * @param getFirst GetFirst function address.
 * @param getNext GetNext function address.
 */
ForwardIterator ForwardIterator_Create(Container container,
                    ForwardIterator_GetFirstFunction getFirst,
                    ForwardIterator_GetNextFunction  getNext)
{
  ForwardIterator iter = (ForwardIterator)TtaGetMemory(sizeof(sForwardIterator));
  iter->container   = container;
  iter->currentNode = NULL;
  iter->getFirst    = getFirst;
  iter->getNext     = getNext;
  return iter;
}

/**
 * Get the first element of an iterator.
 * @param iter Iterator
 * @return First node or NULL if empty.
 */
ContainerNode ForwardIterator_GetFirst(ForwardIterator iter)
{
  iter->currentNode = iter->getFirst(iter);
  return iter->currentNode;
}

/**
 * Get the next item in an iterator.
 * @param iter Iterator.
 * @return next node or NULL if no more object.
 */
ContainerNode ForwardIterator_GetNext(ForwardIterator iter)
{
  iter->currentNode = iter->getNext(iter);
  return iter->currentNode; 
}



/*------------------------------------------------------------------------------
 * Double linked list
 *----------------------------------------------------------------------------*/

/**
 * Create a new list of elements.
 * @return Empty list of element. 
 */
DLList DLList_Create()
{
  DLList list = (DLList)TtaGetMemory (sizeof(sDLList));
  list->first = NULL;
  list->last  = NULL;
  
  list->destroyElement = NULL;
  return list;
}

/**
 * Empty a list of element.
 * All elements are freed.
 * @param list List to empty.
 */
void DLList_Empty(DLList list){
  DLListNode node = list->first;
  
  while(node!=NULL)
  {
    DLListNode next = (DLListNode)node->next;
    if(list->destroyElement!=NULL)
      list->destroyElement(node->elem);
    TtaFreeMemory(node);
    node = next;
  }
  list->first = list->last = NULL;  
}

/**
 * Destroy a list of element
 * All element are freed.
 * @param list List to destroy.
 */
void DLList_Destroy(DLList list)
{
  DLList_Empty(list);
  TtaFreeMemory(list);
}

/**
 * Test if a list is empty.
 */
ThotBool DLList_IsEmpty(DLList list)
{
  return list->first==NULL;
}

/**
 * Append an element at the end of the list
 * @param list List at which the new element is append.
 * @param elem Element to append.
 */
DLListNode DLList_Append(DLList list, ContainerElement elem)
{
  DLListNode node = (DLListNode)TtaGetMemory (sizeof(sDLListNode));
  node->elem = elem;
  node->prev = list->last;
  node->next = NULL;

  if(list->first==NULL)
    list->first = (DLListNode)node;

  if(list->last!=NULL)
    list->last->next = node;
  list->last = (DLListNode)node;
  return node;
}

/**
 * Prepend an element at the begining of the list
 * @param list List at which the new element is append.
 * @param elem Element to append.
 */
DLListNode DLList_Prepend(DLList list, ContainerElement elem)
{
  DLListNode node = (DLListNode)TtaGetMemory (sizeof(sDLListNode));
  node->elem = elem;
  node->prev = NULL;
  node->next = list->first;
  
  list->first = (DLListNode)node;
  if(list->last==NULL)
    list->last = (DLListNode)node;
  ((DLListNode)node->next)->prev = node;
  return node;
}

/**
 * Insert an element after an element in a list
 * @param list List at which the new element is append.
 * @param before Node after which the element is to be inserted.
 * @param elem Element to append.
 */
DLListNode DLList_InsertAfter(DLList list, DLListNode before, ContainerElement elem)
{
  DLListNode node = (DLListNode)TtaGetMemory (sizeof(sDLListNode));
  node->elem = elem;
  node->prev = before;
  node->next = before->next;
  
  before->next = node;
  if(node->next==NULL)
    list->last = node;
  else
    ((DLListNode)node->next)->prev = node;
  
  return node;
}

/**
 * Insert an element before an element in a list
 * @param list List at which the new element is append.
 * @param after Node before which the element is to be inserted.
 * @param elem Element to append.
 */
DLListNode DLList_InsertBefore(DLList list, DLListNode after, ContainerElement elem)
{
  DLListNode node = (DLListNode)TtaGetMemory (sizeof(sDLListNode));
  node->elem = elem;
  node->prev = after->prev;
  node->next = after;
  
  after->prev = node;
  if(node->prev==NULL)
    list->first = node;
  else
    ((DLListNode)node->prev)->next = node;
  
  return node;
}

/**
 * Remove an element from a list
 * @param list List from which remove the element.
 * @param node Node to remove.
 * @return Element
 */
ContainerElement DLList_RemoveElement(DLList list, DLListNode node)
{
  ContainerElement elem = node->elem;
  
  if(node==list->first)
    list->first = node->next;
  else
    node->prev->next = node->next;

  if(node==list->last)
    list->last = node->prev;
  else
    node->next->prev = node->prev;

  TtaFreeMemory(node);
  return elem;
}

/**
 * Destroy an element.
 * Remove an element and destroy it.
 * @param list List from which remove the element.
 * @param node Node to remove.
 */
void  DLList_DestroyElement(DLList list, DLListNode node)
{
  ContainerElement elem = DLList_RemoveElement(list, node);
  if(elem && list->destroyElement)
    list->destroyElement(elem);
}


static DLListNode DLListIterator_GetFirst(ForwardIterator iter)
{
  DLList list = (DLList)iter->container;
  if(list)
    return list->first;
  else
    return NULL;
}

static DLListNode DLListIterator_GetNext(ForwardIterator iter)
{
  DLListNode node = (DLListNode) iter->currentNode;
  if(node)
    return node->next;
  else
    return NULL;
}

/**
 * Create a DLList forward iterator.
 * @param list List on which iterate.
 * @return the iterator.
 */
ForwardIterator DLList_GetForwardIterator(DLList list)
{
  return ForwardIterator_Create((Container)list,
          (ForwardIterator_GetFirstFunction)DLListIterator_GetFirst,
          (ForwardIterator_GetNextFunction)DLListIterator_GetNext);
}


/**
 * Swap two nodes.
 */
void DLList_Swap(DLList list, DLListNode node1, DLListNode node2)
{
  DLListNode prev1 = node1->prev,
             prev2 = node2->prev, 
             next1 = node1->next,
             next2 = node2->next;
  DLListNode node;
  node1->next = next2;
  node1->prev = prev2;
  node2->next = next1;
  node2->prev = prev1;
  
  if(prev1==NULL)
    list->first = node2;
  if(next2==NULL)
    list->last = node1;
    
  node = node2;
  node2 = node1;
  node1 = node;
}


/**
 * Sort a list content.
 * @note use a simple bubble sort algorithm (o(n^2)).
 * @param compare, comparaison function.
 */
void DLList_Sort(DLList list, Container_CompareFunction compare)
{
  DLListNode node1, node2;
  node1 = list->first;
  while(node1!=NULL)
  {
    node2 = node1->next;
    while(node2!=NULL)
    {
      if(compare(node1->elem, node2->elem)>0)
        DLList_Swap(list, node1, node2);
      node2 = node2->next;
    }
    node1 = node1->next;    
  }
}

/**
 * Return a new list with references to the param list elements.
 * Reference elements are not destroy if the list is destroyed.
 * @param srcList Source list from which reference elements.
 * @param compare, If not NULL, use it to sort references.
 * @note Use an insert sort algorithm.
 */
DLList DLList_GetRefList(DLList srcList, Container_CompareFunction compare)
{
  DLList list = DLList_Create();
  DLListNode node = srcList->first;
  if(compare==NULL)
  {
    while(node)
    {
      DLList_Append(list, node->elem);
      node = node->next;
    }
  }
  else
  {
    if(node)
    {
      DLList_Append(list, node->elem);
      node = node->next;
    }
    while(node)
    {
      DLListNode test = list->first;
      while(test && compare(test->elem, node->elem))
        test = test->next;
      if(test)
        DLList_InsertBefore(list, test, node->elem);
      else
        DLList_Append(list, node->elem);
      node = node->next;
    }
  }  
  return list;
}

/**
 * Return a new list with references to the param iterator elements.
 * Reference elements are not destroy if the list is destroyed.
 * @param iter Iterator from which reference elements.
 * @param compare, If not NULL, use it to sort references.
 * @note Use an insert sort algorithm.
 */
DLList DLList_GetRefListFromIterator(ForwardIterator iter, Container_CompareFunction compare){
  DLList list = DLList_Create();
  ContainerNode node = ForwardIterator_GetFirst(iter);
  if(compare==NULL)
  {
    while(node)
    {
      DLList_Append(list, node->elem);
      node = ForwardIterator_GetNext(iter);
    }
  }
  else
  {
    if(node)
    {
      DLList_Append(list, node->elem);
      node = ForwardIterator_GetNext(iter);
    }
    while(node)
    {
      DLListNode test = list->first;
      while(test && compare(test->elem, node->elem))
        test = test->next;
      if(test)
        DLList_InsertBefore(list, test, node->elem);
      else
        DLList_Append(list, node->elem);
      node = ForwardIterator_GetNext(iter);
    }
  }  
  return list; 
}


/*------------------------------------------------------------------------------
 * Hash map
 *----------------------------------------------------------------------------*/
/**
 * Simple Hash map "destroy key" function.
 */
static void HashMap_SimpleDestroyKey(HashMapKey key)
{
  /* Do nothing.*/
}

/**
 * Simple Hash map "compare key" function.
 */
static int HashMap_SimpleCompareKey(HashMapKey key1, HashMapKey key2)
{
  return (int)key1-(int)key2;
}
  
/**
 * Allocate a hash map key node (list of node).
 */
static HashMapKeyNode HashMap_CreateHashMapKeyNode(HashMap map)
{
  HashMapKeyNode node = (HashMapKeyNode)DLList_Create();
  node->destroyElement = map->destroyElement;
  return node;
}
 
/**
 * Create a new hash map.
 * @return Empty hash map. 
 */
HashMap HashMap_Create(Container_DestroyElementFunction destroy,
                       HashMap_HashFunction hash,
                       int nbNodes)
{
  HashMap map = (HashMap)TtaGetMemory (sizeof(sHashMap));
  map->destroyElement = destroy;
  map->destroyKey     = HashMap_SimpleDestroyKey;
  map->compare        = HashMap_SimpleCompareKey;
  map->hash           = hash;
  map->nbNodes        = nbNodes;
  map->nodes = (HashMapKeyNode*) TtaGetMemory(sizeof(HashMapKeyNode)*map->nbNodes);
  memset(map->nodes, 0, sizeof(HashMapKeyNode)*map->nbNodes);
  return map;
}

/**
 * Empty an hash map.
 * All element are freed.
 * @param map Map to empty.
 */
void HashMap_Empty(HashMap map)
{
  int i;
  for(i=0; i<map->nbNodes; i++)
  {
    if(map->nodes[i] !=NULL)
    {
      DLList_Destroy((DLList)map->nodes[i]);
      map->nodes[i] = NULL;
    }
  }  
}

/**
 * Destroy an hash map.
 * All element are freed.
 * @param map Map to destroy.
 */
void HashMap_Destroy(HashMap map)
{
  HashMap_Empty(map);
  TtaFreeMemory(map->nodes);
  TtaFreeMemory(map);
}

/**
 * Test if the map is empty.
 */
ThotBool HashMap_IsEmpty(HashMap map)
{
  int i;
  for(i=0; i<map->nbNodes; i++)
  {
    if(map->nodes[i] !=NULL)
    {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Get the internal list for a specified key.
 * Allocate it if not already done.
 */
static HashMapKeyNode HashMap_GetHashMapKeyNode(HashMap map, HashMapKey key, ThotBool create)
{
  int keyval = (map->hash(key))%map->nbNodes;
  if(map->nodes[keyval]==NULL){
    if(create)
      map->nodes[keyval] = HashMap_CreateHashMapKeyNode(map);
  }
  return map->nodes[keyval];
}

/**
 * Set an element in the hash map, the old element is returned.
 * The element and the key are stored in the map.
 * @param key Key of the element.
 * @param elem Element.
 * @return The old element, NULL if none.
 */
ContainerElement HashMap_Set(HashMap map, HashMapKey key, ContainerElement elem)
{
  HashMapKeyNode keynode = HashMap_GetHashMapKeyNode(map, key, TRUE);
  HashMapNode node = (HashMapNode)keynode->first;
  ContainerElement old = NULL;
  while(node!=NULL && map->compare(key, node->key)!=0)
    node = (HashMapNode)node->next;

  if(node!=NULL)
  {
    old = node->elem;
    node->elem = elem;
  }
  else
  {
    node = (HashMapNode)TtaGetMemory(sizeof(sHashMapNode));
    node->elem = elem;
    node->key  = key;
    node->prev = NULL;
    if(keynode->first==NULL)
    {
      keynode->first = keynode->last = (DLListNode)node;
      node->next = NULL;
    }
    else
    {
      keynode->first->prev = (DLListNode)node;
      node->next = (HashMapNode)keynode->first;
      keynode->first = (DLListNode)node; 
    }
  }
  return (ContainerElement)old;
}

/**
 * Find an element of the map.
 * Return the element node or NULL if not found.
 */
HashMapNode HashMap_Find(HashMap map, HashMapKey key)
{
  HashMapKeyNode keynode = HashMap_GetHashMapKeyNode(map, key, FALSE);
  if(keynode!=NULL)
  {
    HashMapNode node = (HashMapNode)keynode->first;
    while(node!=NULL)
    {
      if(map->compare(key, node->key)==0)
        return node;
      node = node->next;
    }
  }
  return NULL;
}

/**
 * Get an element from the hash map.
 * Only the new element is stored in the map.
 * @param key Key of the element
 * @return The searched element or NULL if not found.
 */
ContainerElement HashMap_Get(HashMap map, HashMapKey key)
{
  HashMapNode node = HashMap_Find(map, key);
  if(node!=NULL)
    return node->elem;
  return NULL;
}

/**
 * Remove an element from the hash map and return it.
 * The stored key is destroyed from the map.
 */
ContainerElement HashMap_Remove(HashMap map, HashMapKey key)
{
  HashMapKeyNode keynode = HashMap_GetHashMapKeyNode(map, key, FALSE);  
  if(keynode!=NULL)
  {
    HashMapNode node = (HashMapNode)keynode->first;
    while(node!=NULL)
    {
      if(map->compare(key, node->key)==0)
      {
        if(node->key)
          map->destroyKey(node->key);
        return DLList_RemoveElement((DLList)keynode, (DLListNode) node); 
      }
      node = node->next;
    }
  }
  return NULL;  
}

/**
 * Destroy an element from the hash map.
 * Both stored element and key are destroyed.
 */
void HashMap_DestroyElement(HashMap map, HashMapKey key)
{
  HashMapKeyNode keynode = HashMap_GetHashMapKeyNode(map, key, FALSE);
  if(keynode!=NULL)
  {
    HashMapNode node = (HashMapNode)keynode->first;
    while(node!=NULL)
    {
      if(map->compare(key, node->key)==0)
      {
        if(node->key)
          map->destroyKey(node->key);
        DLList_DestroyElement((DLList)keynode, (DLListNode) node);
        return;
      }
      node = node->next;
    }
  }
}

static HashMapNode HashMapIterator_GetFirst(ForwardIterator iter)
{
  HashMap map = (HashMap) iter->container;
  int i;
  for(i=0; i< map->nbNodes; i++)
  {
    if(map->nodes[i]!=NULL){
      if(map->nodes[i]->first!=NULL)
        return (HashMapNode)map->nodes[i]->first;
    }
  }
  return NULL;
}

static HashMapNode HashMapIterator_GetNext(ForwardIterator iter)
{
  HashMap map = (HashMap) iter->container;
  HashMapNode node = (HashMapNode) iter->currentNode;
  if(node->next!=NULL)
  {
    return node->next;
  }
  else
  {
    int i = (map->hash(node->key)%map->nbNodes)+1;
    for(; i< map->nbNodes; i++)
    {
      if(map->nodes[i]!=NULL){
        if(map->nodes[i]->first!=NULL)
          return (HashMapNode)map->nodes[i]->first;
      }
    }
  }
  return NULL;
}

/**
 * Get a simple forward iterator on the content of the map.
 * This iterator simply list all the content, the iterator order is not sorted.
 */
ForwardIterator  HashMap_GetForwardIterator(HashMap map)
{
  return ForwardIterator_Create((Container)map,
          (ForwardIterator_GetFirstFunction)HashMapIterator_GetFirst,
          (ForwardIterator_GetNextFunction)HashMapIterator_GetNext);  
}

/*------------------------------------------------------------------------------
 * Pointer hash map
 *----------------------------------------------------------------------------*/

static int PointerHashMap_HashFunction(void* key)
{
  return (int) key; 
}

HashMap PointerHashMap_Create(Container_DestroyElementFunction destroy,
                                      int nbNodes)
{
  return HashMap_Create(destroy, (HashMap_HashFunction)PointerHashMap_HashFunction, nbNodes);
}

/*------------------------------------------------------------------------------
 * String hash map
 *----------------------------------------------------------------------------*/

static int StringHashMap_HashFunction(char* key)
{
  int res = 0;
  while(*key!=0){
    res += *key;
    key++;
  }
  res %= 256;
  return res;
}

static int StringHashMap_CompareKey(HashMapKey key1, HashMapKey key2)
{
  return strcmp((const char*)key1, (const char*)key2);
}
  

/**
 * Create a string hash map
 */
HashMap StringHashMap_Create(Container_DestroyElementFunction destroy, ThotBool keyIsStored, int nbNodes)
{
  HashMap map = HashMap_Create(destroy,
                              (HashMap_HashFunction)StringHashMap_HashFunction, nbNodes);
  map->compare = StringHashMap_CompareKey;
  return map;
}

/*------------------------------------------------------------------------------
 * Keyword hash map
 *----------------------------------------------------------------------------*/
static int KeywordHashMap_HashFunction(char* key)
{
  return *key;
}
 
HashMap KeywordHashMap_Create(Container_DestroyElementFunction destroy,
                                      ThotBool keyIsStored, int nbNodes)
{
  HashMap map = HashMap_Create(destroy,
                              (HashMap_HashFunction)KeywordHashMap_HashFunction, nbNodes);
  map->compare = StringHashMap_CompareKey;
  return map;
}
