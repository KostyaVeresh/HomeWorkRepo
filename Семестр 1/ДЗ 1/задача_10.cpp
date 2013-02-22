#include <stdio.h>
int main()
{
	const int n = 10;
	int a[n], counter = 0;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; ++i) {
		if (a[i] != 0) {
			++counter;
		}
	}
	printf("%d",counter);
	scanf("%*s");
}