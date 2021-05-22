#include "BinaryTree.h"
#include <cstdio>
#include <stdlib.h>

void Init(Tree* tree)
{
	tree->node[MAX_SIZE] = { 0, };
	tree->pos = 0;
}

bool Insert(Tree* tree, int data)
{
	if (tree->pos == MAX_SIZE)
	{
		return false;
	}

	tree->node[tree->pos].data = data;
	++(tree->pos);

	return true;
}


bool InsertLeftChild(Tree* tree, int data, int parentIndex)
{
	if (tree->pos == MAX_SIZE)
	{
		return false;
	}

	tree->node[parentIndex * 2 + 1].data = data;
	if (tree->pos < parentIndex * 2 + 1)
	{
		tree->pos = parentIndex * 2 + 1;
	}

	return true;
}

bool InsertRightChild(Tree* tree, int data, int parentIndex)
{
	if (tree->pos == MAX_SIZE)
	{
		return false;
	}

	tree->node[parentIndex * 2 + 2].data = data;
	if (tree->pos < parentIndex * 2 + 2)
	{
		tree->pos = parentIndex * 2 + 2;
	}

	return true;
}

bool Delete(Tree* tree)
{
	if (tree->pos <= 0)
	{
		return false;
	}

	tree->node[tree->pos].data = 0;
	--(tree->pos);

	return true;
}

void PrintData(Tree* tree)
{
	for (int i = 0; i < tree->pos; ++i)
	{
		printf("[%d] = [%d]\n", i, tree->node[i]);
	}
}