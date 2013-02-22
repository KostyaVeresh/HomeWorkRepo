#include <stdio.h>
int main()
{
	int x = 0, y = 0, result = 0;
	printf("%s", "Enter x:\n");
	scanf("%d",&x);
	y=x * x;
	result=(y + 1) * (y + x);
	printf("Result:\n");
	printf("%d", result);
	scanf("%*s");
}