/************************************************************************/
/*
https://oj.leetcode.com/problems/search-for-a-range/
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int BiSearch(int A[], int n, int target, bool first)
	{
		if (n < 1)
			return -1;
		if (n == 1)
		{
			return (A[0] == target ? 0 : -1);
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
				// get the first
				if (first)
				{
					if (mid == 0)
					{
						return mid;
					}
					else if (A[mid - 1] != target)
					{
						return mid;
					}
					else
					{
						right = mid - 1;
					}
				}
				else
				{
					if (mid == n - 1)
					{
						return mid;
					}
					else if (A[mid + 1] != target)
					{
						return mid;
					}
					else
					{
						left = mid + 1;
					}
				}
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
		if (first)
		{
			if (A[left] == target)
			{
				return left;
			}
			return -1;
		}
		else{
			if (A[right] == target)
			{
				return right;
			}
			return -1;
		}
	}
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> range;

		if (n < 1)
		{
			range.push_back(-1);
			range.push_back(-1);
			return range;
		}
		if (n == 1)
		{
			if (A[0] == target)
			{
				range.push_back(0);
				range.push_back(0);
			}
			else
			{
				range.push_back(-1);
				range.push_back(-1);
			}
			return range;
		}

		int first = BiSearch(A, n, target, true);
		int last = BiSearch(A, n, target, false);

		range.push_back(first);
		range.push_back(last);

		return range;
	}
};

int main()
{
	/*int A[] = { 5, 7, 7, 8, 8, 10 };
	int target = 4;*/

	int A[] = {1, 4};
	int target = 3;

	Solution solution;
	vector<int> result = solution.searchRange(A, sizeof(A) / sizeof(A[0]), target);

	cout << result[0] << " " << result[1];
	system("pause");
	return 0;
}