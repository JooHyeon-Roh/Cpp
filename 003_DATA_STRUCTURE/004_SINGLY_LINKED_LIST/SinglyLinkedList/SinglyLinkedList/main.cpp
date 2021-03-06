#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));

	if (head != nullptr)
	{
		head->data = 1;
		head->next = nullptr;
	}

	Node* tail = (Node*)malloc(sizeof(Node));

	if (tail != nullptr)
	{
		tail->data = 3;
		tail->next = nullptr;
		head->next = tail;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != nullptr)
	{
		newNode->data = 2;
		newNode->next = tail;
		head->next = newNode;
	}

	printf("head->data = [%d]\n", head->data);
	printf("newNode->data1 = [%d]\n", newNode->data);
	printf("newNode->data2 = [%d]\n", head->next->data);
	printf("tail->data1 = [%d]\n", tail->data);
	printf("tail->data2 = [%d]\n", head->next->next->data);


	free(head);
	free(tail);
	free(newNode);
	return 0;
}