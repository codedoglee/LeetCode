#ifndef DIDI_NUMBEROFTAILZERO_H_
#define DIDI_NUMBEROFTAILZERO_H_

/*
 * 末尾0的个数
 * 题目描述
 * 输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2
 * 输入描述:
 * 输入为一行，n(1 ≤ n ≤ 1000)
 * 输出描述:
 * 输出一个整数,即题目所求
 *
 * 示例
 * 输入
 * 10
 *
 * 输出
 * 2
 */
#include <iostream>

void CountPrime(int num, int prime, int& count) {
	if (prime <= 1) {
		return;
	}
	while (num % prime == 0) {
		++count;
		num = num / prime;
	}
}

void Solve() {
	int n = 0;
	std::cin >> n;
	if (n <= 0) {
		return;
	}
	int num2 = 0;
	int num5 = 0;
	for (int i = 2; i <= n; ++i) {
		CountPrime(i, 2, num2);
		CountPrime(i, 5, num5);
	}
	int result = num2 < num5 ? num2 : num5;
	std::cout << result;
}



#endif /* DIDI_NUMBEROFTAILZERO_H_ */
