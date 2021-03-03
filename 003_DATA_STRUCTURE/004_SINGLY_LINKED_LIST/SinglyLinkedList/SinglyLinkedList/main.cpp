#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

typedef struct _LinkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int dataSize;
	int (*comp)(int d1, int d2);
} LinkedList;

void Init(LinkedList* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = nullptr;
	plist->comp = nullptr;
	plist->dataSize = 0;
}

void InsertFirst(LinkedList* plist, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->dataSize)++;
}

void Insert(LinkedList* plist, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != nullptr &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->dataSize)++;
}

void InsertCheck(LinkedList* plist, int data)
{
	if (plist->comp == nullptr)
		InsertFirst(plist, data);
	else
		Insert(plist, data);
}

bool First(LinkedList* plist, int& pdata)
{
	if (plist->head->next == NULL)
		return false;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	pdata = plist->cur->data;
	return true;
}

bool Next(LinkedList* plist, int& pdata)
{
	if (plist->cur->next == NULL)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	pdata = plist->cur->data;
	return true;
}

int Remove(LinkedList* plist)
{
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->dataSize)--;
	return rdata;
}

int Count(LinkedList* plist)
{
	return plist->dataSize;
}

int main()
{
	LinkedList list;
	int data;
	Init(&list);

	// 5���� ������ ���� /////////////////////////////
	InsertCheck(&list, 11);
	InsertCheck(&list, 11);
	InsertCheck(&list, 22);
	InsertCheck(&list, 22);
	InsertCheck(&list, 33);

	// ����� �������� ��ü ��� /////////////////////////
	printf("���� �������� ��: %d \n", Count(&list));

	if (First(&list, data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (Next(&list, data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� //////////////////////////
	if (First(&list, data))
	{
		if (data == 22)
			Remove(&list);

		while (Next(&list, data))
		{
			if (data == 22)
				Remove(&list);
		}
	}

	// ���� �� �����ִ� ������ ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n", Count(&list));

	if (First(&list, data))
	{
		printf("%d ", data);

		while (Next(&list, data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}