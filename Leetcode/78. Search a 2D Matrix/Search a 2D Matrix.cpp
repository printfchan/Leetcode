/************************************************************************/
/* 
https://oj.leetcode.com/problems/search-a-2d-matrix/
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
	[1,   3,  5,  7],
	[10, 11, 16, 20],
	[23, 30, 34, 50]
]
Given target = 3, return true.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int h = matrix.size();
		int w = matrix[0].size();
		if (w == 0)
			return false;

		int left = 0;
		int right = h - 1;
		int mid = 0;
		while (left < right)
		{
			mid = left + ((right - left) >> 1);
			if (matrix[mid][0] > target)
			{
				right = mid - 1;
			}
			else if (matrix[mid][w-1] < target)
			{
				left = mid + 1;
			}
			else if (matrix[mid][0] <= target && matrix[mid][w-1] >= target)
			{
				return findInline(matrix[mid], target);
			}
		}
		
		return findInline(matrix[left], target);
	}

	bool findInline(vector<int> &line, int target)
	{
		int w = line.size();

		int inleft = 0;
		int inright = w - 1;
		int inmid = 0;
		while (inleft < inright)
		{
			inmid = inleft + ((inright - inleft) >> 1);
			if (line[inmid] > target)
			{
				inright = inmid - 1;
			}
			if (line[inmid] < target)
			{
				inleft = inmid + 1;
			}
			if (line[inmid] == target)
			{
				return true;
			}
		}

		if (line[inright] == target)
			return true;

		return false;
	}
};

int main()
{
	vector<vector<int>> matrix;
	/*vector<int> item(4);
	item[0] = 1;
	item[1] = 3;
	item[2] = 5;
	item[3] = 7;
	matrix.push_back(item);
	item[0] = 10;
	item[1] = 11;
	item[2] = 16;
	item[3] = 20;
	matrix.push_back(item);
	item[0] = 23;
	item[1] = 30;
	item[2] = 34;
	item[3] = 50;
	matrix.push_back(item);

	int target = 49;*/

	vector<int> item(1);
	item[0] = 1;
	matrix.push_back(item);
	item[0] = 3;
	matrix.push_back(item);

	int target = 0;

	Solution solution;
	cout << solution.searchMatrix(matrix, target);

	system("pause");
	return 0;
}