#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

typedef ListElement* Position;

List *createList();
Position elemPos(int value, List *list);  //возвращает указатель на элемент списка по его значению
void addElem(Position p, int value);  //добавляет в список новый элемент
void deleteElem(int value, List *list);   //удаляет элемент списка по его значению
void printList(List *list);   //выводит на экран список
void deleteList(List *list);  //удаляет список