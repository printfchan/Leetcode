/************************************************************************/
/* 
https://oj.leetcode.com/problems/first-missing-positive/
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (n < 1)
			return 1;

		int tmp;
		for (int i = 0; i < n;)
		{
			if (A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
			{
				tmp = A[A[i]-1];
				A[A[i]-1] = A[i];
				A[i] = tmp;
			}
			else
				++i;
		}

		for (int i = 0; i < n; ++i)
		{
			if (A[i] != i+1)
			{
				return i + 1;
			}
		}
		return n + 1;
	}
};

int main()
{
	//int A[] = { 1, 1 };
	int A[] = { 1, 2, 0 };
	//int A[] = { 3, 4, -1, 1 };

	Solution solution;
	cout << solution.firstMissingPositive(A, sizeof(A) / sizeof(A[0]));

	system("pause");
	return 0;
}
