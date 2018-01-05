#ifndef WY_SLHY_H_
#define WY_SLHY_H_

/*
 * 题目描述
 * 牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，
 * 其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，
 * 顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
 *
 * 输入描述:
 * 每个输入包含一个测试用例。每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），
 * 接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
 * 输出描述:
 * 输出一行表示合法的排列数目。
 *
 * 输入
 * 5 5
 * 4 0 0 2 0
 * 输出
 * 2
 */
#include <iostream>
#include <string.h>
#include <vector>

//全排列
std::vector<std::vector<int> > permVec;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//回溯交换法获取全排列
void Perm(std::vector<int>& v, unsigned int index) {
    if (index == v.size()) {
    	permVec.push_back(v);
    }
    else {
        for (unsigned int i = index; i < v.size(); ++i) {
            Swap(v[index], v[i]);
            Perm(v, index+1);
            Swap(v[index], v[i]);
        }
    }
}

void Solve() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int data[n+1];
    int flag[n+1];
    std::vector<int> lost;
    std::vector<int> lostIndex;
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; ++i) {
        std::cin >> data[i];
        if (data[i] != 0) {
        	flag[data[i]] = 1;
        }
        else {
        	lostIndex.push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == 0) {
            lost.push_back(i);
        }
    }
    Perm(lost, 0);

    int result = 0;
    //将全排列放入原数列空缺位置
    for (unsigned int i = 0; i < permVec.size(); ++i) {
    	int j = 0;
    	for (unsigned int t = 0; t < lostIndex.size(); ++t) {
    		data[lostIndex[t]] = permVec[i][j];
    		++j;
    	}
    	int pairNum = 0;
    	for (int g = 1; g < n; ++g) {
    		for (int h = g+1; h <= n; ++h) {
    			if (data[g] < data[h]) {
    				++pairNum;
    			}
    		}
    	}
    	if (pairNum == k) {
    		++result;
    	}
    	j = 0;
    	for (unsigned int t = 0; t < lostIndex.size(); ++t) {
			data[lostIndex[t]] = 0;
			++j;
		}
    }
    std::cout << result;
}


#endif /* WY_SLHY_H_ */
