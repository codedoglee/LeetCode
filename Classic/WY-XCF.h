#ifndef WY_XCF_H_
#define WY_XCF_H_

/*
 * ��Ŀ����
 * ţţ�볢��һЩ�µ�����ÿ��������ҪһЩ��ͬ�Ĳ��ϣ���������е�������Ҫ׼�������ֲ�ͬ�Ĳ��ϡ�
 *
 * ��������:
 * ÿ��������� 1 ������������ÿ�����������ĵ� i �У���ʾ��ɵ� i ��������Ҫ��Щ���ϣ����������ÿո������
 * ����ֻ������дӢ����ĸ�Ϳո������ļ������� 50 �У�ÿһ�в����� 50 ���ַ���
 * �������:
 * ���һ��һ�����ֱ�ʾ�������������Ҫ�����ֲ�ͬ�Ĳ��ϡ�
 *
 * ����
 * BUTTER FLOUR
 * HONEY FLOUR EGG
 * ���
 * 4
 */
#include <iostream>
#include <set>
#include <string.h>

void Solve() {
    std::set<std::string> s;
    std::string temp;
    while (std::cin >> temp) {
    	s.insert(temp);
    }
    std::cout << s.size();
}


#endif /* WY_XCF_H_ */
