/************************************************************************/
/*
https://oj.leetcode.com/problems/search-insert-position/
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (n < 1)
			return 0;
		if (n == 1)
		{
			return (A[0] < target ? 1 : 0);
		}

		int left, right;
		int mid;
		left = 0;
		right = n - 1;
		while (left < right)
		{
			mid = left + ((right - left) >> 1);
			if (A[mid] == target)
			{
				return mid;
			}
			else if (A[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (A[left] >= target)
		{
			return left;
		}
		if (A[right] < target)
		{
			return right + 1;
		}
	}
};

int main()
{
	//int A[] = { 1, 3, 5, 6 };
	//int target = 0; // 5, 2, 7, 0; 2, 1, 4, 0

	int A[] = { 1, 3 };
	int target = 3;

	Solution solution;
	cout << solution.searchInsert(A, sizeof(A) / sizeof(A[0]), target);

	system("pause");
	return 0;
}