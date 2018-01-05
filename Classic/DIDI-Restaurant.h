#ifndef DIDI_RESTAURANT_H_
#define DIDI_RESTAURANT_H_

/*
 * ��Ŀ����
 * ĳ�͹���n�����ӣ�ÿ��������һ��������a �����ɵ���������� ��m�����ˣ�ÿ����������������:b������cԤ�����ѽ�
 *  �ڲ�����ƴ��������£���ʵ��һ���㷨ѡ������һ���ֿ��ˣ�ʹ����Ԥ�����ѽ�����
 * ��������:
 * �������m+2�С�
 * ��һ����������n(1 <= n <= 50000),m(1 <= m <= 50000)
 * �ڶ���Ϊn������a,��ÿ�����ӿ����ɵ��������,�Կո�ָ�,��Χ����32λint��Χ�ڡ�
 * ������m�У�ÿ����������b,c���ֱ��ʾ��i�����˵�������Ԥ�����ѽ��,�Կո�ָ�,��Χ����32λint��Χ�ڡ�
 * �������:
 * ���һ������,��ʾ������Ԥ�����ѽ��
 *
 * ʾ��
 * ����
 * 3 5
 * 2 4 2
 * 1 3
 * 3 5
 * 3 7
 * 5 9
 * 1 10
 *
 * ���
 * 20
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>

struct Customer {
    int b;	//����
    int c;	//����
    Customer(int bb, int cc) : b(bb), c(cc) {}
    Customer() : b(0), c(0) {}
    friend bool operator<(Customer c1, Customer c2) {
    	if (c1.c == c2.c) {
    		return c1.b < c2.b; //������������
    	}
    	return c1.c < c2.c;	//�������ѽ�������
    }
};

int Search(std::vector<int>& vec, int target) {
	if (target <= vec[0]) {
		return 0;
	}
	if (target > vec[vec.size()-1]) {
		return -1;
	}
	int low = 0;
	int high = vec.size()-1;
	int mid = (low + high) / 2;
	while (low+1 < high) {
		mid = (low + high) / 2;
		if (target <= vec[mid]) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return high;
}

void Solve1() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<int> A;
    int a;
    int b;
    int c;
    std::priority_queue<Customer> help;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        A.push_back(a);
    }
    std::sort(A.begin(), A.end());
    for (int i = 0; i < m; ++i) {
        std::cin >> b >> c;
        help.push(Customer(b, c));
    }
    long long money = 0;
    int index = 0;
    while (!help.empty() && !A.empty()) {
    	index = Search(A, help.top().b);
    	if (index >= 0) {
    		money += help.top().c;
			A.erase(A.begin() + index);
    	}
    	help.pop();
    }
    std::cout << money;
}

void Solve2() {
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	int A[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> A[i];
	}
	std::sort(A, A+n);

	int b = 0;
	int c = 0;
	std::map<int, std::deque<int> > help;
	for (int i = 0; i < m; ++i) {
		std::cin >> b >> c;
		help[b].push_back(c);
	}

	std::map<int, std::deque<int> >::iterator it = help.begin();
	for (; it != help.end(); ++it) {
		std::sort(it->second.begin(), it->second.end());
	}
	it = help.begin();
	long long money = 0;
	for (int i = 0; i < n; ++i) {
		int max = 0;
		int index = 0;
		for (int j = 1; j <= A[i]; ++j) {
			if (help.find(j) != help.end() && help[j].size() > 0 && help[j].back() > max) {
				max = help[j].back();
				index = j;
			}
		}
		help[index].pop_back();
		money += max;
	}
	std::cout << money;
}


#endif /* DIDI_RESTAURANT_H_ */
