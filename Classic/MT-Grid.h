#ifndef MT_GRID_H_
#define MT_GRID_H_

/*
 * 题目描述
 * 有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。请设计一个算法，计算小团有多少种走法。
 * 给定两个正整数int x,int y，请返回小团的走法数目。
 *
 * 输入描述:
 * 输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
 * 输出描述:
 * 输出包括一行，为走法的数目。
 *
 * 示例
 * 输入
 * 3 2
 * 输出
 * 10
 */
#include <iostream>

void Solve() {
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	int dp[x+1][y+1];
	for (int i = 1; i < x+1; ++i) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < y+1; ++j) {
		dp[0][j] = 1;
	}
	for (int i = 1; i < x+1; ++i) {
		for (int j = 1; j < y+1; ++j) {
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	std::cout << dp[x][y];
}


#endif /* MT_GRID_H_ */
