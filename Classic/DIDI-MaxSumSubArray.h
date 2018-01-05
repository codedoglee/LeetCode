#ifndef DIDI_MAXSUMSUBARRAY_H_
#define DIDI_MAXSUMSUBARRAY_H_

/*
 * 题目描述
 * 一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
 * 输入描述:
 * 输入为两行。
 * 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素
 * 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
 * 输出描述:
 * 所有连续子数组中和最大的值。
 *
 * 示例
 * 输入
 * 3
 * -1 2 1
 *
 * 输出
 * 3
 */
#include<iostream>

bool g_InvalidInput = false;

int Solve(int* numbers, int length) {
	if (numbers == 0 || length <= 0) {
		g_InvalidInput = true;
		return -1;
	}
	int max = 0x80000000;
	int cur = 0;
	for (int i = 0; i < length; ++i) {
		cur += numbers[i];
		if (cur > max) {
			max = cur;
		}
		if (cur < 0) {
			cur = 0;
		}
	}
	return max;
}

void Test() {
	int n = 0;
	std::cin >> n;
	int numbers[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}
	std::cout << Solve(numbers, n);
}


#endif /* DIDI_MAXSUMSUBARRAY_H_ */
