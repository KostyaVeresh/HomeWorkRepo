#include <stdio.h>
#include <iostream>
#include "list.h"
#include "mergeSort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List *list = createList();
	int amountOfElements = 0;
	cout << "Кол-во элементов списка: ";
	cin >> amountOfElements;
	cout << "Список: ";
	for (int i = 1; i <= amountOfElements; ++i)
	{
		ElementType value;
		scanf("%d", &value);
		addElement(list, value);
	}
	list = mergeSort(list);
	cout << endl;
	cout << "Сортированный список: ";
	printList(list);
	deleteList(list);
	scanf("%*s");
	return 0;
}