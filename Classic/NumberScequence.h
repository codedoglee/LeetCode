#ifndef NUMBERSCEQUENCE_H_
#define NUMBERSCEQUENCE_H_

/*
 * 题目描述
 * 设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
 * 如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
 * 如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
 *
 * 输入描述:
 * 有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
 * 输出描述:
 * 每组数据输出一个表示最大的整数。
 *
 * 示例
 * 输入
 * 2
 * 12 123
 * 4
 * 7 13 4 246
 *
 * 输出
 * 12312
 * 7424613
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

const int N = 100;
const int MaxLen = 3;

char num1[MaxLen+1];
char num2[MaxLen+1];

char buf1[2*MaxLen+1];
char buf2[2*MaxLen+1];

int myCompare(const void* n1, const void* n2) {
	sprintf(num1, "%d", *(int*)n1);
	sprintf(num2, "%d", *(int*)n2);

	strcpy(buf1, num1);
	strcat(buf1, num2);

	strcpy(buf2, num2);
	strcat(buf2, num1);

	return strcmp(buf1, buf2);
}

void Solve() {
	int n = 0;
	int buf[N];
	while (std::cin >> n) {
		for (int i = 0; i < n; ++i) {
			std::cin >> buf[i];
		}
		qsort(buf, n, sizeof(int), myCompare);
		for (int i = n-1; i >= 0; --i) {
			std::cout << buf[i];
		}
		std::cout << "\n";
	}
}



#endif /* NUMBERSCEQUENCE_H_ */
