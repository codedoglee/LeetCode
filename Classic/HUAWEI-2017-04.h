#ifndef HUAWEI_2017_04_H_
#define HUAWEI_2017_04_H_

/*
 * 题目描述
 * 连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
 * 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
 * 输入描述:
 * 连续输入字符串(输入2次,每个字符串长度小于100)
 * 输出描述:
 * 输出到长度为8的新字符串数组
 *
 * 示例
 * 输入
 * abc
 * 123456789
 *
 * 输出
 * abc00000
 * 12345678
 * 90000000
 */
#include <iostream>

void Solve() {
    char buf[101];
    while (scanf("%s", buf) != -1) {
        if (*buf == '\0') {
            continue;
        }
        char* cur = buf;
        int offset = 0;
        while (*(cur+offset) != '\0') {
            if (offset <= 7) {
                std::cout << *(cur+offset);
                ++offset;
            }
            if (offset >= 8) {
                offset = 0;
                cur = cur + 8;
                std::cout << std::endl;
            }
        }
        if (offset > 0) {
			while (offset <= 7) {
				std::cout << '0';
				++offset;
			}
			std::cout << std::endl;
		}
    }
}



#endif /* HUAWEI_2017_04_H_ */
