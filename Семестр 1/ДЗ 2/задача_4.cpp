#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
	srand(time(0));
	int ar[10];
	for (int i = 0; i < 10; ++i)
	{
		ar[i] = rand()%50 + 1;
		printf("%d ", ar[i]);
	}
	printf("\nResult: ");

	int left = 1;
	int right = 9;
	bool pos = true;
	while (pos)
	{
		while (ar[0] >= ar[left])
			++left;
		while (ar[0] < ar[right])
			--right;
		if (right > left)
		{
			int temp = ar[right];
			ar[right] = ar[left];
			ar[left] = temp;
		}
		else
			pos = false;
	}
	int temp = ar[0];
	ar[0] = ar[left - 1];
	ar[left - 1] = temp;

    for (int i = 0; i < 10; ++i)
	    {
		    printf("%d ", ar[i]);
	    }

	scanf("%*s");
}