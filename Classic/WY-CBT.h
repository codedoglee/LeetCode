#ifndef WY_CBT_H_
#define WY_CBT_H_

/*
 * ��Ŀ����
 * ţţ�õ���һ���ر�ͼ��˳�Ųر�ͼ��ָʾ��ţţ������һ���ر��У��ر�������һ�����أ�����ÿ�λ���ʾ�����ַ��� s �� t��
 * ���ݹ��ϵĴ�˵��ţţ��Ҫÿ�ζ��ش� t �Ƿ��� s �������С�ע�⣬�����в�Ҫ����ԭ�ַ������������ģ����紮 abc��
 * ���������о��� {�մ�, a, b, c, ab, ac, bc, abc} 8 �֡�
 *
 * ��������:
 * ÿ���������һ������������ÿ�����������������г��Ȳ����� 10 �Ĳ������ո�Ŀɼ� ASCII �ַ�����
 * �������:
 * ���һ�� ��Yes�� ���� ��No�� ��ʾ�����
 *
 * ����
 * x.nowcoder.com
 * ooo
 * ���
 * Yes
 */
#include <iostream>
#include <string.h>

void Solve() {
    char s[11];
    char t[11];
    std::cin >> s;
    std::cin >> t;
    int i = 0;
    int j = 0;
    int len1 = strlen(s);
    int len2 = strlen(t);

    while (i < len1) {
        if (s[i] == t[j]) {
            if (j == len2-1) {
                std::cout << "Yes";
                return;
            }
            ++j;
        }
        ++i;
    }
    std::cout << "No";
}


#endif /* WY_CBT_H_ */
