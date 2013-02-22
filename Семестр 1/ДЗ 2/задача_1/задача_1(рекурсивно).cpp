#include <stdio.h>

int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 2) + fib(n - 1);
}

int main()
{
	int number = 0;
	printf("%s", "Enter number of Fibonacci numbers:\n");
	scanf("%d", &number);
	for (int i = 1; i <= number; ++i)
	{
		printf("%d ", fib(i));
	}
	scanf("%*s");
}