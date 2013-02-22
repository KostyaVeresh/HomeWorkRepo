#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void fillingArray(long *ar, long length)
{
	for (int i = 0; i < length; ++i)
		ar[i] = rand() % 100;
}

void outputArray(long *ar, long length)
{
	for (int i = 0; i < length; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

void quickSort(long *ar, int begin, long length)
{
	long left = begin;
	long right = length - 1;
	long v = ar[(left + right) / 2];
	do
	{
		while (ar[left] < v)
			++left;
		while (ar[right] > v)
			--right;
		if (left <= right)
		{
			long temp = ar[left];
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

bool binSearch(long *ar, long length, long number)
{
	long begin = 0;
	long end = length;
	while (begin < end)
	{
		long v = (begin + end) / 2;
		if (number <= ar[v])
			end = v;
		else
			begin = v + 1;
	}
	return (ar[end] == number);		
}

int main()
{
	srand(time(0));
	long n = 0;
	long k = 0;
	printf("Enter N and K:\n");
	scanf("%d%d", &n, &k);
	long *arrayN = new long[n];
	fillingArray(arrayN, n);
	printf("Array of N elements:\n");
	outputArray(arrayN, n);
	printf("K numbers:\n");
	quickSort(arrayN, 0, n);
	for (int i = 0; i < k; ++i)
	{
		int elemk = rand() % 100;
		printf("%d ", elemk);
		if (binSearch(arrayN, n, elemk))
			printf("Yes\n");
		else
			printf("No\n");
	}
	delete[] arrayN;
	scanf("%*s");
	return 0;
}