#include "list.h"
#include <stdio.h>

List *createList()
{
	List *list = new List;
	list->head = new ListElement;
	list->head->next = NULL;
	list->head->value = 0; 
	return list;
}

Position elemPos(int value, List *list)
{
	ListElement* tmp = list->head;
	while(tmp->value != value)
		tmp=tmp->next;
	return tmp;
}

void addElem(Position p, List *list, int value)
{
	ListElement* tmp = new ListElement;
	tmp->value = value;
	tmp->next = p->next;
	p->next = tmp;
}

void deleteElem(int value, List *list)
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
		printf("%d ", tmp->next->value);
		tmp = tmp->next;
	}
	printf("\n");
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