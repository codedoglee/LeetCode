#ifndef SAMECHARACTERSUBSTRING_H_
#define SAMECHARACTERSUBSTRING_H_

/*
 * �ȶ������Ӵ�
 * �ȶ����յ���һ��ֻ��Сд��ĸ���ַ���S������S���Ӵ���������Ȥ��S���Ӵ�ΪS������������һ�Ρ�
 * �����֣�һЩ�Ӵ�ֻ��һ����ĸ���ɣ�����֪����S��һ���ж������������Ӵ���
 * �����ڴ���aaabbaa���У��ȶ������ҵ��Ӵ��С�a��,��aa��,��aaa��,��b��,��bb�����֡���ֻ�����Ӵ�����������ͬ���Ӵ��ڶ��λ�ó���ֻ��һ�Σ�
 * ���룺
 * ����ֻ��һ�У�һ���ַ��������Ȳ�����100000��ֻ��Сд��ĸ���
 * �������룺aaabbaa
 * �����
 * ���һ�У�����Ҫ����Ӵ�����
 * �������5
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
