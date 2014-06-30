/************************************************************************/
/* 
https://oj.leetcode.com/problems/merge-sorted-array/
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int pa = m-1;
		int pb = n-1;
		int p = m + n - 1;

		while (pa >= 0 && pb >= 0)
		{
			if (A[pa] > B[pb])
			{
				A[p] = A[pa];
				pa--;
			}
			else{
				A[p] = B[pb];
				pb--;
			}
			p--;
		}
		if (pa < 0)
		{
			while (pb>=0)
			{
				A[p] = B[pb];
				pb--;
				p--;
			}
		}
	}
};

int main()
{
	const int m = 5;
	const int n = 7;
	int A[m + n] = { 2, 3, 7, 11, 13 };
	int B[n] = { 1, 6, 8, 9, 12, 14, 15 };

	Solution solution;
	solution.merge(A, m, B, n);

	for (int i = 0; i < (m + n); ++i)
	{
		cout << A[i] << ' ';
	}

	system("pause");
	return 0;
}