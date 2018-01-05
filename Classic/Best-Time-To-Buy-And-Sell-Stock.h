#ifndef BEST_TIME_TO_BUY_AND_SELL_STOCK_H_
#define BEST_TIME_TO_BUY_AND_SELL_STOCK_H_

/*
 * Say you have an array for which the i th element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if (prices.size() <= 1) {
    		return 0;
    	}
    	int profit = 0;
    	int size = prices.size();
        int min[size];
        int max[size];
        min[0] = prices[0];
        for (int i = 1; i < size; ++i) {
        	if (prices[i] < min[i-1]) {
        		min[i] = prices[i];
        	}
        	else {
        		min[i] = min[i-1];
        	}
        }
        max[size-1] = prices.back();
        for (int i = size-2; i >= 0; --i) {
        	if (prices[i] > max[i+1]) {
        		max[i] = prices[i];
        	}
        	else {
        		max[i] = max[i+1];
        	}
        }
        for (int i = 0; i < size; ++i) {
        	int diff = max[i] - min[i];
        	if (diff > profit) {
        		profit = diff;
        	}
        }
        return profit;
    }
};




#endif /* BEST_TIME_TO_BUY_AND_SELL_STOCK_H_ */
