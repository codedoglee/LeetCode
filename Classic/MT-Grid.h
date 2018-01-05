#ifndef MT_GRID_H_
#define MT_GRID_H_

/*
 * ��Ŀ����
 * ��һ��X*Y������С��Ҫ�ڴ������ϴ����Ͻǵ����½ǣ�ֻ���߸����ֻ�����һ������ߡ������һ���㷨������С���ж������߷���
 * ��������������int x,int y���뷵��С�ŵ��߷���Ŀ��
 *
 * ��������:
 * �������һ�У����Ÿ���������������x��y��ȡֵ��Χ[1,10]��
 * �������:
 * �������һ�У�Ϊ�߷�����Ŀ��
 *
 * ʾ��
 * ����
 * 3 2
 * ���
 * 10
 */
#include <iostream>

void Solve() {
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	int dp[x+1][y+1];
	for (int i = 1; i < x+1; ++i) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < y+1; ++j) {
		dp[0][j] = 1;
	}
	for (int i = 1; i < x+1; ++i) {
		for (int j = 1; j < y+1; ++j) {
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	std::cout << dp[x][y];
}


#endif /* MT_GRID_H_ */