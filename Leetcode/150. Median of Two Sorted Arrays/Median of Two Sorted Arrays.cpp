/************************************************************************/
/* 
https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (m == 0)
		{
			if (n & 1)
				return B[n / 2];
			else
				return (B[n / 2] + B[n / 2 - 1]) / 2.0;
		}
		if (n == 0)
		{
			if (m & 1)
				return A[m / 2];
			else
				return (A[m / 2] + A[m / 2 - 1]) / 2.0;
		}

		int k = (m + n) >> 1;
		if (!((m+n)&1))
		{
			k--;
		}
		int a, b;
		a = 0;
		b = 0;
		while (a < m && b < n && k > 0)
		{
			if (A[a] < B[b])
				a++;
			else
				b++;
			k--;
		}

		while (a < m && k-- > 0)
			a++;
		while (b < n && k-- > 0)
			b++;

		if (a < m && b < n)
		{
			if ((m + n) & 1)
			{
				return (A[a] < B[b] ? A[a] : B[b]);
			}
			else{
				int num1;
				int num2;
				if (A[a] < B[b])
				{
					num1 = A[a];
					a++;
				}
				else{
					num1 = B[b];
					b++;
				}

				if (a == m)
				{
					num2 = B[b];
					return (num1 + num2) / 2.0;
				}
				if (b == n)
				{
					num2 = A[a];
					return (num1 + num2) / 2.0;
				}

				if (A[a] < B[b])
				{
					num2 = A[a];
				}
				else{
					num2 = B[b];
				}
				return (num1 + num2) / 2.0;
			}
		}
		else{
			if (a == m)
			{
				if ((m + n) & 1)
				{
					return B[b];
				}else
					return (B[b] + B[b+1]) / 2.0;
			}
			else
			{
				if ((m + n) & 1)
				{
					return A[a];
				}
				else
					return (A[a] + A[a + 1]) / 2.0;
			}
		}
	}
};

int main()
{
	int A[] = { 1};
	int B[] = { 2, 3, 4, 5, 6, 7 };

	Solution solution;
	cout << solution.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0]));

	system("pause");
	return 0;
}