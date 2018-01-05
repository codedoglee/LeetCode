#ifndef DIDI_NUMOFSUM_H_
#define DIDI_NUMOFSUM_H_

/*
 * ���ֺ�Ϊsum�ķ�����
 *
 * ��Ŀ����
 * ����һ����n��������������A��һ������sum,��ѡ������A�в������ֺ�Ϊsum�ķ�������
 * ������ѡȡ������һ�����ֵ��±겻һ��,���Ǿ���Ϊ�ǲ�ͬ����ɷ�����
 * ��������:
 * ����Ϊ����:
 *
 * ��һ��Ϊ����������n(1 �� n �� 1000)��sum(1 �� sum �� 1000)
 *
 * �ڶ���Ϊn��������A[i](32λ����)���Կո������
 * �������:
 * �������ķ�����
 *
 * ʾ��
 * ����
 * 5 15
 * 5 5 10 2 3
 *
 * ���
 * 4
 */
#include <iostream>
#include <cstring>

const int N = 1000;

long long dp[N+1][N+1];	//dp[i][j]��ʾ��ǰi������ɺ�Ϊj�ķ�����

void Solve() {
	int n = 0;
	int sum = 0;
	std::cin >> n >> sum;
	int num[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];
	}
	memset(dp, 0, sizeof(dp));
	//��i������ȡ��Ϊ0�ķ�����Ϊ1����ʲô����ȡ
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	//ǰi����
	for (int i = 1; i <= n; ++i) {
		//��Ϊj
		for (int j = 0; j <= sum; ++j) {
			//����¼ӽ����ģ��±�Ϊi-1�����������ڵ�ǰ���j
			if (num[i-1] <= j) {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i-1]];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	std::cout << dp[n][sum];
}


#endif /* DIDI_NUMOFSUM_H_ */
