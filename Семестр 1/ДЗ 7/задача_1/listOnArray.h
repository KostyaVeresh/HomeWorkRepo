#pragma once

typedef int ElementType;

struct List;

struct ListElement;


List *createList(); // ������� ������
void addElement(List *list, ElementType value); // ��������� ������� � ����� ������
int returnAmount(List *list); // ���������� ����� ������
ElementType returnElement(List *list, int n); // ���������� �������� n-��� �������� ������ 
List *firstPart(List *list, int number); // ���������� ������ � ������� �������� �� ������
List *secondPart(List *list, int number); // ���������� ������ � ������ �� ����� ������
void printList(List *list); // ������� ������ �� �����
void deleteList(List *list); // ������� ������