/************************************************************************/
/* 
https://oj.leetcode.com/problems/jump-game/
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n < 0)
			return false;
		if (n == 1)
			return true;

		int maxreach = A[0];
		for (int i = 1; i < n; ++i)
		{
			if (maxreach < i)
			{
				return false;
			}
			if (maxreach < A[i]+i)
			{
				maxreach = A[i] + i;
				if (maxreach >= n-1)
				{
					return true;
				}
			}
		}
		return maxreach >= n - 1;
	}
};

int main()
{
	int n = 5;
	int A[5] = { 2, 3, 1, 1, 4 };

	Solution solution;
	cout << solution.canJump(A, n);

	system("pause");
	return 0;
}