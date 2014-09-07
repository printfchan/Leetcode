/************************************************************************/
/* 
https://oj.leetcode.com/problems/permutations-ii/
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> result;
		int count = num.size();
		if (count == 0)
			return result;

		sort(num.begin(), num.end());
		for (int i = 0; i < count; ++i)
		{
			InsertItem(result, num, i);
		}

		return result;
	}
	void InsertItem(vector<vector<int>>& result, vector<int> &num, const int index)
	{
		if (result.size() == 0)
		{
			vector<int> vec(1);
			vec[0] = num[index];
			result.push_back(vec);
		}
		else{
			int s = result.size();
			for (int i = 0; i < s; ++i)
			{
				vector<int> vecNew = result[i];
				vecNew.push_back(num[index]);
				result[i].push_back(num[index]);
				int j = vecNew.size() - 1;
				while (j > 0 && vecNew[j] != vecNew[j-1])
				{
					int tmp = vecNew[j];
					vecNew[j] = vecNew[j - 1];
					vecNew[j - 1] = tmp;
					result.push_back(vecNew);
					j--;
				}
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	num.push_back(2);

	Solution solution;
	vector<vector<int>> result = solution.permuteUnique(num);

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