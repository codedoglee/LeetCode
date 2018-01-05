#ifndef MT_MONEY_H_
#define MT_MONEY_H_

/*
 * 题目描述
 * 给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，
 * 编写程序求组成N员（N为0-10000的非负整数）的不同组合的个数。
 *
 * 输入描述:
 * 输入为一个数字N，即需要拼凑的面额
 * 输出描述:
 * 输出也是一个数字，为组成N的组合个数。
 *
 * 输入
 * 5
 * 输出
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
