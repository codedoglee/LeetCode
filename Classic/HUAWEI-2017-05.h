#ifndef HUAWEI_2017_05_H_
#define HUAWEI_2017_05_H_

/*
 * 题目描述
 * 写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
 * 输入描述:
 * 输入一个十六进制的数值字符串。
 * 输出描述:
 * 输出该数值的十进制字符串。
 *
 * 示例
 * 输入
 * 0xA
 *
 * 输出
 * 10
 */
#include <iostream>
#include <cstring>

void Solve() {
    char buf[100];
    long long result = 0;
    while (gets(buf)) {
        int length = strlen(buf);
        for (int i = 2; i < length; ++i) {
        	if (buf[i] >= '0' && buf[i] <= '9') {
        		if (i == length-1) {
        			result = result + buf[i] - '0';
        		}
        		else {
        			result = (result + buf[i] - '0') * 16;
        		}
        	}
        	else if (buf[i] >= 'A' && buf[i] <= 'F') {
        		if (i == length-1) {
					result = result + buf[i] - 'A' + 10;
				}
        		else {
        			result = (result + buf[i] - 'A' + 10) * 16;
        		}
        	}
        }
        std::cout << result << std::endl;
        result = 0;
    }
}



#endif /* HUAWEI_2017_05_H_ */
