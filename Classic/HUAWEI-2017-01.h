#ifndef HUAWEI_2017_01_H_
#define HUAWEI_2017_01_H_

/*
 * ��Ŀ����
 * �����ַ������һ�����ʵĳ��ȣ������Կո������
 * ��������:
 * һ���ַ������ǿգ�����С��5000��
 * �������:
 * ����N�����һ�����ʵĳ��ȡ�
 * ʾ����
 * ���룺hello world
 * �����5
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
