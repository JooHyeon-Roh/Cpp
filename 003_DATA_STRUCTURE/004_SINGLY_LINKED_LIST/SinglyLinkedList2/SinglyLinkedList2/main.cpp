#include <cstdio>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main()
{
	{
		List* list = new List;

		Init(list);

		Insert(list, 1);
		Insert(list, 2);
		Insert(list, 3);

		Delete(list, 2);

		Count(list);

		PrintData(list);

		delete list;
	}

	//{
	//	List list;
	//	Init(&list);
	//}
	return 0;
}