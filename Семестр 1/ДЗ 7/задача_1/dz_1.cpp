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
	cout << "���-�� ��������� ������: ";
	cin >> amountOfElements;
	cout << "������: ";
	for (int i = 1; i <= amountOfElements; ++i)
	{
		ElementType value;
		scanf("%d", &value);
		addElement(list, value);
	}
	list = mergeSort(list);
	cout << endl;
	cout << "������������� ������: ";
	printList(list);
	deleteList(list);
	scanf("%*s");
	return 0;
}