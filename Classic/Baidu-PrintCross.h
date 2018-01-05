#ifndef BAIDU_PRINTCROSS_H_
#define BAIDU_PRINTCROSS_H_

/*
 * 十字架
 * 题目描述
 * 小A很喜欢十字架，并喜欢用各种方式产生十字架的样子。小A不满足简单的十字架输出效果，所以重新定义了一种高大上的十字架输出方式。
 * 给一个n(1≤n≤10) , 输出对应的图形，具体形式如下：
 * 1.当n=1的时候，输出一个小写字母"o":
 * o
 * 2.当n≥2的时候，复制n=n-1时候的图像，并且在n-1图像的上、下、左、右都粘贴一个一模一样的图形。
 * 如n=2时，在原图"o"的上下左右都粘贴一个"o",所以最后输出的是这样一个图形：
 *  o
 * ooo
 *  o
 * 输入
 * 包含多组数据，第一行是数据组数T(T≤10)，随后有T行，每组数据占一行，其中包含一个数字n(1 ≤ n ≤ 10) 。
 * 样例输入
 * 2
 * 2
 * 3
 * 输出
 * 首先每行输出：“Case #x:”，x表示这是第几组数据，在随后的行中输出对应图形。
 * 注意每行输出字符数应该与o处于最右的那一行的字符数相同；如果对应位置没有字母o，就在那一个位置输出一个空格。
 * 样例输出
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
