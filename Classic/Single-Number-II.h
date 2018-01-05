#ifndef SINGLE_NUMBER_II_H_
#define SINGLE_NUMBER_II_H_

/*
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (A == 0 || n <= 0) {
        	return 0;
        }
        int ones = A[0];	//记录只出现过1次的bits
        int twos = 0;	//记录只出现过2次的bits
        int threes = 0;
        for (int i = 1; i < n; ++i) {
        	twos |= (ones & A[i]);
        	ones ^= A[i];
        	threes = ones & twos;	//ones和twos中都为1即出现了3次
        	ones &= ~threes;	//抹去出现了3次的bits
        	twos &= ~threes;	//抹去出现了3次的bits
        }
        return ones;
    }
};


#endif /* SINGLE_NUMBER_II_H_ */
