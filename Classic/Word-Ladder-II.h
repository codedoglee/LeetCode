#ifndef WORD_LADDER_II_H_
#define WORD_LADDER_II_H_

/*
 * Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end,
 * such that: Only one letter can be changed at a time, Each intermediate word must exist in the dictionary
 * For example, Given: start = "hit", end = "cog",  dict = ["hot","dot","dog","lot","log"]
 * Return [	["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"] ]
 * Note: All words have the same length. All words contain only lower case alphabetic characters.
 */
#pragma once

#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
	vector<string> cur;
	vector<vector<string> > result;
	vector<vector<string> > levelVec;

	vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
		if (diffOne(start, end)) {
			cur.push_back(start);
			cur.push_back(end);
			result.push_back(cur);
			return result;
		}
		bool can = getLevel(start, end, dict, levelVec);
		if (!can) {
			return result;
		}
		int levelNum = levelVec.size();
		for (vector<string>::iterator i = levelVec[levelNum - 1].begin(); i != levelVec[levelNum - 1].end();) {
			if (!diffOne(*i, end)) {
				i = levelVec[levelNum - 1].erase(i);
			}
			else {
				++i;
			}
		}
		for (int i = levelNum - 1; i >= 1; --i) {
			for (vector<string>::iterator iter1 = levelVec[i - 1].begin(); iter1 != levelVec[i - 1].end();) {
				bool needDel = true;
				vector<string>::iterator iter2 = levelVec[i].begin();
				for (; iter2 != levelVec[i].end(); ++iter2) {
					if (diffOne(*iter1, *iter2)) {
						needDel = false;
						break;
					}
				}
				if (needDel) {
					iter1 = levelVec[i - 1].erase(iter1);
				}
				else {
					++iter1;
				}
			}
		}

		cur.push_back(start);
		search(start, end, 0, levelNum);
		return result;
	}

	void search(string start, string end, int curLevel, int maxLevel) {
		if (curLevel == maxLevel - 1) {
			for (unsigned int i = 0; i < levelVec[curLevel].size(); ++i) {
				if (diffOne(start, levelVec[curLevel][i])) {
					cur.push_back(levelVec[curLevel][i]);
					cur.push_back(end);
					result.push_back(cur);
					cur.pop_back();
					cur.pop_back();
				}
			}
		}
		else {
			for (unsigned int i = 0; i < levelVec[curLevel].size(); ++i) {
				if (diffOne(start, levelVec[curLevel][i])) {
					cur.push_back(levelVec[curLevel][i]);
					search(levelVec[curLevel][i], end, curLevel + 1, maxLevel);
					cur.pop_back();
				}
			}
		}
	}

	inline bool diffOne(string s1, string s2) {
		if (s1.length() == 0 || s2.length() == 0 || s1.length() != s2.length()) {
			return false;
		}
		int diff = 0;
		for (unsigned int i = 0; i < s1.length(); ++i) {
			if (s1[i] != s2[i]) {
				++diff;
			}
			if (diff >= 2) {
				return false;
			}
		}
		if (diff == 1) {
			return true;
		}
		return false;
	}

	bool getLevel(string start, string end, set<string> &dict, vector<vector<string> >& levelVec) {
		set<string> dict_copy = dict;
		queue<string> q;
		q.push(start);
		int level = 1;
		bool finish = false;
		vector<string> temp;
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
							finish = true;
						}
						if (dict_copy.find(cur) != dict_copy.end()) {
							q.push(cur);
							temp.push_back(cur);
							dict_copy.erase(cur);
						}
					}
					cur[i] = ch;
				}
			}
			if (finish) {
				return true;
			}
			levelVec.push_back(temp);
			temp.clear();
			++level;
		}
		return false;
	}
};

void Test() {
	string start = "hot";
	string end = "dog";
	set<string> s;
	s.insert("hot");
	s.insert("cog");
	s.insert("dog");
	s.insert("tot");
	s.insert("hog");
	s.insert("hop");
	s.insert("pot");
	s.insert("dot");
	Solution S;
	vector<vector<string> > temp = S.findLadders(start, end, s);
	for (unsigned int i = 0; i < temp.size(); ++i) {
		for (unsigned int j = 0; j < temp[i].size(); ++j) {
			cout << temp[i][j].c_str() << " ";
		}
		cout << "\n";
	}
}


#endif /* WORD_LADDER_II_H_ */
