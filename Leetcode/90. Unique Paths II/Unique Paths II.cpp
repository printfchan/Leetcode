/************************************************************************/
/* 
https://oj.leetcode.com/problems/unique-paths-ii/
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
	[0,0,0],
	[0,1,0],
	[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
		{
			return 0;
		}

		int n = obstacleGrid[0].size();
		if (n == 0)
		{
			return 0;
		}

		vector<int> pre(n);
		vector<int> cur(n);

		vector<int> *p = &pre;
		vector<int> *q = &cur;

		int k = 1;
		for (int i = 0; i < n; ++i)
		{
			if (obstacleGrid[0][i] == 1)
			{
				k = 0;
			}
			pre[i] = k;
		}

		for (int i = 1; i < m; ++i)
		{
			p = (i & 1) ? &pre : &cur;
			q = (i & 1) ? &cur : &pre;

			if (obstacleGrid[i][0] == 1)
			{
				(*q)[0] = 0;
			}
			else{
				(*q)[0] = (*p)[0];
			}

			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					(*q)[j] = 0;
				}
				else{
					(*q)[j] = (*p)[j] + (*q)[j - 1];
				}
			}
		}

		return (m & 1) ? pre[n - 1] : cur[n - 1];
	}
};

int main()
{
	vector<vector<int> > obstacleGrid;

	Solution solution;
	cout << solution.uniquePathsWithObstacles(obstacleGrid);

	system("pause");
	return 0;
}