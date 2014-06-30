/************************************************************************/
/* 
https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		if (n < 1)
			return -1;

		int left, right, mid;
		left = 0;
		right = n - 1;

		while (left <= right)
		{
			mid = left + ((right - left) >> 1);
			if (A[mid] == target)
				return mid;
			
			if (A[left] < A[right])
			{
				if (A[mid] > target)
				{
					right = mid - 1;
				}
				if (A[mid] < target)
				{
					left = mid + 1;
				}
			}
			else{
				if (A[mid] < A[right])
				{
					if (A[mid] > target)
					{
						right = mid - 1;
					}
					else{
						if (A[right] >= target)
						{
							left = mid + 1;
						}
						else{
							right = mid - 1;
						}
					}
				}
				else{
					if (A[mid] < target)
					{
						left = mid + 1;
					}
					else{
						if (A[left] <= target)
						{
							right = mid - 1;
						}
						else{
							left = mid + 1;
						}
					}
				}
			}
		}
		
		return -1;
	}
};

int main()
{
	/*const int n = 7;
	int A[n] = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 3;*/

	const int n = 1;
	int A[n] = { 1 };
	int target = 2;

	Solution solution;
	cout << solution.search(A, n, target);

	system("pause");
	return 0;
}