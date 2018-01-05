#ifndef HUAWEI_2017_03_H_
#define HUAWEI_2017_03_H_

/*
 * 题目描述
 * 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
 * 对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
 * 按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
 *
 * 输入描述:
 * 输入多行，先输入随机整数的个数，再输入相应个数的整数
 * 输出描述:
 * 返回多行，处理后的结果
 *
 * 示例
 * 输入
 * 11
 * 10
 * 20
 * 40
 * 32
 * 67
 * 40
 * 20
 * 89
 * 300
 * 400
 * 15
 *
 * 输出
 * 10
 * 15
 * 20
 * 32
 * 40
 * 67
 * 89
 * 300
 * 400
 */
#include <iostream>
#include <cstring>

void Solve() {
    int n = 0;
    int number[1001];
    while (scanf("%d", &n) != -1) {
    	memset(number, 0, sizeof(number));
    	int index = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &index);
			number[index] = 1;
		}
		for (int i = 0; i <= 1000; ++i) {
			if (number[i] == 1) {
				std::cout << i << std::endl;
			}
		}
    }
}


#endif /* HUAWEI_2017_03_H_ */
