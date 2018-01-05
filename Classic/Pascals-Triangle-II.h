#ifndef PASCALS_TRIANGLE_II_H_
#define PASCALS_TRIANGLE_II_H_

/*
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return[1,3,3,1].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> result[2];
    	int flag = 0;
    	result[flag].push_back(1);
    	for (int i = 1; i <= rowIndex; ++i) {
    		int t_falg = flag ^ 1;
    		result[t_falg].clear();
    		for (int j = 0; j <= i; ++j) {
    			if (j == 0 || j == i) {
    				result[t_falg].push_back(1);
    			}
    			else {
    				result[t_falg].push_back(result[flag][j-1] + result[flag][j]);
    			}
    		}
    		flag ^= 1;
    	}
    	return result[flag^1];
    }
};


#endif /* PASCALS_TRIANGLE_II_H_ */
