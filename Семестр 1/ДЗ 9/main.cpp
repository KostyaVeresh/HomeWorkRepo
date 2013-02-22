#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	//чтение данных из файла
	FILE *f = fopen("newfile.txt", "r");
	int m = 0;
	int n = 0;
	fscanf(f, "%d%d", &n, &m);
	int **graph = new int*[n + 1];
	for (int i = 0; i <= n; ++i)
		graph[i] = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			graph[i][j] = -1;
	for (int i = 0; i < m; ++i)
	{
		int ind1 = 0;
		int ind2 = 0;
		int length = 0;
		fscanf(f, "%d%d%d", &ind1, &ind2, &length);
		graph[ind1][ind2] = length;
		graph[ind2][ind1] = length;
	}
	int k = 0;
	fscanf(f, "%d", &k);
	List **country = new List*[k];
	for (int i = 0; i < k; ++i)
	{
		int value = 0;
		fscanf(f, "%d", &value);
		country[i] = createList();
		addElem(country[i]->head, value);
	}
	fclose(f);
	List *freeTowns = createList(); //список городов, не принадлежащих ни одной столице
	for (int i = 1; i <= n; ++i)
		addElem(freeTowns->head, i);
	for (int i = 0; i < k; ++i)
		deleteElem(country[i]->head->next->value, freeTowns);
	int number = 0;
	while (freeTowns->head->next != NULL)
	{
		//поиск города для присоединения
		int minLength = INT_MAX;
		int ind = 0;
		ListElement *tmp = country[number]->head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			ListElement *tmp1 = freeTowns->head;
			while (tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
				if (graph[tmp->value][tmp1->value] < minLength && graph[tmp->value][tmp1->value] != -1)
				{
					ind = tmp1->value;
					minLength = graph[tmp->value][ind];
				}
			}
		}
		//присоединение города
		addElem(tmp, ind);
		deleteElem(ind, freeTowns);
		++number;
		if (number == k)
			number = 0;
	}
	//вывод получившихся государств
	for (int i = 0; i < k; ++i)
	{
		cout << "Country " << i + 1 << ": ";
		printList(country[i]);
		cout << endl;
	}
	//очистка памяти
	deleteList(freeTowns);
	for (int i = 0; i < k; ++i)
		deleteList(country[i]);
	for (int i = 0; i <= n; ++i)
		delete[] graph[i];
	delete graph;
	cin.get();
	return 0;
}