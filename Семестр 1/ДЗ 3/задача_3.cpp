#include <stdio.h>

void quickSort(int *ar, int begin, int length)
{
	int left = begin;
	int right = length - 1;
	int v = ar[(left + right) / 2];
	do
	{
		while (ar[left] < v)
			++left;
		while (ar[right] > v)
			--right;
		if (left <= right)
		{
			int temp = ar[left];
			ar[left] = ar[right];
			ar[right] = temp;
			++left;
			--right;
		}
	}
	while (left <= right);
	if (begin < right)
		quickSort(ar, begin, right + 1);
	if (left < length)
		quickSort(ar, left, length);
}

int main()
{
	const int length = 10;
	int mas[length];
	printf("Enter array:\n");
	for (int i = 0; i < length; ++i)
		scanf("%d", &mas[i]);
	quickSort(mas, 0, length);
	int counter = 1;
	int max_counter = 1;
	int max = 0;
	for (int i = 1; i < length - 1; ++i)
	{
		if (mas[i] == mas[i + 1])
		    ++counter;
		else
		{
			if (max_counter < counter)
			{
				max_counter = counter;
			    max = mas[i];
			}
			counter = 1;
		}
	}
	if (max_counter < counter)
		{
			max_counter = counter;
		    max = mas[length - 1];
		}
	printf("\nResult: %d", max);		
	scanf("%*s");
	return 0;
}