#ifndef BAIDU_ARRANGESEATS_H_
#define BAIDU_ARRANGESEATS_H_

/*
 * ����λ
 * ��Ŀ����
 * ��������һ��Բ�ε����ӣ���������n����λ����λ����˳���1��n��ţ�����n����λ��1����λ���ڣ�ÿ����λ����һ����
 * m����һ��ȥ��Ҳ����Է���Ϊ�˸��õؾͲͣ����ǲ�������̫��ӵ������ˣ����������������������ڡ�
 * ��֪��һ���ж����ֲ�ͬ�ľ������������𰸿��ܷǳ�������𰸳���1000000007֮���������
 * ����������һ�����ҽ�������һ���ˣ��������������������˲�ͬ��λ���ϡ�
 * ����
 * ��һ��һ������T��T<=10����ʾ�������ݵ�����������ÿ��������ݣ�����������n��m��1<=n,m<=100000����
 * ��������
 * 4
 * 3 1
 * 3 2
 * 4 2
 * 50 10
 * ���
 * ÿ���������һ�У������ķ���������������ںϷ��ľ���������������Ϊ0��
 * �������
 * 3
 * 0
 * 4
 * 128093084
 *
 * ��𣺲������������
 */
#include <iostream>

#define MOD 1000000007

void ArrangeSeats() {
	int T = 0;
	int n = 0;
	int m = 0;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		std::cin >> n >> m;
		if (2*m > n) {
			std::cout << 0 << "\n";
			continue;
		}
		long long sum = n;
		for (int j = m+1; j <= 2*m-1; ++j) {
			sum = sum * (n-j) % MOD;
		}
		long long div = 1;
		std::cout << sum << "\n";
	}
}


#endif /* BAIDU_ARRANGESEATS_H_ */