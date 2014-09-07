/************************************************************************/
/* 
https://oj.leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
http://4.bp.blogspot.com/_UElib2WLeDE/TNJf8VtC2VI/AAAAAAAACXU/UyUa-9LKp4E/s400/robot_maze.png

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
		{
			return 0;
		}

		vector<int> pre(n);
		vector<int> cur(n);

		vector<int> *p = &pre;
		vector<int> *q = &cur;

		for (int i = 0; i < n; ++i)
		{
			pre[i] = 1;
		}

		for (int i = 1; i < m; ++i)
		{
			p = (i & 1) ? &pre : &cur;
			q = (i & 1) ? &cur : &pre;

			(*q)[0] = 1;

			for (int j = 1; j < n; ++j)
			{
				(*q)[j] = (*p)[j] + (*q)[j - 1];
			}
		}

		return (m & 1) ? pre[n - 1] : cur[n - 1];
	}
};

int main()
{
	int m = 5;
	int n = 3;

	Solution solution;
	cout << solution.uniquePaths(m, n);

	system("pause");
	return 0;
}