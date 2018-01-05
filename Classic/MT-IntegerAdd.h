#ifndef MT_INTEGERADD_H_
#define MT_INTEGERADD_H_

/*
 * 题目描述
 * 请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error
 *
 * 输入描述:
 * 输入为一行，包含两个字符串，字符串的长度在[1,100]。
 * 输出描述:
 * 输出为一行。合法情况输出相加结果，非法情况输出error
 *
 * 示例
 * 输入
 * 123 123
 * abd 123
 *
 * 输出
 * 246
 * Error
 */
#include <stdio.h>
#include <iostream>
#include <string.h>

void Solve() {
	char data1[101];
	char data2[101];
	scanf("%s", data1);
	scanf("%s", data2);

	int len1 = strlen(data1);
	int len2 = strlen(data2);

	char* num1 = data1;
	char* num2 = data2;

	if (len1 > len2) {
		num1 = data2;
		num2 = data1;
	}

	for (int i = 0; i < len1; ++i) {
		if (num1[i] < '0' || num1[i] > '9') {
			std::cout << "error";
			return;
		}
	}
	for (int i = 0; i < len2; ++i) {
		if (num2[i] < '0' || num2[i] > '9') {
			std::cout << "error";
			return;
		}
	}

	char result[102];
	int nTakeOver = 0;
	int i = len1-1;
	int j = len2-1;
	int k = 0;
	while (i >= 0) {
		int sum = num1[i] - '0' + num2[j] - '0' + nTakeOver;
		if (sum >= 10) {
			nTakeOver = 1;
			result[k] = '0' + sum - 10;
		}
		else {
			nTakeOver = 0;
			result[k] = '0' + sum;
		}
		--i;
		--j;
		++k;
	}
	while (j >= 0) {
		int sum = num2[j] - '0' + nTakeOver;
		if (sum >= 10) {
			nTakeOver = 1;
			result[k] = '0' + sum - 10;
		}
		else {
			nTakeOver = 0;
			result[k] = '0' + sum;
		}
		--j;
		++k;
	}
	if (nTakeOver == 1) {
		result[k] = '1';
		++k;
	}
	for (int t = k-1; t >= 0; --t) {
		std::cout << result[t];
	}
}



#endif /* MT_INTEGERADD_H_ */
