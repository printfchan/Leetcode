/************************************************************************/
/* 
https://oj.leetcode.com/problems/4sum/
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//recursive
//class Solution {
//public:
//	void DFS(vector<vector<int>> &result, vector<int> &path, vector<int> &num, int index, int target)
//	{
//		if (target == 0 && path.size() == 4)
//		{
//			result.push_back(path);
//			return;
//		}else if (path.size() < 4 && index < num.size())
//		{
//			int i = index, j, k;
//			while (i < num.size())
//			{
//				if (num[i] != num[index])
//					break;
//				if (path.size() >= 4)
//				{
//					break;
//				}
//				path.push_back(num[i]);
//				target -= num[i];
//				i++;
//			}
//			j = i;
//			while (i < num.size())
//			{
//				if (num[i] != num[index])
//					break;
//				i++;
//			}
//			k = i;
//			while (j >= index)
//			{
//				DFS(result, path, num, k, target);
//				j--;
//				if (j >= index)
//				{
//					target += num[j];
//					path.pop_back();
//				}
//			}
//		}
//
//	}
//
//	vector<vector<int> > fourSum(vector<int> &num, int target) {
//		vector<vector<int>> result;
//		if (num.size() == 0)
//			return result;
//
//		sort(num.begin(), num.end());
//
//		vector<int> path;
//		DFS(result, path, num, 0, target);
//
//		return result;
//	}
//};

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> result;
		if (num.size() < 4)
			return result;

		sort(num.begin(), num.end());

		vector<int> path(4);
		int size = num.size();
		// target = num[i] + num[j] + num[begin] + num[end];
		for (int i = 0; i < size - 3; ++i)
		{
			if (i == 0 || num[i] != num[i-1])
			{
				// 因为j = i+1 -> size-2，所以实际上在i取到i的时候，j的循环已经包含了所有包含任意个相同num[i]的取法
				for (int j = i + 1; j < size - 2; ++j)
				{
					if (j == i+1 || num[j] != num[j-1])
					{
						int begin = j + 1;
						int end = size - 1;
						int sum = 0;
						while (begin < end)
						{
							// begin == j+1
							if (begin > j + 1 && num[begin] == num[begin - 1])
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

							sum = num[i] + num[j] + num[begin] + num[end];
							if (sum == target)
							{
								path[0] = num[i];
								path[1] = num[j];
								path[2] = num[begin];
								path[3] = num[end];

								result.push_back(path);
								begin++;
							}
							else if (sum < target)
								begin++;
							else
								end--;
						}
					}
				}
			}
		}

		return result;
	}
};

int main()
{
	vector<int> num;
	/*num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);*/

	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(1);


	int target = 0;

	Solution solution;
	vector<vector<int> > result = solution.fourSum(num, target);

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