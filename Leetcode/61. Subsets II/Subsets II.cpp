/************************************************************************/
/* 
https://oj.leetcode.com/problems/subsets-ii/
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		vector<vector<int>> result;
		vector<int> emptySubSet;
		if (S.empty())
		{
			vector<int> item;
			result.push_back(item);
			return result;
		}
		
		map<int, int> allmap;
		for (int i = 0; i < S.size(); ++i)
		{
			if (allmap.find(S[i]) != allmap.end())
			{
				allmap[S[i]]++;
			}
			else
			{
				allmap[S[i]] = 1;
			}
		}

		map<int, int>::iterator it = allmap.begin();
		
		vector<vector<int>> subResult = getSingleSubset(it->first, it->second);
		result.insert(result.end(), subResult.begin(), subResult.end());
		
		for (++it; it != allmap.end(); it++)
		{
			vector<vector<int>> subResult = getSingleSubset(it->first, it->second);
			result = mergeSubSet(subResult, result);
		}
		
		result.push_back(emptySubSet);
		return result;
	}

	vector<vector<int>> getSingleSubset(int key, int count)
	{
		vector<vector<int>> res;
		vector<int> item;
		if (count < 1)
			return res;

		for (int i = 0; i < count; ++i)
		{
			item.push_back(key);
			res.push_back(item);
		}
		return res;
	}

	vector<vector<int>> mergeSubSet(vector<vector<int>> &part, vector<vector<int>> &result)
	{
		vector<vector<int>> mergeSet;
		
		vector<vector<int>>::iterator itp;
		vector<vector<int>>::iterator itr;
		for (itp = part.begin(); itp != part.end(); itp++)
		{
			for (itr = result.begin(); itr != result.end(); itr++)
			{
				vector<int> tot;
				tot.insert(tot.end(), itr->begin(), itr->end());
				tot.insert(tot.end(), itp->begin(), itp->end());
				mergeSet.push_back(tot);
			}
		}
		mergeSet.insert(mergeSet.end(), part.begin(), part.end());
		mergeSet.insert(mergeSet.end(), result.begin(), result.end());
		return mergeSet;
	}
};

int main()
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);

	Solution solution;
	vector<vector<int>> result = solution.subsetsWithDup(S);


	system("pause");
	return 0;
}