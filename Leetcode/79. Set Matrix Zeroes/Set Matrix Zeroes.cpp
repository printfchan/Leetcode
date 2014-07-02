/************************************************************************/
/* 
https://oj.leetcode.com/problems/set-matrix-zeroes/
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
/************************************************************************/
 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.size() == 0)
			return;
		
		int h = matrix.size();
		int w = matrix[0].size();

		bool firstline = false;
		bool firstcolumn = false;
		if (!matrix[0][0])
			firstcolumn = firstline = true;
		else
		{
			for (int i = 0; i < h; ++i)
			{
				if (!matrix[i][0])
					firstcolumn = true;
			}

			for (int j = 0; j < w; ++j)
			{
				if (!matrix[0][j])
					firstline = true;
			}
		}
		
		for (int i = 1; i < h; ++i)
		{
			for (int j = 1; j < w; ++j)
			{
				if (!matrix[i][j])
					matrix[i][0] = matrix[0][j] = 0;
			}
		}
		

		for (int i = 1; i < h; ++i)
		{
			if (!matrix[i][0])
			{
				for (int j = 0; j < w; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		
		for (int j = 1; j < w; ++j)
		{
			if (!matrix[0][j])
			{
				for (int i = 0; i < h; ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}

		if (firstline)
		{
			for (int j = 0; j < w; ++j)
			{
				matrix[0][j] = 0;
			}
		}
		if (firstcolumn)
		{
			for (int i = 0; i < h; ++i)
			{
				matrix[i][0] = 0;
			}
		}
		
	}
};

int main()
{
	vector<vector<int>> matrix;

	Solution solution;
	solution.setZeroes(matrix);

	system("pause");
	return 0;
}