/************************************************************************/
/* 
https://oj.leetcode.com/problems/subsets/
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		return getSubset(S);
	}
	vector<vector<int>> getSubset(vector<int> &S)
	{
		vector<vector<int>> result;
		if (S.size() == 0)
			return result;

		vector<int> item;
		if (S.size() == 1)
		{
			result.push_back(item);

			item.push_back(S[0]);
			result.push_back(item);
			return result;
		}

		int num = S.size();
		vector<int> left;
		vector<int> right;
		for (int i = 0; i < num; ++i)
		{
			if (i < (num >> 1))
			{
				left.push_back(S[i]);
			}
			else{
				right.push_back(S[i]);
			}
		}

		vector<vector<int>> left_result = subsets(left);
		vector<vector<int>> right_result = subsets(right);

		return merge(left_result, right_result);
	}

	vector<vector<int>> merge(vector<vector<int>> left, vector<vector<int>> right)
	{
		if (left.size() == 0)
		{
			return right;
		}
		if (right.size() == 0)
		{
			return left;
		}
		
		//vector<vector<int>> result = left;
		//result.insert(result.end(), right.begin(), right.end());
		vector<vector<int>> result;
		vector<int> item;
		for (int i = 0; i < left.size(); ++i)
		{
			for (int j = 0; j < right.size(); ++j)
			{
				item = left[i];
				item.insert(item.end(), right[j].begin(), right[j].end());
				result.push_back(item);
			}
		}
		return result;
	}
};

int main()
{
	vector<int> S;
	S.push_back(4);
	S.push_back(2);
	S.push_back(1);

	Solution solution;
	vector<vector<int> > result = solution.subsets(S);
	
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