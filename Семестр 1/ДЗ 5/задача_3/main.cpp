#include <stdio.h>
#include "list.h"

int main()
{
	int n = 0;
	int m = 0;
	int k = 0;
	printf("Enter n,m:\n");
	scanf("%d%d", &n, &m);
	List *list = createList();
	ListElement *tmp = list->head;
	//��������� ������ �������� ������
	for (int i = 1; i <= n; ++i)
	{
		addElem(tmp, list, i);
		tmp = tmp->next;
	}
	tmp = list->head->next;
	while (list->head->next->next != NULL)
	{
		//������� �����, ������� ����� �������
		for (int i = 1; i < m; ++i)
		{
			if (tmp == NULL)
				tmp = list->head->next;
			else
				if (tmp->next == NULL)
					tmp = list->head->next;
				else
					tmp = tmp->next;
		}
		//������� ��������� �� ��� �����
		ListElement *tmp1 = new ListElement;
		if (tmp->next == NULL)
			tmp1 = list->head->next;
		else
			tmp1 = tmp->next;
		int value = tmp->value;
		//������� �����
		deleteElem(value, list);
		tmp = tmp1;		
	}
	k = list->head->next->value;
	printf("k = %d", k);
	deleteList(list);
	scanf("%*s");
	return 0;
}