#ifndef HUAWEI_2017_06_H_
#define HUAWEI_2017_06_H_

/*
 * 题目描述
 * 功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
 * 最后一个数后面也要有空格
 *
 * 输入描述:
 * 输入一个long型整数
 * 输出描述:
 * 按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
 *
 * 示例
 * 输入
 * 180
 * 输出
 * 2 2 3 3 5
 */
#include <iostream>

void Solve() {
    long long n;
    std::cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (n == 0) {
            break;
        }
        while (n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }
}



#endif /* HUAWEI_2017_06_H_ */
