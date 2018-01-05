#ifndef HUAWEI_2017_01_H_
#define HUAWEI_2017_01_H_

/*
 * 题目描述
 * 计算字符串最后一个单词的长度，单词以空格隔开。
 * 输入描述:
 * 一行字符串，非空，长度小于5000。
 * 输出描述:
 * 整数N，最后一个单词的长度。
 * 示例：
 * 输入：hello world
 * 输出：5
 */
#include <iostream>

void Solve() {
    char buf[5000];
    gets(buf);
    char* ch = buf;
    int index = 0;
    while (*ch != '\0') {
        if (*ch == ' ') {
            index = ch - buf + 1;
        }
        ++ch;
    }
    int length = 0;
    ch = buf + index;
    while (*ch != '\0') {
        ++length;
        ++ch;
    }
    std::cout << length;
}


#endif /* HUAWEI_2017_01_H_ */
