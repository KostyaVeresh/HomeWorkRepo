#include <stdio.h>

int degree(int a, int b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return degree(a, b - 1) * a;
	else
	{
		int temp = degree(a, b / 2);
		return temp * temp;
	}
}

int main()
{
	int a = 0;
	int b = 0;
	printf("%s", "a^b. Enter a, b\n");
	scanf("%d%d", &a, &b);
	printf("Result: %d", degree(a, b));
	scanf("%*s");
	return 0;
}