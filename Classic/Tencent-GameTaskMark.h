#ifndef TENCENT_GAMETASKMARK_H_
#define TENCENT_GAMETASKMARK_H_

/*
 * ��Ŀ����
 * ��Ϸ�����кܶ��ʽ����������������һ���������ֻ����һ�Σ���������һ����1024��������ID��Χ[1,1024]��
 * ����32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ���ʼ״̬����δ��ɡ� ����������������������ID��
 * ��Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ� ���һ������������ڶ���ID�������Ѿ�������1��
 * ���δ������0�������һ��ڶ���ID����[1,1024]��Χ�������-1��
 * ��������:
 * �������һ��,����������ʾ����ID.
 * �������:
 * ����Ƿ����
 *
 * ʾ��1
 * ����
 * 1024 1024
 *
 * ���
 * 1
 */
#include <iostream>
#include <cstring>

void Solve() {
	unsigned int flag[32];
	memset(flag, 0, sizeof(flag));
	int id1 = 0;
	int id2 = 0;
	std::cin >> id1 >> id2;
	if (id1 <= 0 || id1 > 1024 || id2 <= 0 || id2 > 1024) {
		std::cout << -1;
		return;
	}
	int index = (id1-1) >> 5;
	int offset = (id1-1) & 31;
	flag[index] |= (1 << (31-offset));

	int index2 = (id2-1) >> 5;
	int offset2 = (id2-1) & 31;
	bool isMarked = flag[index2] & (1 << (31 - offset2));
	if (isMarked) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}
}



#endif /* TENCENT_GAMETASKMARK_H_ */
