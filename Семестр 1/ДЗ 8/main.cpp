#include <iostream>
#include "list.h"
#include "hashtable.h"
using namespace std;

void printResult(List** table, int hashsize)
{
	for (int i = 0; i < hashsize; ++i)
			if (!isEmpty(table[i]))
				printList(table[i]);
}

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	const int hashsize = 100;
	List **table = createHasheTable(hashsize);
	while (!feof(f))
	{
		char *str = new char[100];
		fscanf(f, "%s", str);
		addValue(table, str, hashsize);
	}
	fclose(f);
	printResult(table, hashsize);
	destroyHashTable(table, 100);
	cin.get();
	return 0;
}