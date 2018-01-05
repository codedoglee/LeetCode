#ifndef DIDI_TRANSLATERADIX_H_
#define DIDI_TRANSLATERADIX_H_

/*
 * ����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
 * ��������:
 * ����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
 * �������:
 * Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
 *
 * ʾ��
 * ����
 * 7 2
 *
 * ���
 * 111
 */
#include <iostream>
#include <vector>

void Solve() {
	int n = 0;
	int radix = 0;
	std::cin >> n >> radix;
	std::vector<char> result;
	int p = 0;
	if (n < 0) {
		n = (-1) * n;
		std::cout << "-";
	}
	while (n != 0) {
		p = n % radix;
		n /= radix;
		if (p >= 0 && p <= 9) {
			result.push_back('0' + p);
		}
		if (p >= 10 && p < radix) {
			 result.push_back('A' + p - 10);
		}
	}
	for (int i = result.size()-1; i >= 0; --i) {
		std::cout << result[i];
	}
}


#endif /* DIDI_TRANSLATERADIX_H_ */
