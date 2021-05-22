#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct _Node
{
	int data;
	_Node* leftChild;
	_Node* rightChild;
}Node;

typedef struct _Tree
{
	_Node* root;
}Tree;

void Init(Tree* tree);
bool Insert(Tree* tree, int data);

bool Delete(Tree* tree);

void PrintData(Tree* tree);

#endif