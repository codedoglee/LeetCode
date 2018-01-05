#ifndef DIDI_UNDERGROUNDMAZE_H_
#define DIDI_UNDERGROUNDMAZE_H_

/*
 * 小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单,
 * 假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。
 * 小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),
 * 小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,
 * 当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。
 * 现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
 * 输入描述:
 * 输入包括n+1行:
 *
 * 第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
 *
 * 接下来的n行:
 *
 * 每行m个0或者1,以空格分隔
 * 输出描述:
 * 如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。
 * 测试数据保证答案唯一
 *
 * 示例
 * 输入
 * 4 4 10
 * 1 0 0 1
 * 1 1 0 1
 * 0 1 1 1
 * 0 0 1 1
 *
 * 输出
 * [0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
 */
#include <iostream>
#include <vector>
#include <cstring>

const int N = 10;
const int M = 10;

struct Node {
	int x;
	int y;
	Node(int xx, int yy) : x(xx), y(yy) {}
};

void DoWork(int maze[][M], bool flag[][M], int p, int x, int y, int n, int m, std::vector<Node>& path, std::vector<Node>& cpath, int& power) {
	if (x == 0 && y == m-1 && p >= 0) {
		cpath.push_back(Node(x, y));
		if (p > power) {
			power = p;
			path = cpath;
		}
		return;
	}
	if (p <= 0) {
		return;
	}

	flag[x][y] = true;
	cpath.push_back(Node(x, y));

	if (x-1 >= 0 && x-1 <= n && maze[x-1][y] == 1 && flag[x-1][y] == false) {
		DoWork(maze, flag, p-3, x-1, y, n, m, path, cpath, power);
	}
	if (y-1 >= 0 && y-1 <= m && maze[x][y-1] == 1 && flag[x][y-1] == false) {
		DoWork(maze, flag, p-1, x, y-1, n, m, path, cpath, power);
	}
	if (y+1 >= 0 && y+1 <= m && maze[x][y+1] == 1 && flag[x][y+1] == false) {
		DoWork(maze, flag, p-1, x, y+1, n, m, path, cpath, power);
	}
	if (x+1 >= 0 && x+1 <= n && maze[x+1][y] == 1 && flag[x+1][y] == false) {
		DoWork(maze, flag, p, x+1, y, n, m, path, cpath, power);
	}

	flag[x][y] = false;
	cpath.erase(cpath.end()-1);
}

void Solve() {
	int p = 0;
	int n = 0;
	int m = 0;
	std::cin >> n >> m >> p;
	int maze[N][M];
	bool flag[N][M];
	memset(maze, 0, sizeof(maze));
	memset(flag, false, sizeof(flag));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> maze[i][j];
		}
	}
	std::vector<Node> path;
	std::vector<Node> cpath;
	int power = 0x7FFFFFFF;
	DoWork((int(*)[M])maze, (bool(*)[M])flag, p, 0, 0, n, m, path, cpath, power);
	if (power == 0x7FFFFFFF) {
		std::cout << "Can not escape!" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < path.size(); ++i) {
		std::cout << "[" << path[i].x << "," << path[i].y << "]";
		if (i < path.size()-1) {
			std::cout << ",";
		}
	}
}


#endif /* DIDI_UNDERGROUNDMAZE_H_ */
