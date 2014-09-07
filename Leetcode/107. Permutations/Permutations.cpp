/************************************************************************/
/* 
https://oj.leetcode.com/problems/permutations/
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> result;
		int count = num.size();
		if (count == 0)
			return result;

		for (int i = 0; i < count; ++i)
		{
			InsertItem(result, num[i]);
		}

		return result;
	}
	void InsertItem(vector<vector<int>>& result, const int item)
	{
		if (result.size() == 0)
		{
			vector<int> vec(1);
			vec[0] = item;
			result.push_back(vec);
		}
		else{
			int s = result.size();
			for (int i = 0; i < s; ++i)
			{
				vector<int> vecNew = result[i];
				vecNew.push_back(item);
				result[i].push_back(item);
				for (int j = result[i].size() - 1; j > 0; --j)
				{
					int tmp = vecNew[j];
					vecNew[j] = vecNew[j - 1];
					vecNew[j - 1] = tmp;
					result.push_back(vecNew);
				}
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	Solution solution;
	vector<vector<int>> result = solution.permute(num);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ',';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}