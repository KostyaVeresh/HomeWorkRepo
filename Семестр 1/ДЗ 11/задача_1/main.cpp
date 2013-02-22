#include <iostream>
using namespace std;

bool isCorrect(char *str)
{
	int state = 0;
	for(int i = 0; i < strlen(str); ++i)
	{
		char sym = str[i];
		if (sym == ' ')
			continue;
		switch (state)
		{
		case 0:
			if (isdigit(sym))
			{
				state = 1;
			    break;
			}
			else
				return false;
		case 1:
			if (sym == '.')
			{
				state = 2;
				break;
			}
			else
				if (sym == 'E')
				{
					state = 4;
					break;
				}
				else
					return false;
		case 2:
			if (isdigit(sym))
			{
				state = 3;
				break;
			}
			else
				return false;
		case 3:
			if (sym == 'E')
			{
				state = 4;
				break;
			}
			else
				return false;
		case 4:
			if (sym == '+' || sym == '-')
			{
				state = 5;
				break;
			}
			else
				if (isdigit(sym))
				{
					state = 6;
					break;
				}
				else
					return false;
		case 5:
			if (isdigit(sym))
			{
				state = 6;
				break;
			}
			else
				return false;
		case 6:
			return false;
		}
	}
	if (state == 1 || state == 3 || state == 6)
		return true;
	else
		return false;
}
int main()
{
	char *str = new char[10];
	cout << "Enter number: ";
	scanf("%s", str);
	if (isCorrect(str))
		cout << "yes";
	else 
		cout << "no";
	delete[] str;
	cin.get();
	cin.get();
	return 0;
}