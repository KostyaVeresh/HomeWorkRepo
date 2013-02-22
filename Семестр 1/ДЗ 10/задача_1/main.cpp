#include <iostream>
using namespace std;

int countHash(char *str, int length)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result += str[i];
	}
	return result % 100;
}

int RabinKarp(char *str, char *str1)
{
	int hStr = countHash(str, strlen(str1));
	int hStr1 = countHash(str1, strlen(str1));
	for (int i = 0; i < strlen(str) - strlen(str1) + 1; ++i)
	{
		if (hStr == hStr1)
		{
			bool fact = true;
			for (int j = i; j < i + strlen(str1); ++j)
			if (str[j] != str1[j - i])
			{
				fact = false;
				break;
			}
		if (fact)
			return i;
		}
		hStr = (hStr + int(str[strlen(str1) + i]) - int(str[i])) % 100;
	}
	return -1;
}

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	char *str = new char[100];
	char *str1 = new char[100];
	fscanf(f, "%s", str);
	fclose(f);
	printf("Enter string to find: ");
	scanf("%s", str1);
	int point = RabinKarp(str, str1);
	if (point == -1)
		printf("Not found");
	else
		printf("position of string: %d", point + 1);
	cin.get();
	cin.get();
	return 0;
}