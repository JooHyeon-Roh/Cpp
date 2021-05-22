#include <cstdio>
#include <stdlib.h>
#include "BinaryTree.h"

int main()
{
	{
		Tree* tree = new Tree;

		Init(tree);

		Insert(tree, 1);
		Insert(tree, 2);
		Insert(tree, 3);
		Insert(tree, 4);

		Delete(tree);

		PrintData(tree);

		delete tree;
	}

	//{
	//	Tree tree;
	//	Init(&tree);
	//}
	return 0;
}