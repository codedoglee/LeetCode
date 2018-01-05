#ifndef BAIDU_ARRANGESEATS_H_
#define BAIDU_ARRANGESEATS_H_

/*
 * 排座位
 * 题目描述
 * 餐厅里有一张圆形的桌子，桌子上有n个座位，座位按照顺序从1到n编号，而且n号座位和1号座位相邻，每个座位都不一样。
 * m个人一起去这家餐厅吃饭。为了更好地就餐，他们不想坐得太过拥挤，因此，不允许有任意两个人相邻。
 * 你知道一共有多少种不同的就坐方法吗？最后答案可能非常大，输出答案除以1000000007之后的余数。
 * 两种坐法不一样当且仅当存在一个人，在两种坐法中他坐在了不同的位置上。
 * 输入
 * 第一行一个数字T（T<=10）表示测试数据的组数。对于每组测试数据，输入两个数n和m（1<=n,m<=100000）。
 * 样例输入
 * 4
 * 3 1
 * 3 2
 * 4 2
 * 50 10
 * 输出
 * 每组数据输出一行，就坐的方案数，如果不存在合法的就坐方案，方案数为0。
 * 样例输出
 * 3
 * 0
 * 4
 * 128093084
 *
 * 解答：不相邻组合问题
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
