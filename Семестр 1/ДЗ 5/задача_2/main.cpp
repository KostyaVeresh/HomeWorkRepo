#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List* list = createList();
	int num = 0;
	do
	{
		printf("Enter num: ");
	    scanf("%d", &num);
		if (num == 1)
		{
			int value = 0;
			scanf("%d", &value);
			ListElement *tmp = list->head;
			if (list->head->next == NULL)
				addElem(list->head, list, value);
			else
			{
				while (tmp->next->value < value)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
						break;
				}
			    addElem(tmp, list, value);
			}
		}
		if (num == 2)
		{
			int value = 0;
			scanf("%d", &value);
			deleteElem(value, list);
		}
		if (num == 3)
			printList(list);
	}
	while(num != 0);
	deleteList(list);
	scanf("%*s");
	return 0;
}