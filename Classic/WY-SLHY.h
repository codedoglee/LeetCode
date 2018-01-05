#ifndef WY_SLHY_H_
#define WY_SLHY_H_

/*
 * ��Ŀ����
 * ţţ����ҵ������һ������Ϊ n ������ A��������а����˴�1��n��n������������ΪһЩԭ��
 * ������һЩλ�ã������� 10 �����������ˣ�����ţţ�ǵ��������˳��Ե������� k��
 * ˳�����ָ���� i < j �� A[i] < A[j] �Ķ����������ţţ��������������Ҫ��ĺϷ����е���Ŀ��
 *
 * ��������:
 * ÿ���������һ������������ÿ�����������ĵ�һ�а����������� n �� k��1 <= n <= 100, 0 <= k <= 1000000000����
 * �������� 1 �У����� n �����ֱ�ʾ���� A�����е���0�����ʾ�������λ�ã������� 10 ������
 * �������:
 * ���һ�б�ʾ�Ϸ���������Ŀ��
 *
 * ����
 * 5 5
 * 4 0 0 2 0
 * ���
 * 2
 */
#include <iostream>
#include <string.h>
#include <vector>

//ȫ����
std::vector<std::vector<int> > permVec;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//���ݽ�������ȡȫ����
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
    //��ȫ���з���ԭ���п�ȱλ��
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
