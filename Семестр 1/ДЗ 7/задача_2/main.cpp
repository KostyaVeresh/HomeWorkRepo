#include <iostream>
#include "bintree.h"
using namespace std;

int main()
{
	Tree *tree = createTree();
	cout << "Number: " << endl;
	cout << "  0 - to exit;" << endl;
	cout << "  1 - to add new element;" << endl;
	cout << "  2 - to delete element;" << endl;
	cout << "  3 - to check element is exist;" << endl;
	cout << "  4 - to print elements in order;" << endl;
	cout << "  5 - to print elements in reverse order;" << endl;
	int num = 0;
	do
	{
		printf("Enter number: ");
		scanf("%d", &num);
		if (num == 1)
		{
			int value = 0;
			printf("  Enter new element: ");
			scanf("%d", &value);
			addElem(tree->root, value);
		}
		if (num == 2)
		{
			int value = 0;
			printf("  Enter element to delete: ");
			scanf("%d", &value);
			deleteElem(tree->root, value);
		}
		if (num == 3)
		{
			int value = 0;
			printf("  Enter element: ");
			scanf("%d", &value);
			if (exists(tree->root, value))
				cout << "Exists" << endl;
			else
				cout << "Doesn't exist" << endl;
		}
		if (num == 4)
		{
			printInOrder(tree->root);
			cout << endl;
		}
		if (num == 5)
		{
			printInRevOrder(tree->root);
			cout << endl;
		}
	}
	while (num != 0);
	deleteTree(tree);
	cin.get();
	return 0;
}