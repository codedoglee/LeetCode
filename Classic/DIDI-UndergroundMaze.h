#ifndef DIDI_UNDERGROUNDMAZE_H_
#define DIDI_UNDERGROUNDMAZE_H_

/*
 * С������һ�첻С��������һ�������Թ�,С����ϣ�����Լ���ʣ������ֵP������������Թ���Ϊ���������,
 * ��������һ��n*m�ĸ����Թ�,�Թ�ÿ��λ��Ϊ0����1,0�������λ�����ϰ���,С���ܴﵽ�������λ��;1����С���ܿ��Դﵽ��λ�á�
 * С���ܳ�ʼ��(0,0)λ��,�����Թ��ĳ�����(0,m-1)(��֤������λ�ö���1,���ұ�֤һ������㵽�յ�ɴ��·��),
 * С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ,������һ����λ������Ҫ����3����λ������ֵ,�����ƶ�����������ֵ,
 * ��С���ܵ�����ֵ����0��ʱ��û�е������,С���ܽ��޷������Թ���
 * ������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0,m-1)λ��)��
 * ��������:
 * �������n+1��:
 *
 * ��һ��Ϊ��������n,m(3 <= m,n <= 10),P(1 <= P <= 100)
 *
 * ��������n��:
 *
 * ÿ��m��0����1,�Կո�ָ�
 * �������:
 * ����������Թ�,�����һ������������С��·��,�����ʽ��������ʾ;������������Թ�,�����"Can not escape!"��
 * �������ݱ�֤��Ψһ
 *
 * ʾ��
 * ����
 * 4 4 10
 * 1 0 0 1
 * 1 1 0 1
 * 0 1 1 1
 * 0 0 1 1
 *
 * ���
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
