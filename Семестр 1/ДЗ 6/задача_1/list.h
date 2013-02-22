#include <iostream>
#pragma once
using namespace std;

struct Item
{
	string str;
	int num;
};

struct ListElement
{
	Item *value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

typedef ListElement* Position;
typedef Item* ListType;

List *createList();
int sizeOfList(List* list);
Position elemPos(ListType value, List *list);  //���������� ��������� �� ������� ������ �� ��� ��������
void addElem(Position p, List *list, ListType value);  //��������� � ������ ����� �������
void deleteElem(ListType value, List *list);   //������� ������� ������ �� ��� ��������
void printList(List *list);   //������� �� ����� ������
void deleteList(List *list);  //������� ������