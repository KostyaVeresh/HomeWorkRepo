#include <stdio.h>

void incertionSort(int ar[], int first, int length)
{
	for (int i = first + 1; i < length; ++i)
	{
		int key = ar[i];
		int j = i - 1;
		while (j >= first + 1 && ar[j] > key)
		{
			ar[j + 1] = ar[j];
			--j;
		}
		ar[j + 1] = key;
	}
}

void quickSort(int ar[], int begin, int length)
{
	int left = begin;
	int right = length;
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
	{
		if (right - begin <= 10)
			incertionSort(ar, begin - 1, right + 1);
		else
			quickSort(ar, begin, right);
	}
	if (left < length)
	{
		if (length - left <= 10)
			incertionSort(ar, left - 1, length + 1);
		else
			quickSort(ar, left, length);
	}
}

int main()
{
	const int length = 10;
	printf("Enter array:\n");
	int mas[length];
	for (int i = 0; i < length; ++i)
		scanf("%d", &mas[i]);
	quickSort(mas, 0, length - 1);
	printf("Sorted array:\n");
	for (int i = 0; i < length; ++i)
		printf("%d ", mas[i]);
	scanf("%*s");
	return 0;
}