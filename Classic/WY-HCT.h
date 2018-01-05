#ifndef WY_HCT_H_
#define WY_HCT_H_

/*
 * ��Ŀ����
 * �� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
 * Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
 *
 * ��������:
 * ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ��������
 * ��˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50������������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
 * �������:
 * ���һ�б�ʾ���ĳ˻���
 *
 * ����
 * 3
 * 7 4 7
 * 2 50
 * ���
 * 49
 */
#include <iostream>
#include <cstring>
#include <math.h>

void Solve() {
    int n = 0;
    int power[51];
    int k = 0;
    int d = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> power[i];
    }
    std::cin >> k >> d;

    //��Ϊ�и�����dp[i][j][0]������������dp[i][j][1]������С����
    //dp[i][j]��ʾ����ѡ���i���ˣ����Ե�i���˽�β��ѡ��j���˵����˻�
    long long dp[n+1][k+1][2];
    memset(dp, 0, sizeof(dp));

    //��ʼ����ֻѡһ���˵����
    for (int i = 1; i <= n; ++i) {
        dp[i][1][0] = power[i];
        dp[i][1][1] = power[i];
    }

    long long result = 0;
    //����ѡ���i���ˣ����Ե�i���˽�β
    for (int i = 1; i <= n; ++i) {
    	//��ѡ��j����
        for (int j = 2; j <= k; ++j) {
        	//��ǰ���Ѱ�ҵ�i-d��
            for (int t = i-1; t >= 1 && t >= i - d; --t) {
                dp[i][j][0] = std::max(dp[i][j][0], std::max(power[i]*dp[t][j-1][0], power[i]*dp[t][j-1][1]));
                dp[i][j][1] = std::min(dp[i][j][1], std::min(power[i]*dp[t][j-1][0], power[i]*dp[t][j-1][1]));
            }
        }
        //�Բ�ͬλ�ý�β�����˻�
        result = std::max(result, std::max(dp[i][k][0], dp[i][k][1]));
    }
    std::cout << result;
}



#endif /* WY_HCT_H_ */
