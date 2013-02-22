#pragma once

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
};

Tree *createTree();
TreeNode *createNode(int value);
void addElem(TreeNode *&node, int value);
bool isLeaf(TreeNode *node);
bool hasOneChid(TreeNode *node);
TreeNode *mostLeftChild(TreeNode *node);
void deleteElem(TreeNode *&node, int value);
void deleteTree(TreeNode *&node);
void deleteTree(Tree *tree);
void printInOrder(TreeNode *&tree);
void printInRevOrder(TreeNode *&tree);
bool exists(TreeNode *root, int value);