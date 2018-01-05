#ifndef MT_LOSTTHREENUMBER_H_
#define MT_LOSTTHREENUMBER_H_

/*
 * 题目描述
 * 现在有一个数组，其值为从1到10000的连续增长的数字。出于某次偶然操作，导致这个数组中丢失了某三个元素，同时顺序被打乱，
 * 现在需要你用最快的方法找出丢失的这三个元素，并且将这三个元素根据从小到大重新拼接为一个新数字，计算其除以7的余数。
 * 例：丢失的元素为336，10，8435，得到的新数字为103368435，除以七的余数为2。
 *
 * 输入描述:
 * 输入数据为一行，包含9997个数字，空格隔开。
 * 输出描述:
 * 输出为一行，包含一个数字。
 *
 * 示例
 * 输入
 * 同题设例子输入
 *
 * 输出
 * 2
 */
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

void Solve() {
	int numbers[10001];
	memset(numbers, 0, sizeof(numbers));
	int temp;
	for (int i = 0; i < 9997; ++i) {
		std::cin >> temp;
		numbers[temp] = 1;
	}

	int lost[3];
	int j = 0;
	for (int i = 1; i < 10001; ++i) {
		if (numbers[i] == 0) {
			lost[j] = i;
			++j;
		}
	}
	std::sort(lost, lost+3);

	std::stringstream ss;
	for (int i = 0; i < 3; ++i) {
		ss << lost[i];
	}
	long long num = 0;
	ss >> num;
	std::cout << num % 7;
}



#endif /* MT_LOSTTHREENUMBER_H_ */
