#ifndef HUAWEI_2017_10_H_
#define HUAWEI_2017_10_H_

/*
 * 题目描述
 * 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
 * 输入描述:
 * 输入N个字符，字符在ACSII码范围内。
 * 输出描述:
 * 输出范围在(0~127)字符的个数。
 *
 * 示例
 * 输入
 * abc
 *
 * 输出
 * 3
 */
#include <iostream>
#include <cstring>

void Solve() {
    bool flag[128];
    char buf[1000];
    memset(flag, 0, sizeof(flag));
    gets(buf);
    char* p = buf;
    while (*p != '\0') {
        if (*p >= 0 && *p <= 127) {
            flag[(unsigned int)*p] = true;
        }
        ++p;
    }
    int count = 0;
    for (int i = 0; i < 128; ++i) {
        if (flag[i]) {
            ++count;
        }
    }
    std::cout << count;
}


#endif /* HUAWEI_2017_10_H_ */
