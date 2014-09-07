/************************************************************************/
/* 
https://oj.leetcode.com/problems/combination-sum/
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
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
		} else{
			int num = 0;
			while (num <= target)
			{
				DFS(candidates, index + 1, target - num, path, result);
				path.push_back(candidates[index]);
				num += candidates[index];
			}
			while (!path.empty() && path.back() == candidates[index])
			{
				path.pop_back();
			}
		}
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		if (candidates.size() == 0)
			return result;

		int count = candidates.size();
		sort(candidates.begin(), candidates.end());

		vector<int> path;

		DFS(candidates, 0, target, path, result);

		return result;
	}
};

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);

	int target = 7;

	Solution solution;
	vector<vector<int>> result = solution.combinationSum(candidates, target);

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