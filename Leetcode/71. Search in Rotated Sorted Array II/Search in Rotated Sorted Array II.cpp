/************************************************************************/
/* 
https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(int A[], int n, int target) {
		if (n < 1)
			return false;

		int left, right, mid;
		left = 0;
		right = n - 1;

		while (left <= right)
		{
			mid = left + ((right - left) >> 1);
			if (A[mid] == target)
				return true;

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
				// 4, 1, 2, 3
				if (A[mid] < A[right])
				{
					// 比mid还要小，确定在mid左边
					if (A[mid] > target)
					{
						right = mid - 1;
					}
					else{
						// target在mid与right之间
						if (A[right] >= target)
						{
							left = mid + 1;
						}
						else{
							right = mid - 1;
						}
					}
				}
				else
				{
					// 2, 3, 4, 1
					if (A[mid] > A[right]){
						// target比mid还要大，target必然在mid右边
						if (A[mid] < target)
						{
							left = mid + 1;
						}
						else{
							// target比左边最小的要大或等于
							if (A[left] <= target)
							{
								right = mid - 1;
							}
							else{
								left = mid + 1;
							}
						}
					}
					else{
						// 无法判断
						if (A[left] != target)
						{
							left++;
						}
						right--;
					}
				}
			}
		}

		return false;
	}
};

int main()
{
	/*const int n = 6;
	int A[n] = { 1, 1, 1, 2, 2, 3 };
	int target = 2;*/

	/*const int n = 3;
	int A[n] = { 3, 1, 1 };
	int target = 3;*/

	const int n = 4;
	int A[n] = { 1, 3, 1, 1 };
	int target = 3;

	Solution solution;
	cout << solution.search(A, n, target);

	system("pause");
	return 0;
}