/************************************************************************/
/* 
https://oj.leetcode.com/problems/two-sum/
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		vector<int> cpy = numbers;
		sort(cpy.begin(), cpy.end());
		
		int p = 0;
		int q = cpy.size() - 1;

		while (p < q)
		{
			if (cpy[p] + cpy[q] < target)
			{
				p++;
			}else if (cpy[p] + cpy[q] == target)
			{
				bool findfirst = true;
				for (int i = 0; i < numbers.size(); ++i)
				{
					if (findfirst)
					{
						if (numbers[i] == cpy[p] || numbers[i] == cpy[q])
						{
							result.push_back(i + 1);
							findfirst = false;
							continue;
						}
					}else if (numbers[i] == target - numbers[result[0]-1])
					{
						result.push_back(i + 1);
						break;
					}
				}
				return result;
			}
			else{
				q--;
			}
		}
		return result;
	}
};

int main()
{
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(0);

	int target = 0;

	Solution solution;
	vector<int> result = solution.twoSum(numbers, target);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;
}