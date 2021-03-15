#include <cstdio>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main()
{
	NodeInfo* nodeInfo = new NodeInfo;

	Init(nodeInfo);

	Insert(nodeInfo, 1);
	Insert(nodeInfo, 2);
	Insert(nodeInfo, 3);

	Delete(nodeInfo, 2);

	Count(nodeInfo);

	PrintData(nodeInfo);

	delete nodeInfo;
	return 0;
}