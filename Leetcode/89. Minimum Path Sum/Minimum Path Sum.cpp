/************************************************************************/
/* 
https://oj.leetcode.com/problems/minimum-path-sum/
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minval(int a, int b)
	{
		return a < b ? a : b;
	}

	int minPathSum(vector<vector<int> > &grid) {
		int h = grid.size();
		if (h == 0)
			return 0;
		
		int w = grid[0].size();
		if (w == 0)
			return 0;

		vector<int> pre = grid[0];
		vector<int> cur = pre;
		vector<int> *p = &pre;
		vector<int> *q = &cur;

		pre[0] = grid[0][0];
		for (int i = 1; i < w; ++i)
		{
			pre[i] = pre[i - 1] + grid[0][i];
		}
		
		for (int i = 1; i < h; ++i)
		{
			p = (i & 1) ? &pre : &cur;
			q = (i & 1) ? &cur : &pre;
			
			(*q)[0] = (*p)[0] + grid[i][0];

			for (int j = 1; j < w; ++j)
			{
				(*q)[j] = minval((*p)[j], (*q)[j-1]) + grid[i][j];
			}
		}

		return (h & 1) ? pre[w - 1] : cur[w - 1];
	}
};

int main()
{
	vector<vector<int> > grid;
	vector<int> item;
	item.push_back(1);
	item.push_back(3);
	item.push_back(1);
	grid.push_back(item);
	item.push_back(1);
	item.push_back(5);
	item.push_back(1);
	grid.push_back(item);
	item.push_back(4);
	item.push_back(2);
	item.push_back(1);
	grid.push_back(item);

	Solution solution;
	cout << solution.minPathSum(grid);

	system("pause");
	return 0;
}