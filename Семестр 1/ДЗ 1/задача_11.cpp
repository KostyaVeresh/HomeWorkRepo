#include <stdio.h>
#include <string.h>

int main()
{
	char* str = new char[100];
	printf("%s", "Enter string:\n");
	scanf("%s", str);
	int length = strlen(str);
	int i = 0;
	while (str[i] == str[length - i - 1] && i != length / 2)
	{
		++i;
	}
	if (i == length / 2)
		printf("%s", "Yes");
	else
		printf("%s", "No");
	scanf("%*s");
}