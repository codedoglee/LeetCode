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
        int ones = A[0];	//��¼ֻ���ֹ�1�ε�bits
        int twos = 0;	//��¼ֻ���ֹ�2�ε�bits
        int threes = 0;
        for (int i = 1; i < n; ++i) {
        	twos |= (ones & A[i]);
        	ones ^= A[i];
        	threes = ones & twos;	//ones��twos�ж�Ϊ1��������3��
        	ones &= ~threes;	//Ĩȥ������3�ε�bits
        	twos &= ~threes;	//Ĩȥ������3�ε�bits
        }
        return ones;
    }
};


#endif /* SINGLE_NUMBER_II_H_ */
