#ifndef DIDI_TRANSLATERADIX_H_
#define DIDI_TRANSLATERADIX_H_

/*
 * 给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
 * 输入描述:
 * 输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
 * 输出描述:
 * 为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
 *
 * 示例
 * 输入
 * 7 2
 *
 * 输出
 * 111
 */
#include <iostream>
#include <vector>

void Solve() {
	int n = 0;
	int radix = 0;
	std::cin >> n >> radix;
	std::vector<char> result;
	int p = 0;
	if (n < 0) {
		n = (-1) * n;
		std::cout << "-";
	}
	while (n != 0) {
		p = n % radix;
		n /= radix;
		if (p >= 0 && p <= 9) {
			result.push_back('0' + p);
		}
		if (p >= 10 && p < radix) {
			 result.push_back('A' + p - 10);
		}
	}
	for (int i = result.size()-1; i >= 0; --i) {
		std::cout << result[i];
	}
}


#endif /* DIDI_TRANSLATERADIX_H_ */
