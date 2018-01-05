#ifndef MT_MONEY_H_
#define MT_MONEY_H_

/*
 * ��Ŀ����
 * �����������1��5��10��20��50��100Ԫ��ֽ�ң�����ÿ�ֱ�ֵ���������㹻�࣬
 * ��д���������NԱ��NΪ0-10000�ķǸ��������Ĳ�ͬ��ϵĸ�����
 *
 * ��������:
 * ����Ϊһ������N������Ҫƴ�յ����
 * �������:
 * ���Ҳ��һ�����֣�Ϊ���N����ϸ�����
 *
 * ����
 * 5
 * ���
 * 2
 */
#include <iostream>
#include <cstring>

void Solve() {
	int n = 0;
	std::cin >> n;
	long long dp[n+1];
	memset(dp, 0, sizeof(dp));
	int money[6] = {1, 5, 10, 20, 50, 100};
	dp[0] = 1;
	for (int i = 0; i < 6; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j >= money[i]) {
				dp[j] += dp[j - money[i]];
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		std::cout << i << ": " << dp[i] << "\n";
	}
	std::cout << dp[n];
}


#endif /* MT_MONEY_H_ */
