/************************************************************************/
/* 
https://oj.leetcode.com/problems/3sum/
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> result;
		if (num.size() < 3)
			return result;

		sort(num.begin(), num.end());

		vector<int> path(3);
		int size = num.size();
		// target = num[i] + num[begin] + num[end];
		for (int i = 0; i < size - 2; ++i)
		{
			if (i == 0 || num[i] != num[i - 1])
			{
				int begin = i + 1;
				int end = size - 1;
				int sum = 0;
				while (begin < end)
				{
					// begin == j+1
					if (begin > i + 1 && num[begin] == num[begin - 1])
					{
						begin++;
						continue;
					}

					// end == size-1
					if (end < num.size() - 1 && num[end] == num[end + 1])
					{
						end--;
						continue;
					}

					sum = num[i] + num[begin] + num[end];
					if (sum == 0)
					{
						path[0] = num[i];
						path[1] = num[begin];
						path[2] = num[end];

						result.push_back(path);
						begin++;
					}
					else if (sum < 0)
						begin++;
					else
						end--;
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution solution;
	vector<vector<int> > result = solution.threeSum(num);

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