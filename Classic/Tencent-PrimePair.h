#ifndef TENCENT_PRIMEPAIR_H_
#define TENCENT_PRIMEPAIR_H_

/*
 * ����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
 * �磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10,�ֱ�Ϊ(5,5),(3,7)��
 *
 * ��������:
 * �������һ������n,(3 �� n < 1000)
 * �������:
 * �������
 *
 * ʾ��
 * ����
 * 10
 *
 * ���
 * 2
 */
#include <iostream>

bool IsPrime(int n) {
	bool is = true;
	int i = 2;
	while (i <= (n >> 1)) {
		if (n % i == 0) {
			is = false;
			break;
		}
		++i;
	}
	return is;
}

void Solve() {
	int n = 0;
	std::cin >> n;
	int result = 0;
	for (int i = 2; i <= (n >> 1); ++i) {
		if (IsPrime(i) && IsPrime(n-i)) {
			++result;
		}
	}
	std::cout << result;
}



#endif /* TENCENT_PRIMEPAIR_H_ */
