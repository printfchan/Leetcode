/************************************************************************/
/* 
https://oj.leetcode.com/problems/spiral-matrix/
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		result.clear();

		int h = matrix.size();
		if (h == 0)
			return result;

		int w = matrix[0].size();
		if (w == 0)
			return result;

		// right, down, left, up
		int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
		int x = 0;
		int y = 0;
		int xmin = 0;
		int xmax = w - 1;
		int ymin = 0;
		int ymax = h - 1;
		int d = 0;
		while (true)
		{
			result.push_back(matrix[y][x]);

			if ((x + dir[d][0] > xmax) || (x + dir[d][0] < xmin) ||
				(y + dir[d][1] > ymax) || (y + dir[d][1] < ymin))
			{
				d++;
				d %= 4;
				if (d == 0)
					xmin++;
				if (d == 1)
					ymin++;
				if (d == 2)
					xmax--;
				if (d == 3)
					ymax--;
				if (xmin > xmax || ymin > ymax)
				{
					break;
				}
			}

			x += dir[d][0];
			y += dir[d][1];
		}
		return result;
	}
};

int main()
{
	vector<vector<int> > matrix;
	/*vector<int> item(1);
	item[0] = 3;
	matrix.push_back(item);*/
	/*item[0] = 2;
	matrix.push_back(item);*/
	vector<int> item(3);
	item[0] = 1;
	item[1] = 2;
	item[2] = 3;
	matrix.push_back(item);
	item[0] = 4;
	item[1] = 5;
	item[2] = 6;
	matrix.push_back(item); 
	item[0] = 7;
	item[1] = 8;
	item[2] = 9;
	matrix.push_back(item);

	Solution solution;
	vector<int> result = solution.spiralOrder(matrix);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	system("pause");
	return 0;
}