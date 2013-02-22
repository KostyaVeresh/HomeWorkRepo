#pragma once
#include <iostream>
using namespace std;

struct ListElement
{
	char* value;
	int count;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

typedef ListElement* Position;

List *createList();
Position elemPos(char* value, List *list);  //возвращает указатель на элемент списка по его значению
void addElem(Position p, char* value);  //добавл€ет в список новый элемент
void deleteElem(char* value, List *list);   //удал€ет элемент списка по его значению
void printList(List *list);   //выводит на экран список
void deleteList(List *list);  //удал€ет список
bool isEmpty(List *list); //существование списка