#include "Queue.h"
#include <cstdio>

void Init(Queue* queue)
{
	queue->arr[MAX_SIZE] = { 0, };
	queue->front = 0;
	queue->rear = 0;
}

void Push(Queue* queue, int data)
{
	if (queue->front == (queue->rear + 1) % MAX_SIZE)
	{
		printf("큐가 가득차 있습니다.\n");
	}
	else
	{
		queue->arr[queue->rear] = data;
		queue->rear = (queue->rear + 1) % MAX_SIZE;
	}

	return;
}

int Pop(Queue* queue)
{
	if (queue->front == queue->rear)
	{
		printf("큐가 비어 있습니다.\n");
		return -1;
	}
	else
	{
		int result = queue->arr[queue->front];
		queue->front = (queue->front + 1) % MAX_SIZE;
		return result;
	}
}

int Peek(Queue* queue)
{
	if (queue->front == queue->rear)
	{
		printf("큐가 비어 있습니다.\n");
		return -1;
	}
	else
	{
		return queue->arr[queue->front];
	}
}

void Print(Queue* queue)
{
	for (int i = queue->front; i < queue->rear; ++i)
	{
		printf("Print = [%d].\n", i, queue->arr[i]);
	}
}
