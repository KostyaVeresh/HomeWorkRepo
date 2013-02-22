#include <stdio.h>
int main()
{
	const int m = 5, n = 3;
	int a[m + n];
	printf("%s%d%s", "Enter array of ", m + n, " numbers:\n");
	for (int i = 0; i < m + n; ++i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int t = a[0];
		for (int j = 1; j < m + n; ++j) {
			a[j - 1]=a[j];
		}
		a[m + n - 1] = t;
	}
	printf("%s", "New array:\n");
	for (int i = 0; i < m + n; ++i){
		printf("%d%s", a[i], " ");
	}
	scanf("%*s");
}