#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int result = 1;
	printf("%s","a^b. Enter a,b:\n");
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= b; ++i)
	{
		result = result * a;
	}
	printf("Result: %d", result);
	scanf("%*s");
}