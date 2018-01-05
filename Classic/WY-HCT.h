#ifndef WY_HCT_H_
#define WY_HCT_H_

/*
 * 题目描述
 * 有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
 * 要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
 *
 * 输入描述:
 * 每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，
 * 按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
 * 输出描述:
 * 输出一行表示最大的乘积。
 *
 * 输入
 * 3
 * 7 4 7
 * 2 50
 * 输出
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

    //因为有负数，dp[i][j][0]保存最大的数，dp[i][j][1]保存最小的数
    //dp[i][j]表示必须选择第i个人，且以第i个人结尾，选择j个人的最大乘积
    long long dp[n+1][k+1][2];
    memset(dp, 0, sizeof(dp));

    //初始化，只选一个人的情况
    for (int i = 1; i <= n; ++i) {
        dp[i][1][0] = power[i];
        dp[i][1][1] = power[i];
    }

    long long result = 0;
    //必须选择第i个人，且以第i个人结尾
    for (int i = 1; i <= n; ++i) {
    	//共选择j个人
        for (int j = 2; j <= k; ++j) {
        	//往前最多寻找到i-d处
            for (int t = i-1; t >= 1 && t >= i - d; --t) {
                dp[i][j][0] = std::max(dp[i][j][0], std::max(power[i]*dp[t][j-1][0], power[i]*dp[t][j-1][1]));
                dp[i][j][1] = std::min(dp[i][j][1], std::min(power[i]*dp[t][j-1][0], power[i]*dp[t][j-1][1]));
            }
        }
        //以不同位置结尾的最大乘积
        result = std::max(result, std::max(dp[i][k][0], dp[i][k][1]));
    }
    std::cout << result;
}



#endif /* WY_HCT_H_ */
