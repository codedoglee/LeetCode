#ifndef PALINDROME_PARTITIONING_H_
#define PALINDROME_PARTITIONING_H_

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * For example, given s = "aab", Return [ ["aa","b"], ["a","a","b"] ]
 */
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> result;
	vector<string> temp;

    vector<vector<string>> partition(string s) {
    	partitionCore(s, 0);
    	return result;
    }

    void partitionCore(string s, int i) {
    	if (i == s.length()) {
    		result.push_back(temp);
    	}
    	else {
    		for (int j = i; j < s.length(); ++j) {
    			if (isPalindrome(s.substr(i, j-i+1))) {
    				temp.push_back(s.substr(i, j-i+1));
    				partitionCore(s, j+1);
    				temp.pop_back();
    			}
    		}
    	}
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


#endif /* PALINDROME_PARTITIONING_H_ */
