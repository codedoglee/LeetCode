#ifndef WY_FTD_H_
#define WY_FTD_H_

/*
 * ��Ŀ����
 * ţţ�� 15 �������������������ص���Ϸ��ţţ��������������أ���������ؿ��Կ�����һ�����Σ�ÿ��λ����һ����ֵ��
 * �ָ���صķ����Ǻ��������������ֳ� 16 �ݣ���Ϊ�쵼�ɲ���ţţ���ǻ�ѡ�������ܼ�ֵ��С��һ����أ� ��Ϊţţ��õ����ѣ�
 * ��ϣ��ţţȡ�õ���صļ�ֵ�;����ܴ���֪�����ֵ�������Ƕ�����
 *
 * ��������:
 * ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, m <= 75������ʾ��صĴ�С��
 * �������� n �У�ÿ�а��� m �� 0-9 ֮������֣���ʾÿ��λ�õļ�ֵ��
 * �������:
 * ���һ�б�ʾţţ����ȡ�õ����ļ�ֵ��
 *
 * ����
 * 4 4
 * 3332
 * 3233
 * 3332
 * 2323
 * ���
 * 2
 */
#include <iostream>
#include <string.h>

const int T = 75;

int value[T+1][T+1];
int sum[T+1][T+1];
char buf[T+2];
int n = 0;
int m = 0;

int cal(int p, int q, int i, int j) {
	return sum[i][j] - sum[p][j] - sum[i][q] + sum[p][q];
}

bool cut(int mid) {
	for (int i = 1; i <= m-3; ++i) {
		if (sum[n][i] < mid) {
			continue;
		}
		for (int j = i+1; j <= m-2; ++j) {
			if (sum[n][j] - sum[n][i] < mid) {
				continue;
			}
			for (int k = j+1; k <= m-1; ++k) {
				if (sum[n][k] - sum[n][j] < mid) {
					continue;
				}
				int t = 0;
				int cut = 0;
				for (int h = 1; h <= n; ++h) {
					if (sum[h][m] < mid*4) {
						continue;
					}
					int reca = cal(t, 0, h, i);
					int recb = cal(t, i, h, j);
					int recc = cal(t, j, h, k);
					int recd = cal(t, k, h, m);
					if (reca >= mid && recb >= mid && recc >= mid && recd >= mid) {
						t = h;
						++cut;
					}
				}
				if (cut >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}

void Solve() {
	memset(value, 0, sizeof(value));
	memset(sum, 0, sizeof(sum));

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> (char*)(buf+1);
		for (int j = 1; j <= m; ++j) {
			value[i][j] = (int)(buf[j] - '0');
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			sum[i][j] = value[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int left = 0;
	int right = sum[n][m];
	int mid = 0;
	int res = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (cut(mid)) {
			res = mid;
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	std::cout << res;
}


#endif /* WY_FTD_H_ */
