#include "list.h"
#include <iostream>
using namespace std;

List *createList()
{
	List *list = new List;
	list->head = new ListElement;
	list->head->next = NULL;
	list->head->value = ""; 
	list->head->count = 0;
	return list;
}

Position elemPos(char* value, List *list)
{
	ListElement* tmp = list->head;
	while(strcmp(tmp->value, value) != 0)
		tmp=tmp->next;
	return tmp;
}

void addElem(Position p, char* value)
{
	ListElement* tmp = new ListElement;
	tmp->value = new char[100];
	tmp->value = value;
	tmp->next = p->next;
	p->next = tmp;
}

void deleteElem(char* value, List *list)
{
	ListElement* tmp = list->head;
	while (strcmp(tmp->next->value, value) != 0)
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
		cout << tmp->next->value << " " << tmp->next->count << endl << endl;
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

bool isEmpty(List *list)
{
	return list->head->next == NULL;
}