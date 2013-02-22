#include <stdio.h>
#include <string.h>

int main()
{
	int length = 0;
	int counter = 0;
	char* str = new char[100];
	printf("%s", "Enter string:\n");
	scanf("%s", str);
	length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '(') 
			++counter; 
		if (str[i] == ')') 
			--counter; 
		if (counter < 0)
			break;
	}
	if (counter != 0)
		printf("%s", "Error");
	else 
		printf("%s", "All correct");
	scanf("%*s");
}