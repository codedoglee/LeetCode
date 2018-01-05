#ifndef JD_UNIONSET_H_
#define JD_UNIONSET_H_

/*
 * ��Ŀ����
 * �����������ϣ�Ҫ��{A} + {B}�� ע��ͬһ�������в�����������ͬ��Ԫ�ء�
 * ��������:
 * ÿ���������ݷ�Ϊ����,��һ������������n,m(0 �� n,m �� 10000)���ֱ��ʾ����A�ͼ���B��Ԫ�ظ����������зֱ��ʾ����A�ͼ���B��
 * ÿ��Ԫ��Ϊ������int��Χ������,ÿ��Ԫ��֮���и��ո������
 *
 * �������:
 * ���ÿ���������һ�����ݣ���ʾ�ϲ���ļ��ϣ�Ҫ���С���������ÿ��Ԫ��֮����һ���ո����,��ĩ�޿ո�
 *
 * ʾ��
 * ����
 * 3 3
 * 1 3 5
 * 2 4 6
 *
 * ���
 * 1 2 3 4 5 6
 */
#include <iostream>
#include <set>

void Solve() {
	int n = 0;
	int m = 0;
	std::set<int> s;
	int temp = 0;

	std::cin >> n >> m;
	for (int i = 0; i < n + m; ++i) {
		std::cin >> temp;
		s.insert(temp);
	}

	std::set<int>::iterator it = s.begin();
	for (; it != s.end(); ++it) {
		std::cout << *it;
		if (*it != *(s.rbegin())) {
			std::cout << " ";
		}
	}
}


#endif /* JD_UNIONSET_H_ */
