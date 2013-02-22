#include <stdio.h>
#include <iostream>
#include "list.h"

using namespace std;

struct ListElement
{
	ElementType value;
	ListElement *next;
};

struct List
{
	ListElement *head;
	int amount;
};

List* createList()
{
	List *list = new List;
	list->head = NULL;
	list->amount = 0;
	return list;
}

void addElement(List *list, ElementType value)
{
	ListElement *element = new ListElement;
	ListElement *tmp = list->head;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = element;
	}
	else
	{
		list->head = element;
	}
	element->next = NULL;
	element->value = value;
	list->amount++;
}

int returnAmount(List *list)
{
	return list->amount;
}

ElementType returnElement(List *list, int n)
{
	if (list->amount > 0)
	{
		ListElement *tmp = list->head;
		for (int i = 0; i < n; ++i)
			tmp = tmp->next;
		return tmp->value;
	}
	else
	{
		return NULL;
	}
}

List *firstPart(List *list, int number)
{
	List *resultList = createList();
	ListElement *tmp = list->head;
	for (int i = 0; i < number; ++i)
	{
		addElement(resultList, tmp->value);
		tmp = tmp->next;
	}
	return resultList;
}

List *secondPart(List *list, int number)
{
	List *resultList = createList();
	ListElement *tmp = list->head;
	for (int i = 0; i < number; ++i)
	{
		tmp = tmp->next;
	}
	for (int i = number; i < list->amount; ++i)
	{
		addElement(resultList, tmp->value);
		tmp = tmp->next;
	}
	return resultList;
}

void printList(List *list)
{
	setlocale(LC_ALL, "Russian");
	if (list->amount > 0)
	{
		ListElement *tmp = list->head;
		do
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		} while (tmp != NULL);
		cout << endl;
	}
	else
	{
		cout << "Список пуст" << endl;
	}
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	for (int i = 0; i < list->amount; ++i)
	{
		list->head = list->head->next;
		delete tmp;
		tmp = list->head;
	}
	delete list;
}