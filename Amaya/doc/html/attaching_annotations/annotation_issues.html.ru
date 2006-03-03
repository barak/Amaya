<?xml version="1.0" encoding="windows-1251"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
       "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=windows-1251" />
  <title>&#xc8;&#xe7;&#xe2;&#xe5;&#xf1;&#xf2;&#xed;&#xfb;&#xe5;
  &#xef;&#xf0;&#xee;&#xe1;&#xeb;&#xe5;&#xec;&#xfb; &#xf1;
  &#xe0;&#xed;&#xed;&#xee;&#xf2;&#xe0;&#xf6;&#xe8;&#xff;&#xec;&#xe8; &#xe8;
  &#xf0;&#xe5;&#xe4;&#xe0;&#xea;&#xf2;&#xe8;&#xf0;&#xee;&#xe2;&#xe0;&#xed;&#xe8;&#xe5;&#xec;
  &#xe4;&#xee;&#xea;&#xf3;&#xec;&#xe5;&#xed;&#xf2;&#xee;&#xe2;</title>
  <style type="text/css">

  </style>
  <meta name="GENERATOR" content="amaya 8.5, see http://www.w3.org/Amaya/" />
  <link href="../style.css" rel="stylesheet" type="text/css" />
</head>

<body xml:lang="ru" lang="ru">

<table border="0" width="100%" summary="toc">
  <tbody>
    <tr>
      <td><img alt="W3C" src="../../images/w3c_home" /> <img alt="Amaya"
        src="../../images/amaya.gif" /></td>
      <td><p align="right"><a href="configuring_icons.html.ru"
        accesskey="p"><img alt="����������" src="../../images/left.gif"
        /></a> <a href="../Annotations.html.ru" accesskey="t"><img
        alt="�����" src="../../images/up.gif" /></a></p>
      </td>
    </tr>
  </tbody>
</table>

<div id="page_body">
<h1>��������� �������� � ����������� � ��������������� ����������</h1>

<p>����� �� ����������� ��������� � ������ ����������� (�.�. � �����������,
��� ���������� ����� ����������), �� ������ ����������� � ����� ����������:
<strong>���������� ���������</strong> � <strong>����������������
���������</strong>. ��� ���������� ���� �������, ������� �� ������ �������
��� Amaya ����������� ��������� � ����������.</p>

<p>Amaya ���������� <strong><a
href="http://www.w3.org/XML/Linking">XPointer</a></strong> ��� ���������
����� � ���������, ���� �� ������ ���������� ���������. XPointers ��������� �
��������� ���������. ��� �������� XPointer ��� ��������� ����� ���������,
Amaya �������� � ������ ����� ���������� � �������� (����� �������) ����� ���
��������� ���������, ���� �� ����� ������ ������ (root) ���������. ����
������� ����� ������� ID, Amaya ������������� �������� XPointer � ���������
������� � ��������� �������� ID, ��� ������ ����� XPointer.</p>

<p>��������, ���� �� �������������� �������� HTML ��� ����� ���������, �� ��
�������� �������� ����� ������� ����������� ��� ������ � �������� ��������
DIV, ������� ����� ������� ID � ��������� ������ "Issues". ���� ��������� ���
����� ��������� ����:</p>
<pre>  &lt;div id="Issues"&gt;

  &lt;h1&gt;�������� � ....&lt;/h1&gt;

  &lt;p&gt;���� �� �����������...&lt;/p&gt;

  &lt;p&gt;Amaya ���������� &lt;strong&gt;XPointer&lt;/strong&gt;...&lt;/p&gt;

  ...

  &lt;/div&gt;</pre>

<p>����� XPointer �� ������ ���������:
<code>xpointer(id("Issues")/p[2])</code></p>

<p>����� �������������� XPointer �� ������ �������� <code>p</code>,
������������� �������� �������� ������� ID � ��������� ������ "Issues".</p>

<p>��������, ��� ������������� �������� ID ��� ����������� ������ ���������
���������� ����� ������ XPointer � ������ ������� � �������� ���������, ���
������������� ���������� XPointer. XPointer �� ������� �� ���������
�������������� ���.</p>

<h2>���������� ���������</h2>

<p>��������� ���������� "����������" ����� ��� ������ ����������� ����
������������ � ���������, �.�., ����� XPointer �� �������� �� � ������
�������� � ��������� ���������. ��� ���������� � ��� ������ ����� ���������
��������� ���� ��������. Amaya ������� ��������� �� ������ ���� ������������
����� ���������� ��������� ��� �������� ������ ��������� � ������� ���������.
��� ���������� ������ ����� � ���� ������ � �������� �������� � ����
����������� ����� ������� �� �������� <img src="../../images/annotorp.png"
alt="������ ���������� ���������" />.</p>

<h2>���������������� ���������</h2>

<p>��������� ��������� "�����������������" ����� ��� ��������� ��
������������ ����� ����������. ��� �������� ���������� ����� �� �����������
����� ������, ������� ����� ���� ���� ��������. � ������� ������, Amaya ��
������������� ������������ � ���, ��� ��������� ������ ��� � �����������. �
������� �������, �������� ����� ���������� ��������� � ���, ��� ���������
������ ��� � �����������.</p>

<h2>��� �� ������ �������, ��� ����������� �����?</h2>

<p>��� ����� ���������, ����������� ������������ ������� <code>ID</code> �
����� ������ ������, ��������, � ��������� <code>&lt;DIV&gt;</code> �
<code>p</code>. ��������:</p>
<pre>  &lt;p id="Amaya"&gt;Amaya uses...&lt;/p&gt;</pre>

<p>����� XPointer � ���� ��������� ����� ��������:
<code>xpointer(id("Amaya"))</code></p>

<p>����� �������, Xpointer ������ �� ��� �� ��������, ���������� �� �����
������� � ��������� ���������.</p>

<p>Amaya ��������� ��� ������������� ������� ��� ������� �������
<code>ID</code> �/�� ������ ���������, ������ ����� <strong>��������/�������
ID</strong> �� ���� <strong>������</strong>.</p>
</div>
</body>
</html>