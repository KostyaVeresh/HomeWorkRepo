#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0; 
	int b = 0; 
	int i = 0;
	printf("%s", "Enter a, b:\n");
	scanf("%d%d",&a,&b,"\n");
	int temp = a * b / abs(a) / abs(b);
	while (abs(a) >= abs(b)) 
	{
		a = abs(a) - abs(b);
		++i;
	}
	i = i * temp;
	printf("%s%d","Result:\n", i);
	scanf("%*s");
}