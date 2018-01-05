#ifndef JD_UNIONSET_H_
#define JD_UNIONSET_H_

/*
 * 题目描述
 * 给你两个集合，要求{A} + {B}。 注：同一个集合中不会有两个相同的元素。
 * 输入描述:
 * 每组输入数据分为三行,第一行有两个数字n,m(0 ≤ n,m ≤ 10000)，分别表示集合A和集合B的元素个数。后两行分别表示集合A和集合B。
 * 每个元素为不超过int范围的整数,每个元素之间有个空格隔开。
 *
 * 输出描述:
 * 针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之间有一个空格隔开,行末无空格。
 *
 * 示例
 * 输入
 * 3 3
 * 1 3 5
 * 2 4 6
 *
 * 输出
 * 1 2 3 4 5 6
 */
#include <iostream>
#include <set>

void Solve() {
	int n = 0;
	int m = 0;
	std::set<int> s;
	int temp = 0;

	std::cin >> n >> m;
	for (int i = 0; i < n + m; ++i) {
		std::cin >> temp;
		s.insert(temp);
	}

	std::set<int>::iterator it = s.begin();
	for (; it != s.end(); ++it) {
		std::cout << *it;
		if (*it != *(s.rbegin())) {
			std::cout << " ";
		}
	}
}


#endif /* JD_UNIONSET_H_ */
