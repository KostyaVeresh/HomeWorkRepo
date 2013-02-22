#include <iostream>
#include <string>
#include <clocale>
#include "stack.h"
using namespace std;

int priority(char c)
{
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack* stack = createStack();
	char sym;
	string outStr = "";
	cout << "Введите арифметическое выражение:\n";
	while (cin.get(sym), sym != '\n')
	{
		switch (sym)
		{
			case ' ':
				break;
			case '(':
				push(stack, sym);
				break;
			case ')':
				{
				while (top(stack) != '(')
					outStr = outStr + pop(stack) + ' ';
				pop(stack);
				break;
				}
			case '+':
			case '-':
			case '*':
			case '/':
				{
				while (!isEmpty(stack) && priority(top(stack)) <= priority(sym))
					outStr = outStr + pop(stack) + ' ';
				push(stack, sym);
				break;
				}
			default:
				if (sym >= '0' && sym <= '9')
					outStr = outStr + sym + ' ';
				break;
		}
	}
	while (!isEmpty(stack))
		outStr = outStr + pop(stack) + ' ';
	cout << "Постфиксная запись:\n" << outStr;
	destroy(stack);
	cin.get();
	return 0;
}