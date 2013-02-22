#include <iostream>
#include "bintree.h"
using namespace std;

Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

TreeNode *createNode(int value)
{
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool exists(TreeNode *root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value > value)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}

void addElem(TreeNode *&node, int value)
{
    if (node == NULL)
    {
        node = createNode(value);
        return;
    }
	if (value < node->value)
        addElem(node->left, value);
    else
        addElem(node->right, value);
}

bool isLeaf(TreeNode *node)
{
	return node->right == NULL && node->left == NULL;
}

bool hasOneChild(TreeNode *node)
{
	return node->right == NULL && node->left != NULL || node->right != NULL && node->left == NULL;
}

TreeNode *mostLeftChild(TreeNode *node)
{
	if (node->left != NULL)
		return mostLeftChild(node->left);
	else
		return node;
}

void deleteElem(TreeNode *&node, int value)
{
    if (node->value > value)
        deleteElem(node->left, value);
    else if (node->value < value)
        deleteElem(node->right, value);
    else if (isLeaf(node))
    {
        delete node;
        node = NULL;
    }
    else if (hasOneChild(node))
    {
        if (node->left != NULL)
        {
            TreeNode *tmp = node->left;
            delete node;
            node = tmp;
        }
        else if (node->right != NULL)
        {
            TreeNode *tmp = node->right;
            delete node;
            node = tmp;
        }
    }
    else
    {
        TreeNode *tmp = mostLeftChild(node->right);
        node->value = tmp->value;
		deleteElem(node->right, tmp->value);
    }
}

void deleteTree(TreeNode *&node)
{
	if (node->left != NULL)
		deleteTree(node->left);
	if (node->right != NULL)
		deleteTree(node->right);
	delete node;
	node = NULL;
}
void deleteTree(Tree *tree)
{
	if (tree->root != NULL)
		deleteTree(tree->root);
	delete tree;
}

void printInOrder(TreeNode *&node)
{
	if (node != NULL)
	{
		if (node->left != NULL)
			printInOrder(node->left);
		printf("%c ", node->value);
		if (node->right != NULL)
			printInOrder(node->right);
	}
}

void printInRevOrder(TreeNode *&node)
{
	if (node != NULL)
	{
		if (node->right != NULL)
			printInRevOrder(node->right);
		printf("%c ", node->value);
		if (node->left != NULL)
			printInRevOrder(node->left);
	}
}

bool isOper(char symbol)
{
	return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

int operation (char oper, int first, int second)
{
	if (oper == '+') 
		return (first + second);
	if (oper == '-') 
		return (first - second);
	if (oper == '*') 
		return (first * second);
	if (oper == '/') 
		return (first / second);
	return NULL;
}

int makeOperTree(TreeNode *&node, char* str, int pos)
{
	char sym = str[pos];
	if (sym == ' ' || sym == '(' || sym == ')')
	{
		++pos;
		return makeOperTree(node, str, pos);
	}
	else
	{
		addElem(node, sym);
	    ++pos;
		if (isOper(sym))
		{
			pos = makeOperTree(node->left, str, pos);
			pos = makeOperTree(node->right, str, pos);
		}
		return pos;
	}
}

void printOperTree(TreeNode *&node)
{
	printf("%c ", node->value);
	if (node->left != NULL)
		if (isOper(node->left->value))
			printOperTree(node->left);
		else
			printf("%c ", node->left->value);
	if (node->right != NULL)
		if (isOper(node->right->value))
			printOperTree(node->right);
		else
			printf("%c ", node->right->value);
}

int countTree(TreeNode *node)
{
	int result = 0;
	if ((node->left == NULL) && (node->right == NULL))
		result = node->value - '0';
	else
		result = operation(node->value, countTree(node->left), countTree(node->right));
	return result;
}