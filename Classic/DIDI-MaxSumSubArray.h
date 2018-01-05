#ifndef DIDI_MAXSUMSUBARRAY_H_
#define DIDI_MAXSUMSUBARRAY_H_

/*
 * ��Ŀ����
 * һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3
 * ��������:
 * ����Ϊ���С�
 * ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ��
 * �ڶ���Ϊn��������ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���
 * �������:
 * ���������������к�����ֵ��
 *
 * ʾ��
 * ����
 * 3
 * -1 2 1
 *
 * ���
 * 3
 */
#include<iostream>

bool g_InvalidInput = false;

int Solve(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		g_InvalidInput = true;
		return -1;
	}
	int max = 0x80000000;
	int cur = 0;
	for (int i = 0; i < length; ++i) {
		cur += numbers[i];
		if (cur > max) {
			max = cur;
		}
		if (cur < 0) {
			cur = 0;
		}
	}
	return max;
}

void Test() {
	int n = 0;
	std::cin >> n;
	int numbers[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}
	std::cout << Solve(numbers, n);
}


#endif /* DIDI_MAXSUMSUBARRAY_H_ */
