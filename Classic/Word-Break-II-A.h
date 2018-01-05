#ifndef WORD_BREAK_II_A_H_
#define WORD_BREAK_II_A_H_

/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences. For example, given s ="catsanddog",
 * dict =["cat", "cats", "and", "sand", "dog"]. A solution is["cats and dog", "cat sand dog"].
 */
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool match(string& s, int index, string subStr) {
        if (subStr.length() > s.length() - index) {
            return false;
        }
        unsigned int i = 0;
        for (; i < subStr.length(); ++i) {
            if (subStr[i] == s[index]) {
                ++index;
            }
            else {
                break;
            }
        }
        if (i == subStr.length()) {
        	return true;
        }
        return false;
    }

    void wordBreakCore(string s, set<string> &dict, vector<string> &curWord, unsigned int matchIndex, vector<string> &result) {
        if (matchIndex == s.length()) {
            string temp;
            for (unsigned int i = 0; i < curWord.size(); ++i) {
                if (i < curWord.size()-1) {
                    temp = temp + curWord[i] + " ";
                }
                else {
                    temp += curWord[i];
                }
            }
            result.push_back(temp);
        }
        else {
            set<string>::iterator it = dict.begin();
            for (; it != dict.end(); ++it) {
                if (match(s, matchIndex, *it)) {
                    curWord.push_back(*it);
                    wordBreakCore(s, dict, curWord, matchIndex+(*it).size(), result);
                    curWord.erase(curWord.end()-1);
                }
            }
        }
    }

    vector<string> wordBreak(string s, set<string> &dict) {
        vector<string> result;
        vector<string> curWord;
        wordBreakCore(s, dict, curWord, 0, result);
        return result;
    }
};

void Test() {
	string s = "catsanddog";
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	Solution sl;
	vector<string> vec = sl.wordBreak(s, dict);
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << "\n";
	}
}



#endif /* WORD_BREAK_II_A_H_ */
