/************************************************************************/
/* 
https://oj.leetcode.com/problems/n-queens-ii/
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png

*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int tot_count;
public:
	void DFS(vector<int> &col, vector<int> &empty_arr, int t, int n)
	{
		int i = 0;
		int j = 0;
		if (t > n)
		{
			tot_count++;
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
					DFS(col, empty_arr, t + 1, n);
				}
				col[t] = 0;
				empty_arr[i] = 0;
			}
		}
	}
	int totalNQueens(int n) {
		if (n <= 0)
			return 0;

		tot_count = 0;

		vector<int> col(n + 1);
		vector<int> empty_arr(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			col[i] = 0;
			empty_arr[i] = 0;
		}
		DFS(col, empty_arr, 1, n);

		return tot_count;
	}
};

int main()
{
	int  n = 4;
	Solution solution;
	cout << solution.totalNQueens(n);

	system("pause");
	return 0;
}