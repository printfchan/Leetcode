/************************************************************************/
/* 
https://oj.leetcode.com/problems/jump-game-ii/
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		if (n <= 1)
			return 0;

		vector<int> B(n);
		for (int i = 0; i < n; ++i)
			B[i] = 0;
		
		int prei = 0;
		int curi = 0;
		int max_reach = A[0];
		if (max_reach >= n - 1)
		{
			B[n - 1] = B[prei] + 1;
			return B[n - 1];
		}
		for (int i = 1; i < n;)
		{
			int nextp = i;
			
			for (; i <= A[prei] + prei; ++i)
			{
				if (i > n-1)
					break;

				if (B[i] == 0)
				{
					B[i] = B[prei] + 1;
				}
				if (A[i] + i > max_reach)
				{
					max_reach = A[i] + i;
					nextp = i;
				}
				if (max_reach >= n - 1)
				{
					return B[i] + 1;
				}
			}
			prei = nextp;
		}
		return B[n - 1];
	}
};

int main()
{
	int A[] = {2, 3, 6, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1};
	//int A[] = {1, 2};
	//int A[] = {3, 2, 1};
	//int A[] = {1, 1, 1, 1};

	Solution solution;
	cout << solution.jump(A, sizeof(A) / sizeof(A[0]));

	system("pause");
	return 0;
}