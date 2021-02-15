#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int* arr;

bool Create(int n)
{
	printf("배열 생성을 생성합니다.\n");
	if (n <= 0)
	{
		printf("배열 사이즈를 재설정해주시기 바랍니다.\n");
		arr = nullptr;
		return false;
	}

	arr = (int*)malloc(n * sizeof(int));

	if (arr)
	{
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i + 1;
			printf("Create [%d] = [%d]\n", i, arr[i]);
		}
	}
	else
	{
		printf("배열 생성에 실패하였습니다.\n");
		return false;
	}

	printf("배열 생성에 성공하였습니다.\n");
	return true;
}

int Retrieve(int* arr, int i, int n)
{
	if (i > 0 && i < n)
	{
		return arr[i];
	}
	else
	{
		printf("인덱스 설정이 잘못되었습니다.\n");
		return -1;
	}
}

bool Store(int* arr, int i, int item)
{
	if (i > 0)
	{
		int ori = arr[i];
		arr[i] = item;
		printf("배열 요소 변경이 완료되었습니다.[%d]->[%d]\n", ori, arr[i]);
		return true;
	}
	else
	{
		printf("인덱스 설정이 잘못되었습니다.\n");
		return false;
	}
}

bool Insert(int* arr, int i, int item, int n, int & m)
{
	m = n + 1;
	arr = (int*)realloc(arr, m * sizeof(int));	

	if (arr)
	{
		memmove(arr + i + 1, arr + i, (m - i - 1) * sizeof(int));
		arr[i] = item;
	}
	else
	{
		printf("배열 생성에 실패하였습니다.\n");
		return false;
	}

	return true;
}

bool Delete(int* arr, int i, int m, int& n)
{
	memmove(arr + i, arr + i + 1, (m - i) * sizeof(int));

	n = m - 1;
	arr = (int*)realloc(arr, n * sizeof(int));
	if (arr)
	{
		return true;
	}
	else
	{
		printf("배열 생성에 실패하였습니다.\n");
		return false;
	}
}


int main()
{
	printf("START!\n\n");
	int n = 5;

	//배열 생성
	if (Create(n))
	{
		//검색
		int index = 1;
		int result = Retrieve(arr, index, n);
		if (result > 0)
		{
			printf("검색 결과 입니다. index[%d]=element[%d]\n", index, result);
		}
		//변경
		int index2 = 4;
		int item = 10;
		bool result2 = Store(arr, index2, item);
		if (result2)
		{
			for (int i = 0; i < n; ++i)
			{
				printf("Store [%d] = [%d]\n", i, arr[i]);
			}
		}
		//추가
		int index3 = 2;
		int item2 = 20;
		int m = 0;
		if (Insert(arr, index3, item2, n, m))
		{
			for (int i = 0; i < m; ++i)
			{
				printf("Insert [%d] = [%d]\n", i, arr[i]);
			}
		}
		//삭제
		int index4 = 3;
		if (Delete(arr, index4, m, n))
		{
			for (int i = 0; i < n; ++i)
			{
				printf("Delete [%d] = [%d]\n", i, arr[i]);
			}
		}
	}
	else
	{
		return -1;
	}

	printf("END!\n\n");

	free(arr);
	return 0;
}