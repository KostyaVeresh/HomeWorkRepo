#include <stdio.h>
#include <string.h>

int main()
{
	int counter = 0;
	char* s = new char[100];
	char* s1 = new char[100];
	printf("%s", "Enter strings:\n");
	scanf("%s%s", s, s1);
	int length = strlen(s);
	int length1 = strlen(s1);
	for (int i = 0; i < length - length1 + 1; ++i)
	{
		int index = i;
		for (int j = 0; j < length1; ++j)
		{
			if (s[index] != s1[j])
				break;
			++index;
			if (j == length1 - 1)
				++counter;
		}
	}
	printf("%s%d", "Result: ", counter);
	scanf("%*s");
}