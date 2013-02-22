#include <iostream>
#include <string>
using namespace std;

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	int m = 0;
	int n = 0;
	fscanf(f, "%d\n%d\n", &m, &n);
	int **table = new int*[m];
	for (int i = 0; i < m; ++i)
		table[i] = new int[n];
	// Считывание таблицы переходов из файла
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			fscanf(f, "%d", &table[i][j]);
		fscanf(f, "\n");
	}
	fscanf(f, "\n");
	char sym = ' ';
	int state = 0;
	string str = "";
	do
	{
		fscanf(f, "%c", &sym);
		if (sym == '*' || sym == '/')
		{
			int num = 0;
			if (sym == '*')
				num = 1;
			state = table[state][num];
		}
		if (state != 0)
			str = str + sym;
		else
			str = "";
	    if (state == 4)
		{
			printf("%s\n\n", str.c_str());
			state = 0;
			str = "";
		}
	}
	while (!feof(f));
	// Очистка памяти
	for (int i = 0; i < m; ++i)
		delete[] table[i];
	delete table;
	cin.get();
	return 0;
}