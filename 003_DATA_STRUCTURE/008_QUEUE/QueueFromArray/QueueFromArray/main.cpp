#include <cstdio>
#include "Queue.h"

int main()
{
	{
		Queue* queue = new Queue;

		Init(queue);

		Push(queue, 1);
		Push(queue, 2);
		Push(queue, 3);
		Push(queue, 4);

		int data = Pop(queue);
		printf("pop = [%d]\n\n", data);

		data = Peek(queue);
		printf("Peek = [%d]\n\n", data);

		Print(queue);

		delete queue;
	}

	//{
	//	Queue queue;
	//	Init(&queue);
	//}
	return 0;
}