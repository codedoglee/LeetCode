#ifndef HUAWEI_2017_05_H_
#define HUAWEI_2017_05_H_

/*
 * ��Ŀ����
 * д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��
 * ��������:
 * ����һ��ʮ�����Ƶ���ֵ�ַ�����
 * �������:
 * �������ֵ��ʮ�����ַ�����
 *
 * ʾ��
 * ����
 * 0xA
 *
 * ���
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
