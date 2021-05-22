#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

static const int MAX_SIZE = 30;

typedef struct _Node
{
	int data;
}Node;

typedef struct _Tree
{
	_Node node[MAX_SIZE];
	int pos;
}Tree;

void Init(Tree* tree);
bool Insert(Tree* tree, int data);
bool InsertLeftChild(Tree* tree, int data, int parentIndex);
bool InsertRightChild(Tree* tree, int data, int parentIndex);

bool Delete(Tree* tree);

void PrintData(Tree* tree);

#endif