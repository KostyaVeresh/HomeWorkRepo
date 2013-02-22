#include "hashtable.h"
#include "list.h"
#include <iostream>
using namespace std;

List** createHasheTable(int hashsize)
{
	List** table = new List*[hashsize];
	for (int i = 0; i < hashsize; ++i)
		table[i] = createList();
	return table;
}

int calculateHash(char* str, int hashsize)
{
	int result = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		result = result + int(str[i]);
	}
	return result % hashsize;
}

void addValue(List** table, char* value, int hashsize)
{
	int key = calculateHash(value, hashsize);
	if (table[key]->head->next == NULL)
	{
		addElem(table[key]->head, value);
		table[key]->head->next->count = 1;
	}
	else
		{
			ListElement *tmp = table[key]->head;
			while (strcmp(tmp->next->value, value) != 0)
			{
				tmp = tmp->next;
				if (tmp->next == NULL)
					break;
			}
			if (tmp->next == NULL)
			{
				addElem(tmp, value);
				tmp->next->count = 1;
			}
			else
				tmp->next->count += 1;
		}
} 

void deleteValue(List** table, char* value, int hashsize)
{
	int key = calculateHash(value, hashsize);
	deleteElem(value, table[key]);
}

void destroyHashTable(List** table, int hashsize)
{
	for (int i = 0; i < hashsize; ++i)
		deleteList(table[i]);
	delete[] table;
}