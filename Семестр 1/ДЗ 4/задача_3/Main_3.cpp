#include <stdio.h>

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	int counter = 0;
	char symbol = ' ';
	bool fact = false;
	// Читаем эл-ты каждой строки; если среди них есть отличные от ' ' и '\t', то увеличиваем счётчик на 1  
	while (fread(&symbol, 1, 1, f))
	{
		if (symbol != ' ' && symbol != '\t' && symbol != '\n')
			fact = true;
		if (symbol == '\n')
		{
			if (fact)
				++counter;
			fact = false;
		}
	}
	printf("%d", counter);
	fclose(f);
	scanf("%*s");
	return 0;
}