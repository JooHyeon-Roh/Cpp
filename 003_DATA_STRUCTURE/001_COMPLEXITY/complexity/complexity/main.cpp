#include <cstdio>

int FactorialFor(int num)
{
	int result = 1;

	for (int i = 1; i <= num; ++i)
	{
		result = result * i;
		int* p = &result;
		printf("%p\n", p);
	}
	return result;
}

int FactorialRec(int num)
{
	int* p = &num;
	printf("%p\n", p);
	if (num <= 1) return 1;

	return num * FactorialRec(num - 1);
}

int main()
{
	//// Time Complexity
	//{
	//	//시간 복잡도는 O(1), 공간 복잡도 O(1)
	//	int n = 0;
	//	int* p = &n;
	//	printf("%d\n", n);
	//	printf("%p\n", p);
	//	n = n + 1;
	//	printf("%d\n", n);
	//	printf("%p\n", p);
	//}

	//{
	//	//시간 복잡도는 O(n), 공간 복잡도 O(1), 반복문 안의 코드는 O(1)라고 가정
	//	int n = 10;
	//	int result = 0;
	//	for (int i = 0; i < n; ++i)
	//	{
	//		result = result + i;
	//		int* p = &result;
	//		printf("i = [%d], result = [%d]\n", i, result);
	//		printf("%p\n", p);
	//	}
	//}

	//{
	//	//시간 복잡도는 O(n²), 공간 복잡도 O(1), 반복문 안의 코드는 O(1)라고 가정
	//	//2 중 for 문중 n 이 k로 변경될시 O(n^k) 시간 복잡도를 갖는다
	//	int n = 10;
	//	int result = 0;
	//	for (int i = 0; i < n; ++i)
	//	{
	//		for (int j = 0; j < n; ++j) 
	//		{
	//			result = result + j;
	//			int* p = &result;
	//			printf("i = [%d], j = [%d], result = [%d]\n", i, j, result);
	//			printf("%p\n", p);
	//		}
	//	}
	//}


	//{
	//	//시간 복잡도는 O(n), 공간 복잡도 O(1)
	//	int num = 5;
	//	int result = 0;

	//	result = FactorialFor(num);
	//	printf("result = [%d]\n", result);
	//}

	//{
	//	//시간 복잡도는 O(n), 공간 복잡도 O(n)
	//	int num = 5;
	//	int result = 0;

	//	result = FactorialRec(num);
	//	printf("result = [%d]\n", result);
	//}

	//맨처음 우리는
	//factorial(5) 를 불렀습니다.
	//그리고 5는 1이 아니기 때문에 첫번째 if (num <= 1)는 통과하겠죠 ?
	//
	//
	//그리고나서 return 5 * factorial(4); 를 불러줍니다.리턴을 할때 함수가 또 호출이 되었기 때문에 아직 반환이 되지 않고, 스택에 머믈러 있습니다.
	//factorial(4)가 불리면 위와 동일한 방식으로 -> return 4 * factorial(3);
	//factorial(3)가 불리면 위와 동일한 방식으로 -> return 3 * factorial(2);
	//factorial(2)가 불리면 위와 동일한 방식으로 -> return 2 * factorial(1);
	//factorial(1)이 불리면, 이제 첫번째 if문인 if (num <= 1)에 걸려서 return 1 을 하게 됩니다.
	//
	//
	//이제까지 계산되지 않는걸 거꾸로 올라가겠죠 ? 계산되지 않은식은 아래와 같습니다.
	//factorial(5) = 5 * factorial(4);
	//factorial(5) = 5 * 4 * factorial(3);
	//factorial(5) = 5 * 4 * 3 * factorial(2);
	//factorial(5) = 5 * 4 * 3 * 2 * factorial(1);
	//이런방식으로 치환이 된거겠죠 ? factorial(1) = 1 이 종료조건이기 때문에 이 호출은 끝이 나게 되고.
	//
	//
	//함수가 아래에서부터 하나씩 하나씩 종료가 됩니다.
	//factorial(1) = 1  을 반환하면서 종료
	//factorial(2) = 2 * 1 = 2  를 반환하면서 종료
	//factorial(3) = 3 * 2 = 6  을 반환하면서 종료
	//factorial(4) = 4 * 6 = 24 를 반환하면서 종료
	//factorial(5) = 5 * 24 = 120 을 반환하면서 완전 종료.


	return 0;
}