#include <iostream>
#include "bintree.h"

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
		printf("%d ", node->value);
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
		printf("%d ", node->value);
		if (node->left != NULL)
			printInRevOrder(node->left);
	}
}