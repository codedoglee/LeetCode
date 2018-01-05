#ifndef THEBRAIN_H_
#define THEBRAIN_H_

/*
 * СB�˻𳵺�������һ����N�е�M��֮�����С�����·;��ʱ˯ʱ�ѡ����������ۿ�����ķ羰ʱ��ע�⵽ÿ����վ����һ���ر���ɫ�����ģ�
 * ���������������Ľ����Ǿ�����һС���֡�СB�ڳ˳����������������ѵ�ʱ�䣬�������ó��յ�ʱ����˯���С�
 * ��վʱ������������̸����һ·�ļ��ţ������Ǿ��ú�����˼�����ǰ�N����M֮�侭����վ��������ɫ�����г�����
 * Ȼ�������СB�ǵõ�������ɫ���У������ж�СB�����Ǵ�N��M֮����Щ������ܿ�����˵��ɫ�����ģ����Ǹ����Ͳ����ܿ�����
 * ��ɫ����ĸ������ͬ����ĸ������ͬ����ɫ����ͬ����ĸ���ʾ��ͬ����ɫ��
 *
 * ��������:
 * �������ж���������ݣ�ÿ��������ݰ������У���һ��Ϊһ����Сд������ĸ���ɵķǿ��ַ��������Ȳ�����10^5����ʾN��M֮�䳵վ����ɫ��
 * �𳵴�M��N����ʱ�������ĳ�վ��ͬ��ֻ�Ƿ����෴���ڶ���ΪСB�ڵ�һ��˯��ʱ��������ɫ���У�������ΪСB�ڵڶ���˯��ʱ��������ɫ���С�
 * �������ж���Сд��������ĸ���ɵ��ַ��������Ȳ�����100����ĸ��ÿ�����е���ɫ˳�����а�СB������ʱ��˳�����С�
 * �������:
 * ��ÿ��������ݣ��ڵ������������СB�����з���
 *
 * forward - ��N��M����
 * backward -��M��N����
 * both - ���ַ����п��ܣ�
 * invalid - �����ܿ�����������ɫ���У�
 *
 * ʾ��1
 * ����
 * atob
 * a
 * b
 * aaacaaa
 * aca
 * aa
 *
 * ���
 * forward
 * both
 */
#include <iostream>
#include <string.h>

//next[j] = k ����p[j]֮ǰ��ģʽ���Ӵ��У��г���Ϊk����ͬǰ׺�ͺ�׺
void GetNext(char* find, int* next, int length) {
	if (find == 0 || next == 0 || length <= 0) {
		return;
	}
	int i = 0;	//ָ����ͬǰ׺��ĩβ
	int j = 1;	//ָ����ͬ��׺��ĩβ
	next[0] = -1;
	if (length > 1) {
		next[1] = 0;
	}
	while (j < length) {
		if (find[j] == find[i]) {
			++i;
		}
		else {
			i = 0;
			if (find[j] == find[i]) {
				++i;
			}
		}
		next[j] = i;
		++j;
	}
}

//�����״�ƥ���index
int KMP(char* test, int length1, char* find, int length2) {
	if (test == 0 || length1 <= 0 || find == 0 || length2 <= 0) {
		return -1;
	}
	int* next = new int[length2];
	GetNext(find, next, length2);
	int i = 0;
	int j = 0;
	while (i < length1 && j < length2) {
		if (test[i] == find[j]) {
			++i;
			++j;
		}
		else if (next[j] != -1) {
			j = next[j];
		}
		else {
			++i;
		}
	}
	if (j == length2) {
		return i - length2;
	}
	return -1;
}

void Solve() {
	char forward[100001];
	char backward[100001];
	char first[101];
	char second[101];

	bool fw = false;
	bool bw = false;

	std::cin >> forward;
	std::cin >> first;
	std::cin >> second;

	int len = strlen(forward);
	backward[len] = '\0';
	for (int i = 0; i < len; ++i) {
		backward[i] = forward[len-1-i];
	}

	int index1 = -1;
	int index2 = -1;
	char* start = forward;
	index1 = KMP(start, strlen(start), first, strlen(first));
	if (index1 != -1) {
		start = start + index1 + strlen(first);
		index2 = KMP(start, strlen(start), second, strlen(second));
		if (index2 != -1) {
			fw = true;
		}
	}

	index1 = -1;
	index2 = -1;
	start = backward;
	index1 = KMP(start, strlen(start), first, strlen(first));
	if (index1 != -1) {
		start = start + index1 + strlen(first);
		index2 = KMP(start, strlen(start), second, strlen(second));
		if (index2 != -1) {
			bw = true;
		}
	}

	if (fw && bw) {
		std::cout << "both";
	}
	else if (fw) {
		std::cout << "forward";
	}
	else if (bw) {
		std::cout << "backward";
	}
	else {
		std::cout << "invalid";
	}
}


#endif /* THEBRAIN_H_ */
