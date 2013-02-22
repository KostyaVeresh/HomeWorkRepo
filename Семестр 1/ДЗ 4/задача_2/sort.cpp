#include "sort.h"

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