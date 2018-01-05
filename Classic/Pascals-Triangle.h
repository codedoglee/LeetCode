#ifndef PASCALS_TRIANGLE_H_
#define PASCALS_TRIANGLE_H_

/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 * [
 * 	    [1],
 * 	   [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > result;
    	vector<int> row;
    	row.push_back(1);
    	for (int i = 0; i < numRows; ++i) {
    		result.push_back(row);
    	}
    	for (int i = 1; i < numRows; ++i) {
    		for (int j = i; j < numRows; ++j) {
    			if (j == i) {
    				result[j].push_back(1);
    			}
    			else {
    				result[j].push_back(result[j-1][i-1] + result[j-1][i]);
    			}
    		}
    	}
    	return result;
    }
};



#endif /* PASCALS_TRIANGLE_H_ */
