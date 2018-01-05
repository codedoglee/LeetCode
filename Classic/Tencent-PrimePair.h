#ifndef TENCENT_PRIMEPAIR_H_
#define TENCENT_PRIMEPAIR_H_

/*
 * 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
 * 如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
 *
 * 输入描述:
 * 输入包括一个整数n,(3 ≤ n < 1000)
 * 输出描述:
 * 输出对数
 *
 * 示例
 * 输入
 * 10
 *
 * 输出
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
