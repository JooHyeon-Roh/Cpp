#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

Node* Init(int data = 0)
{
	printf("Node 초기화 시작!\n");
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (pNode == nullptr)
	{
		printf("Node 초기화 실패!\n");
		return nullptr;
	}

	pNode->data = data;
	pNode->next = nullptr;
	printf("Node 초기화 성공!\n");
	return pNode;
}

bool IsEmpty(Node* pNode)
{
	if (pNode == nullptr)
	{
		printf("Node가 비어 있습니다!\n");
		return true;
	}

	printf("Node가 비어 있지 않습니다!\n");
	return false;
}

int GetSize(Node* pNode)
{
	int count = 0;
	Node* chkNode = (Node*)malloc(sizeof(Node));

	if (chkNode == nullptr)
	{
		printf("사이즈 체크에 필요한 Node 생성에 실패하였습니다.\n");
		count = -1;
	}
	else
	{
		chkNode = pNode;
		if (chkNode != nullptr)
		{
			++count;
			while (chkNode->next != nullptr)
			{
				++count;
				chkNode = chkNode->next;
			}
		}
	}

	free(chkNode);
	return count;
}

Node* InsertFirst(Node* pNode, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == nullptr)
	{
		printf("데이터 추가 실패!\n");
		return nullptr;
	}
	else
	{
		newNode->data = data;
		newNode->next = pNode;
	}

	return newNode;
}

Node* Insert(Node* pNode, Node* pNodePrev, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == nullptr)
	{
		printf("데이터 추가 실패!\n");
		return nullptr;
	}
	else
	{
		newNode->data = data;
		newNode->next = pNodePrev;
		pNode->next = newNode;
	}

	return newNode;
}

Node* Delete(Node* pNode, Node* pNodePrev)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == nullptr)
	{
		printf("데이터 추가 실패!\n");
		return nullptr;
	}
	else
	{
		newNode = pNodePrev;
		newNode->next = pNode->next;
	}

	return newNode;
}

void PrintList(Node* pNode)
{

	int count = 0;
	Node* printNode = (Node*)malloc(sizeof(Node));
	if (printNode != nullptr)
	{
		printNode = pNode;
		if (printNode != nullptr)
		{
			++count;
			printf("Node[%d] -> data[%d]\n", count, printNode->data);
			while (printNode->next != nullptr)
			{
				++count;
				printNode = printNode->next;
				printf("Node[%d] -> data[%d]\n", count, printNode->data);
			}
			printf("\n");
		}
	}
	
	return;
}

int main()
{
	Node* node1;
	int nodeData = 2;
	node1 = Init(nodeData);
	PrintList(node1);
	int nodeData2 = 1;
	node1 = InsertFirst(node1, nodeData2);
	PrintList(node1);

	Node* node2 = node1->next;

	int nodeData3 = 3;
	Node* node3;
	node3 = Insert(node1, node2, nodeData3);
	PrintList(node1);

	node1 = Delete(node3, node1);
	PrintList(node1);

	int nodeSize = GetSize(node1);
	printf("전체 Node의 크기 = [%d]\n", nodeSize);

	free(node1);
	return 0;
}