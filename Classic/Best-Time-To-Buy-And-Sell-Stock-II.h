#ifndef BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_
#define BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_

/*
 * Say you have an array for which the i th element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple
 * transactions at the same time (ie, you must sell the stock before you buy again).
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
        int i = 0;
        int j = 1;
        while (j < prices.size()) {
        	if (prices[j] < prices[j-1]) {
        		profit += prices[j-1] - prices[i];
        		i = j;
        	}
        	++j;
        	if (j == prices.size()) {
        		profit += prices[j-1] - prices[i];
        	}
        }
        return profit;
    }
};


#endif /* BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_ */
