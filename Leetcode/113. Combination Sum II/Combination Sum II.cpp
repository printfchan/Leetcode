/************************************************************************/
/* 
https://oj.leetcode.com/problems/combination-sum-ii/
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void DFS(const vector<int> &candidates, const int index, const int target, vector<int>& path, vector<vector<int>> &result)
	{
		if (target == 0)
		{
			result.push_back(path);
			return;
		}
		else if (target < 0 || index >= candidates.size())
		{
			return;
		}
		else{
			int sum = 0;
			int i = index;
			for (; i < candidates.size(); ++i)
			{
				if (candidates[i] != candidates[index])
					break;
				path.push_back(candidates[index]);
				sum += candidates[index];
			}
			while (sum >= 0)
			{
				DFS(candidates, i, target - sum, path, result);
				sum -= candidates[index];
				if (sum >= 0)
				{
					path.pop_back();
				}
			}
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> result;
		if (num.size() == 0)
			return result;

		int count = num.size();
		sort(num.begin(), num.end());

		vector<int> path;

		DFS(num, 0, target, path, result);

		return result;
	}
};

int main()
{
	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);

	int target = 8;

	Solution solution;
	vector<vector<int>> result = solution.combinationSum2(num, target);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}