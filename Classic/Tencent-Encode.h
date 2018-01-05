#ifndef TENCENT_ENCODE_H_
#define TENCENT_ENCODE_H_

/*
 * 题目描述
 * 假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
 * 形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy
 * 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
 * 输入描述:
 * 输入一个待编码的字符串,字符串长度小于等于100.
 * 输出描述:
 * 输出这个编码的index
 *
 * 示例
 * 输入
 * baca
 *
 * 输出
 * 16331
 */
#include <iostream>
#include <cstring>

void Solve() {
	char buf[101];
	scanf("%s", buf);
	int len = strlen(buf);
	int h = 0;
	while (len < 4) {
		buf[len] = 'a';
		++len;
		++h;
	}
	int index = 0;
	int help[4] = {1, 26, 651, 16276};
	for (int i = 0; i < len; ++i) {
		index += (buf[i] - 'a') * help[len-1-i] + 1;
	}
	std::cout << index-1-h;
}



#endif /* TENCENT_ENCODE_H_ */
