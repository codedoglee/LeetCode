#ifndef HUAWEI_2017_10_H_
#define HUAWEI_2017_10_H_

/*
 * ��Ŀ����
 * ��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ���ACSII�뷶Χ��(0~127)�����ڷ�Χ�ڵĲ���ͳ�ơ�
 * ��������:
 * ����N���ַ����ַ���ACSII�뷶Χ�ڡ�
 * �������:
 * �����Χ��(0~127)�ַ��ĸ�����
 *
 * ʾ��
 * ����
 * abc
 *
 * ���
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
