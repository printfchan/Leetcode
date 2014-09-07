/************************************************************************/
/* 
https://oj.leetcode.com/problems/spiral-matrix-ii/
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
	[ 1, 2, 3 ],
	[ 8, 9, 4 ],
	[ 7, 6, 5 ]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> ret;
		if (n < 1)
		{
			return ret;
		}
		
		for (int i = 0; i < n; ++i)
		{
			vector<int> item(n);
			for (int j = 0; j < n; ++j)
				item[j] = 0;
			ret.push_back(item);
		}

		int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1}, {-1, 0} };
		int k = 1;
		int d = 0;
		int x, y;
		x = 0;
		y = 0;
		while (true)
		{
			ret[x][y] = k;
			k++;

			if ((x + dir[d][0] >= n) || (x + dir[d][0] < 0) ||
				(y + dir[d][1] >= n) || (y + dir[d][1] < 0) ||
				(ret[x + dir[d][0]][y + dir[d][1]]))
			{
				d++;
			}
			d %= 4;

			x += dir[d][0];
			y += dir[d][1];

			if (x >= n || x < 0 ||
				y >= n || y < 0 ||
				ret[x][y])
			{
				break;
			}
		}
		return ret;
	}
};

int main()
{
	int n = 2;
	Solution solution;
	vector<vector<int> > result = solution.generateMatrix(n);

	system("pause");
	return 0;
}

