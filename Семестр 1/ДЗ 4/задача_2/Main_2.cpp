#include <stdio.h>
#include "sort.h"

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	const int length = 10;
	int mas[length];
	for (int i = 0; i < length; ++i)
		fscanf(f, "%d", &mas[i]);	
	quickSort(mas, 0, length); // ѕринимает массив, индекс начального элемента и длину интервала, и сортирует элементы массива в переданном интервале
	int counter = 1;
	int maxCounter = 1;
	int max = 0;
	// ¬ отсортированном массиве находим самую длинную последовательность из одинаковых элементов и запоминаем тот элемент, из которого она состоит
	for (int i = 1; i < length - 1; ++i)
	{
		if (mas[i] == mas[i + 1])
		    ++counter;
		else
		{
			if (maxCounter < counter)
			{
				maxCounter = counter;
			    max = mas[i];
			}
			counter = 1;
		}
	}
	if (maxCounter < counter)
		{
			maxCounter = counter;
		    max = mas[length - 1];
		}
	printf("Result: %d", max);	
	fclose(f);
	scanf("%*s");
	return 0;
}