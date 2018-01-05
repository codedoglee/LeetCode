#ifndef WORD_BREAK_II_B_H_
#define WORD_BREAK_II_B_H_

/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences. For example, given s ="catsanddog",
 * dict =["cat", "cats", "and", "sand", "dog"]. A solution is["cats and dog", "cat sand dog"].
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int> > dp;
	vector<int> vec;
	vector<string> result;
	vector<string> temp;

    vector<string> wordBreak(string s, set<string> &dict) {
    	for (unsigned int i = 0; i < s.size(); ++i) {
    		for (unsigned int j = i; j < s.size(); ++j) {
    			vec.push_back(match(s.substr(i, j-i+1), dict));
    		}
			dp.push_back(vec);
			vec.clear();
    	}
    	wordBreakCore(s, s.size()-1);
    	return result;
    }

    int match(string s, set<string> &dict) {
    	if (dict.find(s) != dict.end()) {
    		return 1;
    	}
    	return 0;
    }

    void wordBreakCore(string s, int i) {
    	if (i == -1) {
    		string ss;
    		for (int i = temp.size()-1; i >= 0; --i) {
    			if (i > 0) {
    				ss += (temp[i] + " ");
    			}
    			else {
    				ss += temp[i];
    			}
    		}
    		result.push_back(ss);
    	}
    	else {
    		for (int j = i; j >= 0; --j) {
    			if (dp[j][i-j]) {
    				temp.push_back(s.substr(j, i-j+1));
    				wordBreakCore(s, j-1);
    				temp.pop_back();
    			}
    		}
    	}
    }
};

void Test() {
	string str = "ab";
	set<string> dict;
	dict.insert("a");
	dict.insert("b");
	Solution st;
	vector<string> result = st.wordBreak(str, dict);
	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\n";
	}
}



#endif /* WORD_BREAK_II_B_H_ */
