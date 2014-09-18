/************************************************************************/
/* 
https://oj.leetcode.com/problems/3sum-closest/
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int result;
		if (num.size() < 3)
			return 0;

		sort(num.begin(), num.end());

		result = num[0] + num[1] + num[2];

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
					if (abs(sum-target) < abs(result-target))
					{
						result = sum;
					}
					if (sum < target)
						begin++;
					else if (sum == target)
						return target;
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
	vector<int> num;
	/*num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-4);*/

	/*num.push_back(0);
	num.push_back(1);
	num.push_back(2);*/

	num.push_back(0);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-3);

	int target = 1;

	Solution solution;
	cout << solution.threeSumClosest(num, target);

	system("pause");
	return 0;
}