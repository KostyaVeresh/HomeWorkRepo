#include <stdio.h>
#include <iostream>
#include "listOnArray.h"

using namespace std;

int const numberOfElements = 100;

struct ListElement
{
	ElementType value;
};

struct List
{
	ListElement *element[numberOfElements];
	int amount;
};

List *createList()
{
	List *list = new List;
	list->amount = 0;
	for (int i = 0; i < numberOfElements; ++i)
	{
		list->element[i] = new ListElement;
	}
	return list;
}

void addElement(List *list, ElementType value)
{
	list->element[list->amount]->value = value;
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
		return list->element[n]->value;
	}
	else
	{
		return NULL;
	}
}

List *firstPart(List *list, int number)
{
	List *resultList = createList();
	for (int i = 0; i < number; ++i)
	{
		resultList->element[i]->value = list->element[i]->value;
		resultList->amount++;
	}
	return resultList;
}

List *secondPart(List *list, int number)
{
	List *resultList = createList();
	int ind = 0;
	for (int i = number; i < list->amount; ++i)
	{
		resultList->element[ind++]->value = list->element[i]->value;
		resultList->amount++;
	}
	return resultList;
}

void printList(List *list)
{
	setlocale(LC_ALL, "Russian");
	if (list->amount > 0)
	{
		for (int i = 0; i < list->amount; ++i)
		{
			cout << list->element[i]->value << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Список пуст" << endl;
	}
}

void deleteList(List *list)
{
	for (int i = 0; i < list->amount; ++i)
	{
		delete list->element[i];
	}
	delete list;
}