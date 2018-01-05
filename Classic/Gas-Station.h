#ifndef GAS_STATION_H_
#define GAS_STATION_H_

/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
 * its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * Note: The solution is guaranteed to be unique.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	if (gas.empty() || cost.empty() || gas.size() != cost.size()) {
    		return -1;
    	}
    	int n = gas.size();
    	int start = 0;
    	int end = 1 % n;
    	int curGas = gas[0] - cost[0];
    	while (start != end) {
    		if (curGas >= 0) {
    			curGas += gas[end];
    			curGas -= cost[end];
    			++end;
    			end = end % n;
    		}
    		else {
    			--start;
    			start = (start + n) % n;
    			curGas += gas[start];
    			curGas -= cost[start];
    		}
    	}
    	if (curGas < 0) {
    		return -1;
    	}
    	return start;
    }
};


#endif /* GAS_STATION_H_ */
