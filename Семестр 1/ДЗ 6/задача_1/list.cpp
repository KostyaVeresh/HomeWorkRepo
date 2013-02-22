#include "list.h"
#include <iostream>
#include <string>;

List *createList()
{
	List *list = new List;
	list->head = new ListElement;
	list->head->next = NULL;
	list->head->value = NULL; 
	return list;
}

int sizeOfList(List* list)
{
	int size = 0;
	ListElement *tmp = list->head->next;
	while (tmp != NULL)
	{
		++size;
		tmp = tmp->next;
	}
	return size;
}

Position elemPos(ListType value, List *list)
{
	ListElement* tmp = list->head;
	while(tmp->value != value)
		tmp=tmp->next;
	return tmp;
}

void addElem(Position p, List *list, ListType value)
{
	ListElement* tmp = new ListElement;
	tmp->value = value;
	tmp->next = p->next;
	p->next = tmp;
}

void deleteElem(ListType value, List *list)
{
	ListElement* tmp = list->head;
	while (tmp->next->value != value)
		tmp = tmp->next;
	ListElement *tmp1 = elemPos(value, list);
	tmp->next = tmp1->next;
    delete tmp1;
}

void printList(List *list)
{
	ListElement* tmp = list->head;
	while (tmp->next != NULL)
	{
		cout << tmp->next->value->str << " " << tmp->next->value->num << endl;
		tmp = tmp->next;
	}
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	ListElement *tmp1 = tmp->next;
	while (tmp1 != NULL)
	{
		tmp = tmp1;
		tmp1 = tmp1->next;
		delete tmp;
	}
	delete list->head;
	delete list;
}