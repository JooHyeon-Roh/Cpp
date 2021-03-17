#pragma once
#ifndef __QUEUE_FROM_ARRAY_H__
#define __QUEUE_FROM_ARRAY_H__

const int MAX_SIZE = 10;

typedef struct _Queue
{
	int arr[MAX_SIZE];
	int front;
	int rear;
}Queue;

void Init(Queue* queue);
void Push(Queue* queue, int data);

int Pop(Queue* queue);
int Peek(Queue* queue);

void Print(Queue* queue);

#endif