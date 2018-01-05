#ifndef HUAWEI_2017_08_H_
#define HUAWEI_2017_08_H_

/*
 * 题目描述
 * 数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
 * 输入描述:
 * 先输入键值对的个数
 * 然后输入成对的index和value值，以空格隔开
 * 输出描述:
 * 输出合并后的键值对（多行）
 *
 * 示例
 * 输入
 * 4
 * 0 1
 * 0 2
 * 1 2
 * 3 4
 *
 * 输出
 * 0 3
 * 1 2
 * 3 4
 */
#include <iostream>
#include <cstring>

void Solve() {
    int sum[1000];
    bool flag[1000];
    memset(sum, 0, sizeof(sum));
    memset(flag, 0, sizeof(flag));
    int n = 0;
    int key;
    int value;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> key >> value;
        flag[key] = true;
        sum[key] += value;
    }
    for (int i = 0; i < 1000; ++i) {
        if (flag[i]) {
            std::cout << i << " " << sum[i] << std::endl;
        }
    }
}


#endif /* HUAWEI_2017_08_H_ */
