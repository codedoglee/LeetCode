#ifndef HUAWEI_2017_07_H_
#define HUAWEI_2017_07_H_

/*
 * 写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
 * 输入描述:
 * 输入一个正浮点数值
 * 输出描述:
 * 输出该数值的近似整数值
 *
 * 示例
 * 输入
 * 5.5
 *
 * 输出
 * 6
 */
#include <iostream>

void Solve() {
    double d;
    std::cin >> d;
    int i = (d + 0.5);
    std::cout << i;
}


#endif /* HUAWEI_2017_07_H_ */
