#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

//�迭 �����Ҵ��� ���� �ڷ�
//�Թ��ڿ��Դ� ���߿� ��õ
//int* arr;

void InsertData(int* arr)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		arr[i] = i;
	}

	return;
}

void printfAll(int* arr)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		printf("[%d] = [%d]\n", i, arr[i]);
	}

	return;
}

void PrintValue(int* arr, int pos)
{
	printf("[%d] = [%d]\n", pos, arr[pos]);
	return;
}

int main()
{
	printf("START!\n\n");
	int arr[MAX_SIZE] = { 0, };

	InsertData(arr);
	printfAll(arr);
	PrintValue(arr, 3);

	//�迭 �����Ҵ��� ���� �ڷ�
	//�Թ��ڿ��Դ� ���߿� ��õ
	//{
	//	int n = 5;
	//	//�迭 ����
	//	if (Create(n))
	//	{
	//		//�˻�
	//		{
	//			int index = 1;
	//			int result = Retrieve(arr, index, n);
	//			if (result > 0)
	//			{
	//				printf("�˻� ��� �Դϴ�. index[%d]=element[%d]\n\n", index, result);
	//			}
	//		}
	//	}
	//	else
	//	{
	//		return -1;
	//	}
	//}
	//free(arr);

	printf("END!\n\n");

	return 0;
}


//�迭 �����Ҵ��� ���� �ڷ�
//�Թ��ڿ��Դ� ���߿� ��õ
//bool Create(int n)
//{
//	printf("�迭 ������ �����մϴ�.\n");
//	if (n <= 0)
//	{
//		printf("�迭 ����� �缳�����ֽñ� �ٶ��ϴ�.\n");
//		arr = nullptr;
//		return false;
//	}
//
//	arr = (int*)malloc(n * sizeof(int));
//
//	if (arr)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			arr[i] = i + 1;
//			printf("Create [%d] = [%d]\n", i, arr[i]);
//		}
//	}
//	else
//	{
//		printf("�迭 ������ �����Ͽ����ϴ�.\n");
//		return false;
//	}
//
//	printf("�迭 ������ �����Ͽ����ϴ�.\n");
//	return true;
//}
//
//int Retrieve(int* arr, int i, int n)
//{
//	if (i > 0 && i < n)
//	{
//		return arr[i];
//	}
//	else
//	{
//		printf("�ε��� ������ �߸��Ǿ����ϴ�.\n");
//		return -1;
//	}
//}