#ifndef BAIDU_PRINTCROSS_H_
#define BAIDU_PRINTCROSS_H_

/*
 * ʮ�ּ�
 * ��Ŀ����
 * СA��ϲ��ʮ�ּܣ���ϲ���ø��ַ�ʽ����ʮ�ּܵ����ӡ�СA������򵥵�ʮ�ּ����Ч�����������¶�����һ�ָߴ��ϵ�ʮ�ּ������ʽ��
 * ��һ��n(1��n��10) , �����Ӧ��ͼ�Σ�������ʽ���£�
 * 1.��n=1��ʱ�����һ��Сд��ĸ"o":
 * o
 * 2.��n��2��ʱ�򣬸���n=n-1ʱ���ͼ�񣬲�����n-1ͼ����ϡ��¡����Ҷ�ճ��һ��һģһ����ͼ�Ρ�
 * ��n=2ʱ����ԭͼ"o"���������Ҷ�ճ��һ��"o",������������������һ��ͼ�Σ�
 *  o
 * ooo
 *  o
 * ����
 * �����������ݣ���һ������������T(T��10)�������T�У�ÿ������ռһ�У����а���һ������n(1 �� n �� 10) ��
 * ��������
 * 2
 * 2
 * 3
 * ���
 * ����ÿ���������Case #x:����x��ʾ���ǵڼ������ݣ����������������Ӧͼ�Ρ�
 * ע��ÿ������ַ���Ӧ����o�������ҵ���һ�е��ַ�����ͬ�������Ӧλ��û����ĸo��������һ��λ�����һ���ո�
 * �������
 * Case #1:
 *  o
 * ooo
 *  o
 * Case #2:
 *     o
 *    ooo
 *     o
 *  o  o  o
 * ooooooooo
 *  o  o  o
 *     o
 *    ooo
 *     o
 */
#include <iostream>
#include <math.h>
#include <cstring>

#define MAX 10
#define NN 19683

char dp[NN][NN];

int GetEdgeLength(int n) {
	int result = 1;
	if (n == 1) {
		return 1;
	}
	else {
		for (int i = 0; i < n-1; ++i) {
			result *= 3;
		}
	}
	return result;
}

void GetCross(int row, int col, int n) {
	if (n == 1) {
		dp[row][col] = 'o';
	}
	else {
		GetCross(row, col, n-1);
		GetCross(row-pow(3, n-2), col, n-1);
		GetCross(row+pow(3, n-2), col, n-1);
		GetCross(row, col-pow(3, n-2), n-1);
		GetCross(row, col+pow(3, n-2), n-1);
	}
}

void PrintCross() {
	int T = 0;
	int n = 0;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%d", &n);
		std::memset(dp, ' ', sizeof(dp));
		int centerX = pow(3, n-1) / 2;
		int centerY = centerX;
		GetCross(centerX, centerY, n);
		std::cout << "Case #" << i << ":\n";
		for (int i = 0; i < pow(3, n-1); ++i) {
			for (int j = 0; j < pow(3, n-1); ++j) {
				std::cout << dp[i][j];
			}
			std::cout << "\n";
		}
	}
}


#endif /* BAIDU_PRINTCROSS_H_ */
