#ifndef WY_FTD_H_
#define WY_FTD_H_

/*
 * 题目描述
 * 牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以看成是一个矩形，每个位置有一个价值。
 * 分割田地的方法是横竖各切三刀，分成 16 份，作为领导干部，牛牛总是会选择其中总价值最小的一份田地， 作为牛牛最好的朋友，
 * 你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？
 *
 * 输入描述:
 * 每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 75），表示田地的大小，
 * 接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示每块位置的价值。
 * 输出描述:
 * 输出一行表示牛牛所能取得的最大的价值。
 *
 * 输入
 * 4 4
 * 3332
 * 3233
 * 3332
 * 2323
 * 输出
 * 2
 */
#include <iostream>
#include <string.h>

const int T = 75;

int value[T+1][T+1];
int sum[T+1][T+1];
char buf[T+2];
int n = 0;
int m = 0;

int cal(int p, int q, int i, int j) {
	return sum[i][j] - sum[p][j] - sum[i][q] + sum[p][q];
}

bool cut(int mid) {
	for (int i = 1; i <= m-3; ++i) {
		if (sum[n][i] < mid) {
			continue;
		}
		for (int j = i+1; j <= m-2; ++j) {
			if (sum[n][j] - sum[n][i] < mid) {
				continue;
			}
			for (int k = j+1; k <= m-1; ++k) {
				if (sum[n][k] - sum[n][j] < mid) {
					continue;
				}
				int t = 0;
				int cut = 0;
				for (int h = 1; h <= n; ++h) {
					if (sum[h][m] < mid*4) {
						continue;
					}
					int reca = cal(t, 0, h, i);
					int recb = cal(t, i, h, j);
					int recc = cal(t, j, h, k);
					int recd = cal(t, k, h, m);
					if (reca >= mid && recb >= mid && recc >= mid && recd >= mid) {
						t = h;
						++cut;
					}
				}
				if (cut >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}

void Solve() {
	memset(value, 0, sizeof(value));
	memset(sum, 0, sizeof(sum));

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> (char*)(buf+1);
		for (int j = 1; j <= m; ++j) {
			value[i][j] = (int)(buf[j] - '0');
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			sum[i][j] = value[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int left = 0;
	int right = sum[n][m];
	int mid = 0;
	int res = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (cut(mid)) {
			res = mid;
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	std::cout << res;
}


#endif /* WY_FTD_H_ */
