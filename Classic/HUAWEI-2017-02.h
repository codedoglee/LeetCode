#ifndef HUAWEI_2017_02_H_
#define HUAWEI_2017_02_H_

/*
 * ��Ŀ����
 * д��һ�����򣬽���һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��
 * ��������:
 * ����һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���
 * �������:
 * ��������ַ����к��и��ַ��ĸ�����
 * ʾ����
 * ���룺
 * ABCDEF
 * A
 * �����
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
