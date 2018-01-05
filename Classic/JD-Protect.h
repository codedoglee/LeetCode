#ifndef JD_PROTECT_H_
#define JD_PROTECT_H_

/*
 * 题目描述
 * 战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。
 * 首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上设置一个观察哨，
 * 日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，
 * 若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰上的烽烟是否点燃。
 * 由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡的条件下，
 * 一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，一端的岗哨一定可以发现一端点燃的烽烟。
 * 小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。
 *
 * 输入描述:
 * 输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，第二行为n个整数，
 * 依次表示为小山的高度h（1<=h<=10^9）
 * 输出描述:
 * 对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。
 *
 * 示例
 * 输入
 * 5
 * 1 2 4 5 3
 *
 * 输出
 * 7
 */
#include <iostream>
#include <string.h>

const int N = 1000001;

int buf[N];			//原始数据
int numbers[N];		//调整后的数据
int right[N];		//右边大于等于它的下标
int left[N];		//左边大于等于它的下标
int count[N];		//小山高度相同时动态规划

void Solve() {
	memset(right, 0, sizeof(right));
	memset(left, 0, sizeof(left));
	memset(count, 0, sizeof(count));

	int n = 0;
	int max = 0;			//最大值
	int firstMaxIndex = 0;	//记录数组第一个最大值

	std::cin >> n;
	if (n <= 2) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> buf[i];
		if (buf[i] > max) {
			max = buf[i];
			firstMaxIndex = i;
		}
	}

	//将数组转化为首元素为最大值，即进行一次旋转，最高的山在位置0
	for (int i = 0; i < n; ++i) {
		numbers[i] = buf[(firstMaxIndex+i)%n];
	}

	left[0] = 0;

	//向右找左边界，找到第一个大于自己的下标
	for (int i = 1; i < n; ++i) {
		int index = i-1;
		while (index > 0 && numbers[index] <= numbers[i]) {
			index = left[index];
		}
		left[i] = index;
	}

	right[n-1] = n;

	//向左找右边界，找到第一个大于或等于自身的下标
	for (int i = n-2; i >= 0; --i) {
		int index = i+1;
		while (index < n && numbers[index] < numbers[i]) {
			index = right[index];
		}
		right[i] = index;
		if (index < n &&  numbers[index] == numbers[i]) {
			count[i] = count[index] + 1;
			right[i] = right[index];
		}
	}

	long long result = 0;
	for (int i = 1; i < n; ++i) {
		result += count[i] + 2;
		if (left[i] == 0 && right[i] == n) {
			--result;
		}
	}

	std::cout << result;
}


#endif /* JD_PROTECT_H_ */
