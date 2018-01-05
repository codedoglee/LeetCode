#ifndef HUAWEI_2017_02_H_
#define HUAWEI_2017_02_H_

/*
 * 题目描述
 * 写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
 * 输入描述:
 * 输入一个有字母和数字以及空格组成的字符串，和一个字符。
 * 输出描述:
 * 输出输入字符串中含有该字符的个数。
 * 示例：
 * 输入：
 * ABCDEF
 * A
 * 输出：
 * 1
 */
#include <iostream>

void Solve() {
    char buf[10000];
    char c;
    gets(buf);
    scanf("%c", &c);
    char* p = buf;
    if (c >= 'A' && c <= 'Z') {
    	c += 32;
    }
    while (*p != '\0') {
    	if (*p >= 'A' && *p <= 'Z') {
    		*p += 32;
    	}
    	++p;
    }
    int count = 0;
    p = buf;
    while (*p != '\0') {
        if (*p == c) {
            ++count;
        }
        ++p;
    }
    std::cout << count;
}



#endif /* HUAWEI_2017_02_H_ */
