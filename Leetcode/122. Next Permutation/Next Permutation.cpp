/************************************************************************/
/* 
https://oj.leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int len = num.size();
		if (len < 2)
		{
			return;
		}
		
		int min_large = 0;
		int s;
		for (int i = len - 2; i >= 0; --i)
		{
			if (num[i] < num[i+1])
			{
				s = num[i];
				min_large = i + 1;
				for (int j = i + 1; j < len; ++j)
				{
					if (num[j] > num[i])
					{
						if (num[min_large] > num[j])
						{
							min_large = j;
						}
					}else
						break;
				}
				num[i] = num[min_large];
				num[min_large] = s;
				sort(num.begin() + i + 1, num.end());
				return;
			}
		}
		sort(num.begin() , num.end());
	}
};

int main()
{
	vector<int> num;
	num.push_back(3);
	num.push_back(1);
	num.push_back(4);
	num.push_back(2);

	Solution solution;
	solution.nextPermutation(num);

	for (int i = 0; i < num.size(); ++i)
	{
		cout << num[i] << ' ';
	}
	

	system("pause");
	return 0;
}
