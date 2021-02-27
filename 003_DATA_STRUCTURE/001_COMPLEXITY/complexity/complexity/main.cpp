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
	//	//�ð� ���⵵�� O(1), ���� ���⵵ O(1)
	//	int n = 0;
	//	int* p = &n;
	//	printf("%d\n", n);
	//	printf("%p\n", p);
	//	n = n + 1;
	//	printf("%d\n", n);
	//	printf("%p\n", p);
	//}

	//{
	//	//�ð� ���⵵�� O(n), ���� ���⵵ O(1), �ݺ��� ���� �ڵ�� O(1)��� ����
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
	//	//�ð� ���⵵�� O(n��), ���� ���⵵ O(1), �ݺ��� ���� �ڵ�� O(1)��� ����
	//	//2 �� for ���� n �� k�� ����ɽ� O(n^k) �ð� ���⵵�� ���´�
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
	//	//�ð� ���⵵�� O(n), ���� ���⵵ O(1)
	//	int num = 5;
	//	int result = 0;

	//	result = FactorialFor(num);
	//	printf("result = [%d]\n", result);
	//}

	//{
	//	//�ð� ���⵵�� O(n), ���� ���⵵ O(n)
	//	int num = 5;
	//	int result = 0;

	//	result = FactorialRec(num);
	//	printf("result = [%d]\n", result);
	//}

	//��ó�� �츮��
	//factorial(5) �� �ҷ����ϴ�.
	//�׸��� 5�� 1�� �ƴϱ� ������ ù��° if (num <= 1)�� ����ϰ��� ?
	//
	//
	//�׸����� return 5 * factorial(4); �� �ҷ��ݴϴ�.������ �Ҷ� �Լ��� �� ȣ���� �Ǿ��� ������ ���� ��ȯ�� ���� �ʰ�, ���ÿ� �ӹɷ� �ֽ��ϴ�.
	//factorial(4)�� �Ҹ��� ���� ������ ������� -> return 4 * factorial(3);
	//factorial(3)�� �Ҹ��� ���� ������ ������� -> return 3 * factorial(2);
	//factorial(2)�� �Ҹ��� ���� ������ ������� -> return 2 * factorial(1);
	//factorial(1)�� �Ҹ���, ���� ù��° if���� if (num <= 1)�� �ɷ��� return 1 �� �ϰ� �˴ϴ�.
	//
	//
	//�������� ������ �ʴ°� �Ųٷ� �ö󰡰��� ? ������ �������� �Ʒ��� �����ϴ�.
	//factorial(5) = 5 * factorial(4);
	//factorial(5) = 5 * 4 * factorial(3);
	//factorial(5) = 5 * 4 * 3 * factorial(2);
	//factorial(5) = 5 * 4 * 3 * 2 * factorial(1);
	//�̷�������� ġȯ�� �ȰŰ��� ? factorial(1) = 1 �� ���������̱� ������ �� ȣ���� ���� ���� �ǰ�.
	//
	//
	//�Լ��� �Ʒ��������� �ϳ��� �ϳ��� ���ᰡ �˴ϴ�.
	//factorial(1) = 1  �� ��ȯ�ϸ鼭 ����
	//factorial(2) = 2 * 1 = 2  �� ��ȯ�ϸ鼭 ����
	//factorial(3) = 3 * 2 = 6  �� ��ȯ�ϸ鼭 ����
	//factorial(4) = 4 * 6 = 24 �� ��ȯ�ϸ鼭 ����
	//factorial(5) = 5 * 24 = 120 �� ��ȯ�ϸ鼭 ���� ����.


	return 0;
}