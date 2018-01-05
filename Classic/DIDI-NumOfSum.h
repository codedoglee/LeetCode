#ifndef DIDI_NUMOFSUM_H_
#define DIDI_NUMOFSUM_H_

/*
 * 数字和为sum的方法数
 *
 * 题目描述
 * 给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
 * 当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
 * 输入描述:
 * 输入为两行:
 *
 * 第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
 *
 * 第二行为n个正整数A[i](32位整数)，以空格隔开。
 * 输出描述:
 * 输出所求的方案数
 *
 * 示例
 * 输入
 * 5 15
 * 5 5 10 2 3
 *
 * 输出
 * 4
 */
#include <iostream>
#include <cstring>

const int N = 1000;

long long dp[N+1][N+1];	//dp[i][j]表示，前i个数组成和为j的方案数

void Solve() {
	int n = 0;
	int sum = 0;
	std::cin >> n >> sum;
	int num[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];
	}
	memset(dp, 0, sizeof(dp));
	//从i个数中取和为0的方案数为1，即什么都不取
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	//前i个数
	for (int i = 1; i <= n; ++i) {
		//和为j
		for (int j = 0; j <= sum; ++j) {
			//如果新加进来的，下标为i-1的数，不大于当前求和j
			if (num[i-1] <= j) {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i-1]];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	std::cout << dp[n][sum];
}


#endif /* DIDI_NUMOFSUM_H_ */
