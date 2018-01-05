#ifndef TRIANGLE_H_
#define TRIANGLE_H_

/*
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers
 * on the row below.
 * For example, given the following triangle
 * [
 * 	    [2],
 * 	   [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11(i.e., 2 + 3 + 5 + 1 = 11).
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	if (triangle.size() == 0) {
    		return 0;
    	}
    	int size = triangle.size();
    	int min = 0x7fffffff;
    	minimumTotalCore(triangle, size, 0, 0, triangle[0][0], min);
    	return min;
    }

    void minimumTotalCore(vector<vector<int> > &triangle, int maxLevel, int level, int index, int sum, int &min) {
    	if (level == maxLevel-1) {
    		if (sum < min) {
    			min = sum;
    		}
    	}
    	else {
    		minimumTotalCore(triangle, maxLevel, level+1, index, sum+triangle[level+1][index], min);
    		minimumTotalCore(triangle, maxLevel, level+1, index+1, sum+triangle[level+1][index+1], min);
    	}
    }
};


#endif /* TRIANGLE_H_ */
