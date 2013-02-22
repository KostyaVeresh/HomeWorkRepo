#include <iostream>
#include <string>
using namespace std;

struct Item {
	int phone;
	string str;
};

string readString(FILE* f, string str)  //чтение строки из файла до \n или конца файла
{
	char sym = ' ';
	fscanf(f, "%c", &sym);
	while (sym != '\n' && !feof(f))
	{
		str = str + sym;
		fscanf(f, "%c", &sym);		
	}
	return str;
}

int main()
{
	FILE *f = fopen("newfile.txt", "a+");
	const int length = 150;
	Item arrayOfItems[length];
	int counter = 0;
	int fcounter = 0;
	while (!feof(f))
		{
			fscanf(f, "%d " , &arrayOfItems[fcounter].phone);
			arrayOfItems[fcounter].str = readString(f, arrayOfItems[fcounter].str);
			++fcounter;
		}
	--fcounter;
	counter = fcounter;
	cout << "Number:" << endl;
	cout << "  0 - to exit;" << endl;
	cout << "  1 - to add new item;" << endl;
	cout << "  2 - to find phone number by name;" << endl;
	cout << "  3 - to find name by phone number;" << endl;
	cout << "  4 - to save new items in file;" << endl;
	int num = 0;
	do
	{
		printf("Enter number:\n");
		scanf("%d", &num);
		if (num == 1)
		{
			++counter;
			printf("Enter new phone and name:\n");
			cin >> arrayOfItems[counter].phone >> arrayOfItems[counter].str;
		}
		if (num == 2)
		{
			string name = " ";
			printf("Enter name: ");
			cin >> name;
			int i = 0;
			while (name != arrayOfItems[i].str)
				++i;
			printf("phone: %d\n", arrayOfItems[i].phone);
		}
		if(num == 3)
		{
			int number = 0;
			printf("Enter phone: ");
			scanf("%d", &number);
			int i = 0;
			while (number != arrayOfItems[i].phone)
				++i;
			cout << "name: " << arrayOfItems[i].str << endl;
		}
		if (num == 4)
			if (counter > fcounter)
			{
				for (int i = fcounter + 1; i <= counter; ++i)
					fprintf(f, "%d %s\n", arrayOfItems[i].phone, arrayOfItems[i].str.c_str());
				fcounter = counter;
				printf("New items were saved in file\n");
			}
			else
				printf("There are no new items\n");
	}
	while (num != 0);
	fclose(f);
	scanf("%*s");
	return 0;
}