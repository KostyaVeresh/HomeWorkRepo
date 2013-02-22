#include <stdio.h>
#include <iostream>
#include "list.h"
#include "mergeSort.h"

List *merge(List *list1, List *list2)
{
	ElementType value1;
	ElementType value2;
	int ind1 = 0;
	int ind2 = 0;
	List *newList = createList();
	while (returnAmount(list1) != ind1 && returnAmount(list2) != ind2)
	{
		value1 = returnElement(list1, ind1);
		value2 = returnElement(list2, ind2);
		if (value1 >= value2)
		{
			addElement(newList, value2);
			ind2++;
		}
		else
		{
			addElement(newList, value1);
			ind1++;
		}
	}
	if (returnAmount(list1) == ind1)
	{
		while (returnAmount(list2) != ind2)
		{
			value2 = returnElement(list2, ind2);
			addElement(newList, value2);
			ind2++;
		}
	}
	else
	{
		if (returnAmount(list2) == ind2)
			while (returnAmount(list1) != ind1)
			{
				value1 = returnElement(list1, ind1);
				addElement(newList, value1);
				ind1++;
			}
	}
	deleteList(list1);
	deleteList(list2);
	return newList;
}

List *mergeSort(List *list)
{
	int amount = returnAmount(list);
	if (amount == 0)
		return createList();
	if (amount == 1)
		return list;
	int half = amount / 2;
	List *list1 = createList();
	List *list2 = createList();
	list2 = secondPart(list, half);
	list1 = firstPart(list, half);
	list1 = mergeSort(list1);
	list2 = mergeSort(list2);
	return merge(list1, list2);
}