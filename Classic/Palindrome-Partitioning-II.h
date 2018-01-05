#ifndef PALINDROME_PARTITIONING_II_H_
#define PALINDROME_PARTITIONING_II_H_

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * For example, given s = "aab", Return 1. since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
#include <vector>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		if (s.length() == 0) {
			return 0;
		}
		int dp[s.length()];
		for (unsigned int i = 0; i < s.length(); ++i) {
			if (isPalindrome(s.substr(0, i+1))) {
				dp[i] = 0;	//不需要切割
			}
			else {
				dp[i] = i;	//最大切割次数
			}
		}
		for (int i = 1; i < s.length(); ++i) {
			if (dp[i] == i) {
				for (int j = 0; j < i; ++j) {
					if (isPalindrome(s.substr(j+1, i-j)) && dp[j] + 1 < dp[i]) {
						dp[i] = dp[j] + 1;
					}
				}
			}
		}
		return dp[s.length()-1];
	}

    bool isPalindrome(string s) {
    	int i = 0;
    	int j = s.length()-1;
    	bool result = true;
    	while (i < j) {
    		if (s[i] != s[j]) {
    			result = false;
    			break;
    		}
    		++i;
    		--j;
    	}
    	return result;
    }
};


#endif /* PALINDROME_PARTITIONING_II_H_ */
