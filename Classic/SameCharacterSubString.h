#ifndef SAMECHARACTERSUBSTRING_H_
#define SAMECHARACTERSUBSTRING_H_

/*
 * 度度熊找子串
 * 度度熊收到了一个只有小写字母的字符串S，他对S的子串产生了兴趣，S的子串为S中任意连续的一段。
 * 他发现，一些子串只由一种字母构成，他想知道在S中一共有多少种这样的子串。
 * 例如在串”aaabbaa”中，度度熊想找的子串有”a”,”aa”,”aaa”,”b”,”bb”五种。（只考虑子串的种数，相同的子串在多个位置出现只算一次）
 * 输入：
 * 输入只有一行，一个字符串，长度不超过100000，只由小写字母组成
 * 样例输入：aaabbaa
 * 输出：
 * 输出一行，符合要求的子串种数
 * 样例输出5
 */
#include <iostream>

#define MAXLEN 100001

void SameCharacterSubString() {
	int counter[26];
	char buf[MAXLEN];
	scanf("%s", buf);
	char* ch = buf;
	char curChar = buf[0];
	int curLength = 0;
	while (*ch != '\0') {
		if (curChar == *ch) {
			++curLength;
			++ch;
		}
		else {
			int index = curChar - 'a';
			if (counter[index] < curLength) {
				counter[index] = curLength;
			}
			curLength = 1;
			curChar = *ch;
			++ch;
		}
	}
	int sum = 0;
	for (int i = 0; i < 26; ++i) {
		sum += counter[i];
	}
	std::cout << sum << std::endl;
}


#endif /* SAMECHARACTERSUBSTRING_H_ */
