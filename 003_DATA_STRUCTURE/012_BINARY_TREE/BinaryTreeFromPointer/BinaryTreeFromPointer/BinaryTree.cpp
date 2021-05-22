#include "BinaryTree.h"
#include <cstdio>
#include <stdlib.h>

void Init(Tree* tree)
{
	tree->root = nullptr;
}

bool Insert(Tree* tree, int data)
{
	if (tree->root == nullptr)
	{
		tree->root = (_Node*)malloc(sizeof(_Node));
	}
	else
	{

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