#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
	Stack* stack = createStack();
	string str = "";
	char sym = ' ';
	int length = 0;
	printf("Enter string of ()[]{}:\n");
	while (cin.get(sym), sym != '\n')
	{
		str = str + sym;
		++length;
	}
	int i = 0;
	bool fact = true;
	sym = str[i];
	while (fact && i < length)
	{
		if (sym == '(' || sym == '[' || sym == '{')
			push(stack, sym);
		else
		{
			if (!isEmpty(stack))
				switch(sym)
			{
				case ')':
				    fact = top(stack) == '(';
				    break;
			    case ']':
				    fact = top(stack) == '[';
				    break;
			    case '}':
				    fact = top(stack) == '{';
				    break;
		    }
			else
				fact = false;				
		if (fact)
			pop(stack);
		}
		++i;
		sym = str[i];
	}
	if (!fact || !isEmpty(stack))
		cout << "disbalance";
	else
		cout << "balance";
	destroy(stack);
	scanf("%*s");
	return 0;
}