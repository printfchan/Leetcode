/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

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
		bool exist = false;
		for (int i = 1; i < n; ++i)
		{
			if (A[i] != A[index] || !exist)
			{
				if (A[i] == A[index])
					exist = true;
				else
					exist = false;
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
	int A[n] = {1, 1, 1, 2, 2, 3};
	Solution solution;
	cout << solution.removeDuplicates(A, n);

	system("pause");
	return 0;
}