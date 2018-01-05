#ifndef THEBRAIN_H_
#define THEBRAIN_H_

/*
 * 小B乘火车和朋友们一起在N市到M市之间旅行。她在路途中时睡时醒。当她醒来观看窗外的风景时，注意到每个火车站都有一种特别颜色的旗帜，
 * 但是她看到的旗帜仅仅是经过的一小部分。小B在乘车过程中有两次清醒的时间，她到达旅程终点时处于睡梦中。
 * 出站时，她和朋友们谈论着一路的见闻，朋友们觉得很有意思，他们把N到和M之间经过车站的旗帜颜色依次列出来，
 * 然后告诉你小B记得的旗帜颜色序列，让你判断小B究竟是从N和M之间哪些方向才能看到所说颜色的旗帜，还是根本就不可能看到？
 * 颜色用字母代表，相同的字母代表相同的颜色，不同的字母则表示不同的颜色。
 *
 * 输入描述:
 * 输入中有多组测试数据，每组测试数据包含三行，第一行为一个由小写拉丁字母构成的非空字符串，长度不超过10^5，表示N到M之间车站的颜色。
 * 火车从M向N运行时，经过的车站相同，只是方向相反。第二行为小B在第一次睡醒时看到的颜色序列，第三行为小B在第二次睡醒时看到的颜色序列。
 * 两个序列都是小写的拉丁字母构成的字符串，长度不超过100个字母。每个序列的颜色顺序排列按小B看到的时间顺序排列。
 * 输出描述:
 * 对每组测试数据，在单独的行中输出小B的旅行方向。
 *
 * forward - 由N到M方向；
 * backward -由M到N方向；
 * both - 两种方向都有可能；
 * invalid - 不可能看到这样的颜色序列；
 *
 * 示例1
 * 输入
 * atob
 * a
 * b
 * aaacaaa
 * aca
 * aa
 *
 * 输出
 * forward
 * both
 */
#include <iostream>
#include <string.h>

//next[j] = k 代表p[j]之前的模式串子串中，有长度为k的相同前缀和后缀
void GetNext(char* find, int* next, int length) {
	if (find == 0 || next == 0 || length <= 0) {
		return;
	}
	int i = 0;	//指向相同前缀的末尾
	int j = 1;	//指向相同后缀的末尾
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

//返回首次匹配的index
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
