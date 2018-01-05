#ifndef TENCENT_ENCODE_H_
#define TENCENT_ENCODE_H_

/*
 * ��Ŀ����
 * �ٶ�һ�ֱ���ı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰѸñ��밴�ֵ�������
 * �γ�һ���������£� a, aa, aaa, aaaa, aaab, aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy
 * ����a��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ� ��дһ������������������һ�����룬�����������Ӧ��Index.
 * ��������:
 * ����һ����������ַ���,�ַ�������С�ڵ���100.
 * �������:
 * �����������index
 *
 * ʾ��
 * ����
 * baca
 *
 * ���
 * 16331
 */
#include <iostream>
#include <cstring>

void Solve() {
	char buf[101];
	scanf("%s", buf);
	int len = strlen(buf);
	int h = 0;
	while (len < 4) {
		buf[len] = 'a';
		++len;
		++h;
	}
	int index = 0;
	int help[4] = {1, 26, 651, 16276};
	for (int i = 0; i < len; ++i) {
		index += (buf[i] - 'a') * help[len-1-i] + 1;
	}
	std::cout << index-1-h;
}



#endif /* TENCENT_ENCODE_H_ */
