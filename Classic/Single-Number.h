#ifndef SINGLE_NUMBER_H_
#define SINGLE_NUMBER_H_

/*
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (A == 0 || n <= 0) {
            return 0;
        }
        int single = A[0];
        for (int i = 1; i < n; ++i) {
            single ^= A[i];
        }
        return single;
    }
};



#endif /* SINGLE_NUMBER_H_ */
