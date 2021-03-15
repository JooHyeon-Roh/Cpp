#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

//배열 동적할당을 위한 자료
//입문자에게는 나중에 추천
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

	//배열 동적할당을 위한 자료
	//입문자에게는 나중에 추천
	//{
	//	int n = 5;
	//	//배열 생성
	//	if (Create(n))
	//	{
	//		//검색
	//		{
	//			int index = 1;
	//			int result = Retrieve(arr, index, n);
	//			if (result > 0)
	//			{
	//				printf("검색 결과 입니다. index[%d]=element[%d]\n\n", index, result);
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


//배열 동적할당을 위한 자료
//입문자에게는 나중에 추천
//bool Create(int n)
//{
//	printf("배열 생성을 생성합니다.\n");
//	if (n <= 0)
//	{
//		printf("배열 사이즈를 재설정해주시기 바랍니다.\n");
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
//		printf("배열 생성에 실패하였습니다.\n");
//		return false;
//	}
//
//	printf("배열 생성에 성공하였습니다.\n");
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
//		printf("인덱스 설정이 잘못되었습니다.\n");
//		return -1;
//	}
//}