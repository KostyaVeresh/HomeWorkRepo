#include <stdio.h>
#include <string.h>
#include <iostream>

char sign(int number)
{
	if (number / abs(number) >= 0)
		return '+';
	else
		return '-';
}

int main()
{
	const int n = 5;
	printf("Enter coefficients:\n");
	int mas[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &mas[i]);
	char* str = new char[100];
	printf("\nPolynomial:\n");
	
	sprintf(str, "%d", mas[0]);
	for (int j = 1; j < strlen(str) + 1; ++j)
		printf(" ");
	printf("%d", n - 1);

    for (int i = 1; i < n - 2; ++i)
	{
		sprintf(str, "%d", abs(mas[i]));
		for (int j = 1; j < strlen(str) + 4; ++j)
			printf(" ");
		printf("%d", n - i - 1);
	}
	printf("\n");

	printf("%d ", mas[0]);
	for (int i = 1; i < n - 1; ++i)
		printf("%c %dx ", sign(mas[i]), abs(mas[i]));
	printf("%c %d", sign(mas[n - 1]), abs(mas[n - 1]));
	scanf("%*s");
	return 0;
}