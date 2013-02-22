#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	int n = 0;
	//Чтение данных из файла
	fscanf(f, "%d", &n);
	int **graph = new int*[n + 1];
	for (int i = 0; i <=n; ++i)
		graph[i] = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			fscanf(f, "%d", &graph[i][j]);
	fclose(f);
	//Алгоритм Прима
	List *verticesOfTree = createList(); 
	List *freeVertices = createList();
	for (int i = n; i > 1; --i)
		addElem(freeVertices->head, i);
	addElem(verticesOfTree->head, 1);
	printf("Edges of minimum spanning tree:\n");
	while (freeVertices->head->next != NULL)
	{
		int minLength = INT_MAX;
		int ind1 = 0;
		int ind2 = 0;
		ListElement *tmp = verticesOfTree->head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			ListElement *tmp1 = freeVertices->head;
			while (tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
				if (graph[tmp->value][tmp1->value] < minLength && graph[tmp->value][tmp1->value] != -1)
				{
					ind1 = tmp->value;
					ind2 = tmp1->value;
					minLength = graph[ind1][ind2];
				}
			}
		}
		addElem(tmp, ind2);
		deleteElem(ind2, freeVertices);
	    printf("%d %d\n", ind1, ind2);
	}
	//Очистка памяти
	deleteList(verticesOfTree);
	deleteList(freeVertices);
	for (int i = 0; i <= n; ++i)
		delete[] graph[i];
	delete graph;
	cin.get();
	return 0;
}