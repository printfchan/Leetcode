/************************************************************************/
/*
https://oj.leetcode.com/problems/n-queens/
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
	[".Q..",  // Solution 1
	"...Q",
	"Q...",
	"..Q."],

	["..Q.",  // Solution 2
	"Q...",
	"...Q",
	".Q.."]
]

*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<vector<string>> result;

public:
	void DFS(vector<int> &col, vector<int> &empty_arr, int t, int n)
	{
		int i = 0;
		int j = 0;
		if ( t > n)
		{
			vector<string> item;
			item.clear();
			for (i = 1; i <= n; ++i)
			{
				string str_item;
				for (j = 1; j <= n; ++j)
				{
					if (col[i] == j)
						str_item += "Q";
					else
						str_item += ".";
				}
				item.push_back(str_item);
			}
			result.push_back(item);
		}
		
		bool ifValid = false;
		for (i = 1; i <= n; ++i)
		{
			// 第i列还没放过
			if (empty_arr[i] == 0)
			{
				col[t] = i;
				empty_arr[i] = 1;

				// check if valid
				// up left
				ifValid = true;
				for (j = t - 1; j > 0; --j)
				{
					if (col[j] == (i - (t - j)) || col[j] == (i + (t - j)))
					{
						ifValid = false;
						break;
					}
				}
				if (ifValid)
				{
					DFS(col, empty_arr, t+1, n);
				}
				col[t] = 0;
				empty_arr[i] = 0;
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		if (n <= 0)
			return result;
		
		vector<int> col(n + 1);
		vector<int> empty_arr(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			col[i] = 0;
			empty_arr[i] = 0;
		}
		DFS(col, empty_arr, 1, n);

		return result;
	}
};

int main()
{
	int  n = 4;
	Solution solution;
	vector<vector<string>> result = solution.solveNQueens(n);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << endl;
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}