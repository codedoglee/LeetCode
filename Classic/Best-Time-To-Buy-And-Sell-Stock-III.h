#ifndef BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H_
#define BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H_

/*
 * Say you have an array for which the i th element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
		int size = prices.size();
		int max[size][size];	//max[i][j]代表i-j天的最大价格
		for (int i = 0; i < size; ++i) {
			max[i][i] = prices[i];
		}
		for (int i = 0; i < size-1; ++i) {
			for (int j = i+1; j < size; ++j) {
				if (prices[j] > max[i][j-1]) {
					max[i][j] = prices[j];
				}
				else {
					max[i][j] = max[i][j-1];
				}
			}
		}

		int profitMatrix[size][size];	//profitMatrix[i][j]代表i天买入，j天之前售出可获利
		for (int i = 0; i < size; ++i) {
			profitMatrix[i][i] = 0;
		}
		for (int i = 0; i < size-1; ++i) {
			for (int j = i+1; j < size; ++j) {
				profitMatrix[i][j] = profitMatrix[i][j-1];
				if (max[i][j] > max[i][j-1]) {
					profitMatrix[i][j] += (max[i][j] - max[i][j-1]);
				}
			}
		}

		int profitArray1[size];	//profitArray1[i]代表0-i天买卖一次可获利
		int profitArray2[size];	//profitArray2[i]代表i-(size-1)天买卖一次可获利
		profitArray1[0] = 0;
		for (int i = 1; i < size; ++i) {
			profitArray1[i] = profitArray1[i-1];
			for (int j = 0; j <= i; ++j) {
				if (profitMatrix[j][i] > profitArray1[i]) {
					profitArray1[i] = profitMatrix[j][i];
				}
			}
		}
		profitArray2[size-1] = 0;
		for (int i = size-2; i >= 0; --i) {
			profitArray2[i] = profitArray2[i+1];
			if (profitMatrix[i][size-1] > profitArray2[i]) {
				profitArray2[i] = profitMatrix[i][size-1];
			}
		}

		int profit = 0;
		for (int i = 0; i < size; ++i) {
			int profit1 = profitArray1[i];
			int profit2 = profitArray2[i];
			if (profit1 + profit2 > profit) {
				profit = profit1 + profit2;
			}
		}
		return profit;
    }
};

class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int buy1 = 0x80000000, sell1 = 0, buy2 = 0x80000000, sell2 = 0;
		for(unsigned int i = 0; i < prices.size(); i++) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
};

class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}
		int size = prices.size();
		int left[size];
		int right[size];

		left[0] = 0;
		int leftMin = prices[0];
		int leftMaxProfit = 0;
		for (int i = 1; i < size; ++i) {
			if (prices[i] > leftMin) {
				int temp = prices[i] - leftMin;
				if (temp > leftMaxProfit) {
					leftMaxProfit = temp;
				}
				left[i] = leftMaxProfit;
			}
			else {
				leftMin = prices[i];
				left[i] = left[i-1];
			}
		}

		right[size-1] = 0;
		int rightMax = prices[size-1];
		int rightMaxProfit = 0;
		for (int i = size-2; i>= 0; --i) {
			if (prices[i] > rightMax) {
				rightMax = prices[i];
				right[i] = right[i+1];
			}
			else {
				int temp = rightMax - prices[i];
				if (temp > rightMaxProfit) {
					rightMaxProfit = temp;
				}
				right[i] = rightMaxProfit;
			}
		}

		int profit = 0;
		for (int i = 0 ; i < size; ++i) {
			if (left[i] + right[i] > profit) {
				profit = left[i] + right[i];
			}
		}

		return profit;
	}
};

void Test() {
	Solution3 S;
	int A[5] = {3,1};
	vector<int> vec;
	for (int i = 0; i < 2; ++i) {
		vec.push_back(A[i]);
	}
	cout << S.maxProfit(vec);
}


#endif /* BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H_ */
