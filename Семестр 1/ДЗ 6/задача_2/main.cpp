#include <iostream>
#include "stack.h"
using namespace std;

void stackMachine(Stack *stack)
{
	char sym = ' ';
	while (cin.get(sym), sym != '\n')
	{
		switch (sym)
		{
		case '+':
			{
				int op1 = pop(stack);
				int op2 = pop(stack);
				int result = op2 + op1;
				push(stack, result);
			}
			break;
		case '-':
			{
				int op1 = pop(stack);
				int op2 = pop(stack);
			    int result = op2 - op1;
				push(stack, result);
			}
			break;
		case '*':
			{
				int op1 = pop(stack);
				int op2 = pop(stack);
				int result = op2 * op1;
				push(stack, result);
			}
			break;
		case '/':
			{
				int op1 = pop(stack);
				int op2 = pop(stack);
				int result = op2 / op1;
				push(stack, result);
			}
			break;
		case ' ':
			break;
		default:
			push(stack, sym - '0');
		}
	}
}
int main()
{
	Stack* stack = createStack();
	stackMachine(stack);
	cout << top(stack);
	destroy(stack);
	scanf("%*s");
	return 0;
}