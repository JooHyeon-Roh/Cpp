#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
	struct _Node* prev;
}Node;

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));

	if (head != nullptr)
	{
		head->data = 1;
		head->next = nullptr;
		head->prev = nullptr;
	}

	Node* tail = (Node*)malloc(sizeof(Node));

	if (tail != nullptr)
	{
		tail->data = 3;
		tail->next = nullptr;
		tail->prev = head;
		head->next = tail;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != nullptr)
	{
		newNode->data = 2;
		newNode->next = tail;
		newNode->prev = head;
		head->next = newNode;
		tail->prev = newNode;
	}

	printf("head->data = [%d]\n", head->data);
	printf("newNode->data1 = [%d]\n", newNode->data);
	printf("tail->data1 = [%d]\n", tail->data);


	free(head);
	free(tail);
	free(newNode);
	return 0;
}