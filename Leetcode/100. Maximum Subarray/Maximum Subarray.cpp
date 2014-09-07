/************************************************************************/
/*
https://oj.leetcode.com/problems/maximum-subarray/
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution,
try coding another solution using the divide and conquer approach, which is more subtle.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n <= 0)
		{
			return 0;
		}

		int result = A[0];
		int p = A[0];
		for (int i = 1; i < n; ++i)
		{
			if (p > 0)
				p = p + A[i];
			else
				p = A[i];

			if (p > result)
			{
				result = p;
			}
		}
		return result;
	}
};

int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int n = 9;
	Solution solution;
	cout << solution.maxSubArray(A, n);

	system("pause");
	return 0;
}