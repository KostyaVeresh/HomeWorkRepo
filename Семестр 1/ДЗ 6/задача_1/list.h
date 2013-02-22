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
Position elemPos(ListType value, List *list);  //возвращает указатель на элемент списка по его значению
void addElem(Position p, List *list, ListType value);  //добавляет в список новый элемент
void deleteElem(ListType value, List *list);   //удаляет элемент списка по его значению
void printList(List *list);   //выводит на экран список
void deleteList(List *list);  //удаляет список