#include <stdio.h>

int main()
{
	int mas[10];
	printf("%s", "Enter array filled with numbers from 0 to 99:\n");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &mas[i]);
	}
	int ar[100];
	for (int i = 0; i < 100; ++i)
		ar[i] = 0;
	for (int i = 0; i < 10; ++i)
	{
		++ar[mas[i]];
	}
	printf("Sorted array:\n");
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 1; j <= ar[i]; ++j)
			printf("%d ", i);
	}
	scanf("%*s");
	return 0;
}