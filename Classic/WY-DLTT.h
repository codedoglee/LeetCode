#ifndef WY_DLTT_H_
#define WY_DLTT_H_

/*
 * 题目描述
 * 给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，
 * 和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，也不能到达障碍上。
 * 地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
 * 输入描述:
 * 每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。接下来的 n 行，
 * 每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，
 * 表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。
 * 之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，
 * 每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）
 *
 * 输出描述:
 * 输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。以下测试用例中，
 * 牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
 *
 * 输入
 * 3 3
 * ...
 * ...
 * ...
 * 0 1
 * 4
 * 1 0
 * 0 1
 * -1 0
 * 0 -1
 * 输出
 * 3
 */
#include <iostream>
#include <queue>
#include <string.h>

const int T = 50;

char DL[T][T];
int n = 0;
int m = 0;
int x0 = 0;
int y0 = 0;
int k = 0;
int dx[T];
int dy[T];
int visited[T][T];	//记录最短到达步数

void Solve() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> DL[i][j];
        }
    }
    std::cin >> x0 >> y0 >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> dx[i] >> dy[i];
    }
    memset(visited, 0, sizeof(visited));
    visited[x0][y0] = 1;	//起始步数为1,0表示未访问

    std::queue<std::pair<int, int> > q;

    q.push(std::pair<int, int>(x0, y0));

    int curx = 0;
    int cury = 0;
    int nextx = 0;
    int nexty = 0;
    while (!q.empty()) {
    	curx = q.front().first;
    	cury = q.front().second;
    	q.pop();
    	for (int j = 0; j < k; ++j) {
    		nextx = curx + dx[j];
    		nexty = cury + dy[j];
    		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && visited[nextx][nexty] == 0) {
    			if (DL[nextx][nexty] == '.') {
    				visited[nextx][nexty] = visited[curx][cury] + 1;
    				q.push(std::pair<int, int>(nextx, nexty));
    			}
    		}
    	}
    }

    int max = 0;

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (DL[i][j] == '.') {
    			if (visited[i][j] == 0) {
    				std::cout << -1;
    				return;
    			}
    			else if (visited[i][j] > max) {
    				max = visited[i][j];
    			}
    		}
    	}
    }
    std::cout << max-1;
}


#endif /* WY_DLTT_H_ */
