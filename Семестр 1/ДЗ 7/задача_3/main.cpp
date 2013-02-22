#include <iostream>
#include "bintree.h"
using namespace std;

int main()
{
	FILE *f = fopen("newfile.txt", "r");
	char *str = new char[100];
	int i = 0;
	char sym = ' ';
	while (!feof(f))
	{
		fscanf(f, "%c", &sym);
		str[i] = sym;
		++i;		
	}
	fclose(f);
	Tree *tree = createTree();
	makeOperTree(tree->root, str, 0);
	printOperTree(tree->root);
	int result = countTree(tree->root);
	printf("\nResult: %d", result);
	cin.get();
	return 0;
}
