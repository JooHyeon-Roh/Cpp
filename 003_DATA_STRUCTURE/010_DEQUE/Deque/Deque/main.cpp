#include <cstdio>
#include <stdlib.h>
#include "Deque.h"

int main()
{
	{
		Deque* deque = new Deque;

		Init(deque);

		PushHead(deque, 1);
		PushHead(deque, 2);
		PushHead(deque, 3);
		PushHead(deque, 4);

		int data = PopHead(deque);
		printf("PopHead = [%d]\n\n", data);
		PushTail(deque, 5);
		PushTail(deque, 6);
		PushTail(deque, 7);
		PushTail(deque, 8);

		int data2 = PopTail(deque);
		printf("PopTail = [%d]\n\n", data2);

		Print(deque);

		delete deque;
	}

	//{
	//	Deque deque;
	//	Init(&deque);
	//}
	return 0;
}