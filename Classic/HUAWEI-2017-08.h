#ifndef HUAWEI_2017_08_H_
#define HUAWEI_2017_08_H_

/*
 * ��Ŀ����
 * ���ݱ��¼��������������ֵ����Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������
 * ��������:
 * �������ֵ�Եĸ���
 * Ȼ������ɶԵ�index��valueֵ���Կո����
 * �������:
 * ����ϲ���ļ�ֵ�ԣ����У�
 *
 * ʾ��
 * ����
 * 4
 * 0 1
 * 0 2
 * 1 2
 * 3 4
 *
 * ���
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
