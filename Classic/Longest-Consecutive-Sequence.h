#ifndef LONGEST_CONSECUTIVE_SEQUENCE_H_
#define LONGEST_CONSECUTIVE_SEQUENCE_H_

/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example, Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
    	priority_queue<int> prique;
    	for (unsigned int i = 0; i < num.size(); ++i) {
    		prique.push(num[i]);
    	}
    	int sum = 1;
    	int pre = prique.top();
    	prique.pop();
    	int cur = 0;
    	int curSum = 1;
    	while (!prique.empty()) {
    		cur = prique.top();
    		if (cur == pre-1) {
    			++curSum;
    			pre = cur;
    		}
    		else if (cur == pre) {
    			;
    		}
    		else {
    			if (curSum > sum) {
    				sum = curSum;
    			}
    			curSum = 1;
    			pre = cur;
    		}
    		prique.pop();
    	}
    	if (curSum > sum) {
			sum = curSum;
		}
    	return sum;
    }
};


#endif /* LONGEST_CONSECUTIVE_SEQUENCE_H_ */
