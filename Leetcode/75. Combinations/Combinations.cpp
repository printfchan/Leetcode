/************************************************************************/
/* 
https://oj.leetcode.com/problems/combinations/
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
	[2,4],
	[3,4],
	[2,3],
	[1,2],
	[1,3],
	[1,4],
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void getResult(vector<vector<int>> &result, vector<int> &item, int n, int k, int step, int num)
	{
		if (step == k)
		{
			result.push_back(item);
			return;
		}
		
		for (int i = num; i <= (n - (k-step - 1)); ++i)
		{
			item[step] = i;
			getResult(result, item, n, k, step + 1, i+1);
		}
	}

	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> result;
		if (n < 1)
			return result;
		
		if (k < 1)
			return result;

		if (k > n)
			return result;
		
		vector<int> item(k);
		getResult(result, item, n, k, 0, 1);
		
		return result;
	}
};

int main()
{
	int n = 5;
	int k = 3;
	Solution solution;
	vector<vector<int> > result = solution.combine(n, k);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << '[';
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ' ';
		}
		cout << ']' << endl;
	}

	system("pause");
	return 0;
}