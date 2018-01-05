#ifndef WY_DLTT_H_
#define WY_DLTT_H_

/*
 * ��Ŀ����
 * ����һ�� n �� m �еĵ��Σ����� '.' ��ʾ����ͨ�е�λ�ã�'X' ��ʾ����ͨ�е��ϰ���ţţ�� (x0 , y0 ) λ�ó���������������Σ�
 * ��һ�����Ϸ����ͬ���ǣ���ÿһ��ֻ�ܰ���һЩָ���Ĳ����������Σ�Ҫ��ÿһ���������Գ������εı߽磬Ҳ���ܵ����ϰ��ϡ�
 * ���εĳ��ڿ���������ĳ������ͨ�е�λ���ϡ�ţţ��֪�������£�����Ҫ���ٲ��ſ����뿪������Ρ�
 * ��������:
 * ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, m <= 50������ʾ���εĳ��Ϳ��������� n �У�
 * ÿ�� m ���ַ����������Σ����ν����ٰ������� '.'����������һ�У������������� x0, y0��
 * ��ʾţţ�ĳ���λ�ã�0 <= x0 < n, 0 <= y0 < m�����Ͻǵ�����Ϊ ��0, 0��������λ��һ���� '.'����
 * ֮���һ�а���һ������ k��0 < k <= 50����ʾţţ�Ϸ��Ĳ��������������� k �У�
 * ÿ���������� dx, dy ��ʾÿ�ο�ѡ���ƶ����к��в�����-50 <= dx, dy <= 50��
 *
 * �������:
 * ���һ��һ�����ֱ�ʾ��������Ҫ���ٴ��ƶ������뿪���Σ������Զ�޷��뿪����� -1�����²��������У�
 * ţţ�������������ƶ��������п�ͨ�е�λ��.�ϣ����γ�����������������½ǣ�ţţ���뿪��Ҫ�ƶ��Ĵ�����࣬Ϊ3�Ρ�
 *
 * ����
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
 * ���
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
int visited[T][T];	//��¼��̵��ﲽ��

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
    visited[x0][y0] = 1;	//��ʼ����Ϊ1,0��ʾδ����

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
