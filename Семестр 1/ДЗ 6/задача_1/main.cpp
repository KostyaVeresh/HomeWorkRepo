#include <iostream>
#include <string>
#include "list.h"
using namespace std;

string readString(string str, FILE *f)
{
	char sym = ' ';
	fscanf(f, "%c", &sym);
	while (sym != ' ' && sym != '\n' && sym != EOF)
	{
		str = str + sym;
		fscanf(f, "%c", &sym);
	}
	return str;
}

bool compare(int num1, int num2)
{
	return num1 <= num2;
}

bool compare(string str1, string str2)
{
	return str1 <= str2;	
}

List* merge(List *list1, List *list2, char key)
{
	List* result = createList();
	ListElement *tmp = result->head;
	while (list1->head->next != NULL && list2->head->next != NULL)
	{
		bool comp = false;
		if (key == 's')
			comp = compare(list1->head->next->value->str, list2->head->next->value->str);
		else
			comp = compare(list1->head->next->value->num, list2->head->next->value->num);
		if (comp)
		{
			addElem(tmp, result, list1->head->next->value);
			tmp = tmp->next;
			deleteElem(list1->head->next->value, list1);
		}
		else
		{
			addElem(tmp, result, list2->head->next->value);
			tmp = tmp->next;
			deleteElem(list2->head->next->value, list2);
		}
	}
	if (list1->head->next != NULL)
	{
		ListElement *tmp1 = list1->head->next;
		while (tmp1 != NULL)
		{
			addElem(tmp, result, tmp1->value);
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
	}
	if (list2->head->next != NULL)
	{
		ListElement *tmp1 = list2->head->next;
		while (tmp1 != NULL)
		{
			addElem(tmp, result, tmp1->value);
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
	}
	deleteList(list1);
	deleteList(list2);
	return result;	
}

List* mergeSort(List* list, char key)
{
	int size = sizeOfList(list); 
	if (sizeOfList(list) <= 1)
	{
		return list;
	}
	else
	{
		int middle = sizeOfList(list) / 2;
		List *list1 = createList();
		List *list2 = createList();
		List *result = createList();
		ListElement *tmp = list->head->next;
		ListElement *tmp1 = list1->head;
		ListElement *tmp2 = list2->head;
		for (int i = 1; i <= middle; ++i)
		{
			addElem(tmp1, list1, tmp->value);
			tmp1 = tmp1->next;
			tmp = tmp->next;
		}
		for (int i = middle + 1; i <= sizeOfList(list); ++i)
		{
			addElem(tmp2, list2, tmp->value);
			tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		list1 = mergeSort(list1, key);
		list2 = mergeSort(list2, key);
		result = merge(list1, list2, key);
		return result;
	}
}


int main()
{
	FILE *f = fopen("newfile.txt", "r");
	List *list = createList();
	ListElement *tmp = list->head;
	int size = 0;
	while (!feof(f))
	{
		string str = "";
		str = readString(str, f);
		int number = 0;
		fscanf(f, " %d\n", &number);
		Item* elem = new Item;
		elem->str = str;
		elem->num = number;
		addElem(tmp, list, elem);
		++size;
		tmp = tmp->next;
	}
	printList(list);
	char sym = ' ';
	cout << endl << "Enter:" << endl << "  n - to sort list by numbers;" << endl << "  s - to sort list by strings;" << endl;
	cin >> sym;
	List* result = mergeSort(list, sym);
	printList(result);
	deleteList(list);
	deleteList(result);
	fclose(f);
	scanf("%*s");
	return 0;
}