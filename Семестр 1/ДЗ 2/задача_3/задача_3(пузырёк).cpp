#include <stdio.h>

void bubbleSort(int mas[], int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (mas[j] > mas[j + 1]) {
				int t = mas[j];
	            mas[j] = mas[j + 1];
	            mas[j + 1] = t;
			}
		}
	}
}

int main()
{
	printf("Enter array:\n");
	const int length = 10;
	int mas[length];
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &mas[i]);
	}
	bubbleSort(mas, 10);
	printf("Sorted array:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", mas[i]);
	}
	scanf("%*s");
	return 0;
}