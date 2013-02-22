#pragma once;

struct StackElement 
{
	char value;
	StackElement *next;
};

struct Stack 
{
	StackElement* head;
};

Stack *createStack();
void destroy(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack, char value);
char top(Stack *stack);
char pop(Stack *stack);