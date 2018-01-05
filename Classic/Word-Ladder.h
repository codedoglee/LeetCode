#ifndef WORD_LADDER_H_
#define WORD_LADDER_H_

/*
 * Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start
 * to end, such that: Only one letter can be changed at a time Each intermediate word must exist in the dictionary
 * For example, Given: start ="hit", end ="cog", dict =["hot","dot","dog","lot","log"]
 * As one shortest transformation is"hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
 * Note: Return 0 if there is no such transformation sequence. All words have the same length.
 * All words contain only lower case alphabetic characters.
 */
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, set<string> &dict) {
    	set<string> dict_copy = dict;
    	queue<string> q;
    	q.push(start);
    	int result = 1;
    	while (!q.empty()) {
    		int qsize = q.size();	//当前队列大小
    		while (qsize > 0) {
    			--qsize;
    			string cur = q.front();
				q.pop();
				for (unsigned int i = 0; i < cur.size(); ++i) {
					char ch = cur[i];
					for (int j = 0; j < 26; ++j) {
						cur[i] = 'a' + j;
						if (cur.compare(end) == 0) {
							return result + 1;
						}
						if (dict_copy.find(cur) != dict_copy.end()) {
							q.push(cur);
							dict_copy.erase(cur);
						}
					}
					cur[i] = ch;
				}
    		}
    		++result;
    	}
    	return 0;
    }
};

void Test() {
	string start ="hit";
	string end = "cog";
	set<string> s;
	s.insert("hot");
	s.insert("dot");
	s.insert("dog");
	s.insert("lot");
	s.insert("log");
	Solution S;
	cout << S.ladderLength(start, end, s);
}


#endif /* WORD_LADDER_H_ */
