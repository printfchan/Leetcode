/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 0)
			return 0;
		
		if (n == 0 || n == 1)
			return n;

		int index = 0;
		int m = 1;
		for (int i = 1; i < n; ++i)
		{
			if (A[i] != A[index])
			{
				A[index + 1] = A[i];
				index++;
				m++;
			}
		}
		
		return m;
	}
};

int main()
{
	const int n = 6;
	int A[n] = { 1, 1, 1, 2, 2, 3 };
	Solution solution;
	int m = solution.removeDuplicates(A, n);

	for (int i = 0; i < m; ++i)
	{
		cout << A[i] << " ";
	}
	
	system("pause");
	return 0;
}