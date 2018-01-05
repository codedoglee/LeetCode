#ifndef MT_LOSTTHREENUMBER_H_
#define MT_LOSTTHREENUMBER_H_

/*
 * ��Ŀ����
 * ������һ�����飬��ֵΪ��1��10000���������������֡�����ĳ��żȻ������������������ж�ʧ��ĳ����Ԫ�أ�ͬʱ˳�򱻴��ң�
 * ������Ҫ�������ķ����ҳ���ʧ��������Ԫ�أ����ҽ�������Ԫ�ظ��ݴ�С��������ƴ��Ϊһ�������֣����������7��������
 * ������ʧ��Ԫ��Ϊ336��10��8435���õ���������Ϊ103368435�������ߵ�����Ϊ2��
 *
 * ��������:
 * ��������Ϊһ�У�����9997�����֣��ո������
 * �������:
 * ���Ϊһ�У�����һ�����֡�
 *
 * ʾ��
 * ����
 * ͬ������������
 *
 * ���
 * 2
 */
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

void Solve() {
	int numbers[10001];
	memset(numbers, 0, sizeof(numbers));
	int temp;
	for (int i = 0; i < 9997; ++i) {
		std::cin >> temp;
		numbers[temp] = 1;
	}

	int lost[3];
	int j = 0;
	for (int i = 1; i < 10001; ++i) {
		if (numbers[i] == 0) {
			lost[j] = i;
			++j;
		}
	}
	std::sort(lost, lost+3);

	std::stringstream ss;
	for (int i = 0; i < 3; ++i) {
		ss << lost[i];
	}
	long long num = 0;
	ss >> num;
	std::cout << num % 7;
}



#endif /* MT_LOSTTHREENUMBER_H_ */
