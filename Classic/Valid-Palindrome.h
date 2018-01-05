#ifndef VALID_PALINDROME_H_
#define VALID_PALINDROME_H_

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example, "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.length() <= 1) {
			return true;
		}
		int length = s.length();
		int i = 0;
		int j = length - 1;
		bool isPalindrome = true;
		while (i < j) {
			while (i < length && !isAlphaNumeric(s[i])) {
				++i;
			}
			while (j >= 0 && !isAlphaNumeric(s[j])) {
				--j;
			}
			if (i >= length || j < 0) {
				break;
			}
			if (s[i] - s[j] != 0 && s[i] - s[j] != 32 && s[i] - s[j] != -32) {
				isPalindrome = false;
				break;
			}
			++i;
			--j;
		}
		return isPalindrome;
	}

	bool isAlphaNumeric(char c) {
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			return true;
		}
		return false;
	}
};

void Test() {
	string s = "a.";
	Solution S;
	cout << S.isPalindrome(s);
}


#endif /* VALID_PALINDROME_H_ */
