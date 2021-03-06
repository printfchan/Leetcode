/************************************************************************/
/* 
https://oj.leetcode.com/problems/sort-colors/
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, 
then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(int A[], int n) {

		int x, y, z;
		x = y = z = -1;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == 2)
			{
				z = i;
			}
			if (A[i] == 1)
			{
				if (y != -1)
					A[++y] = 1;
				else
				{
					y = x;
					A[++y] = 1;
				}
				if (z != -1)
				{
					A[++z] = 2;
				}
			}
			if (A[i] == 0)
			{
				A[++x] = 0;
				if (y != -1)
				{
					A[++y] = 1;
				}
				if (z != -1)
				{
					A[++z] = 2;
				}
			}
		}		
	}
};

int main()
{
	const int n = 6;
	int A[6] = {0};
	A[0] = 2;
	A[1] = 1;
	A[2] = 2;
	A[3] = 0;
	A[4] = 1;
	A[5] = 0;

	Solution solution;
	solution.sortColors(A, n);

	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << ' ' << endl;
	}
	
	system("pause");
	return 0;
}