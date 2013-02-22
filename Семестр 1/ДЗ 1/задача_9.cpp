#include <stdio.h>

int main()
{
	int number = 0;
	printf("%s","Enter number:\n");
	scanf("%d", &number);
	for (int i = 2; i <= number; ++i) {
		int devider = 1; 
		int temp = 1;
		while (temp != 0) 
		{
			++devider;
			temp = i % devider;
		}
		if (devider == i) 
		{ 
			printf("%d%s", i, " "); 
		} 
	}
	scanf("%*s");
}