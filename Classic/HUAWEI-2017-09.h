#ifndef HUAWEI_2017_09_H_
#define HUAWEI_2017_09_H_

/*
 * 题目描述
 * 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
 * 输入描述:
 * 输入一个int型整数
 * 输出描述:
 * 按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
 *
 * 示例
 * 输入
 * 9876673
 *
 * 输出
 * 37689
 */
void Solve() {
	int n = 0;
	std::cin >> n;
	bool flag[10];
	for (int i = 0; i < 10; ++i) {
		flag[i] = false;
	}
	while (n % 10 == 0) {
		n = n / 10;
	}
	while (n != 0) {
		if (!flag[n % 10]) {
			std::cout << n % 10;
			flag[n % 10] = true;
		}
		n = n / 10;
	}
}


#endif /* HUAWEI_2017_09_H_ */
