#include <stdio.h>

int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
	{
		int a = 1;
		int b = 1; 
		int c = 0;
		for (int i = 1; i <= n; ++i)
		{
			c = a;
			a = a + b;
			b = c;
		}
		return a;
	}
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