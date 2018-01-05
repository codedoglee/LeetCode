#ifndef DIDI_NUMBEROFTAILZERO_H_
#define DIDI_NUMBEROFTAILZERO_H_

/*
 * ĩβ0�ĸ���
 * ��Ŀ����
 * ����һ��������n,��n!(���׳�)ĩβ�ж��ٸ�0�� ����: n = 10; n! = 3628800,���Դ�Ϊ2
 * ��������:
 * ����Ϊһ�У�n(1 �� n �� 1000)
 * �������:
 * ���һ������,����Ŀ����
 *
 * ʾ��
 * ����
 * 10
 *
 * ���
 * 2
 */
#include <iostream>

void CountPrime(int num, int prime, int& count) {
	if (prime <= 1) {
		return;
	}
	while (num % prime == 0) {
		++count;
		num = num / prime;
	}
}

void Solve() {
	int n = 0;
	std::cin >> n;
	if (n <= 0) {
		return;
	}
	int num2 = 0;
	int num5 = 0;
	for (int i = 2; i <= n; ++i) {
		CountPrime(i, 2, num2);
		CountPrime(i, 5, num5);
	}
	int result = num2 < num5 ? num2 : num5;
	std::cout << result;
}



#endif /* DIDI_NUMBEROFTAILZERO_H_ */
