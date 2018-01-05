#ifndef WORD_BREAK_H_
#define WORD_BREAK_H_

/*
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * For example, given s = "leetcode", dict = ["leet", "code"].
 * Return true because "leetcode" can be segmented as "leet code".
 */
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, set<string> &dict) {
    	bool *dp = new bool[s.size()+1];
    	for (unsigned int i = 0; i <= s.size(); ++i) {
    		dp[i] = 0;
    	}
    	dp[0] = true;
    	for (unsigned int i = 1; i <= s.size(); ++i) {
    		for (unsigned int j = 0; j < i; ++j) {
    			dp[i] = dp[i] | (dp[j] && match(s.substr(j, i-j), dict));
    		}
    	}
    	return dp[s.size()];
    }
    bool match(string s, set<string> &dict) {
    	if (dict.find(s) != dict.end()) {
    		return true;
    	}
    	return false;
    }
};




#endif /* WORD_BREAK_H_ */
