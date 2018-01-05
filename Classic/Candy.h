#ifndef CANDY_H_
#define CANDY_H_

/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int len = ratings.size();
        int num[len];
        for (int i = 0; i < len; ++i) {
        	num[i] = 1;
        }
        int result = len;
        int give = 0;
        while (true) {
        	for (int i = 1; i < len; ++i) {
        		if (ratings[i] > ratings[i-1] && num[i] <= num[i-1]) {
        			++num[i];
        			++give;
        		}
        	}
        	for (int i = len-1; i >= 1; --i) {
        		if (ratings[i-1] >ratings[i] && num[i-1] <= num[i]) {
        			++num[i-1];
        			++give;
        		}
        	}
        	result += give;
        	if (give == 0) {
        		break;
        	}
        	give = 0;
        }
        return result;
    }
};



#endif /* CANDY_H_ */
