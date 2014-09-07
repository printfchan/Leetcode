/************************************************************************/
/* 
https://oj.leetcode.com/problems/permutation-sequence/
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string result;
		if (n < 1 || k < 0 || n > 9)
		{
			result = "";
			return "";
		}

		if (n == 1)
		{
			result = "1";
			return result;
		}

		int a[10] = { 0 };
		a[0] = 1;
		for (int i = 1; i < 10; ++i)
		{
			a[i] = a[i - 1] * i;
		}

		k--;
		bool f[10];
		for (int i = 0; i <= n; ++i)
		{
			f[i] = false;
		}

		int m = n;
		int count = 0;
		while (m > 0)
		{
			int num = k / a[m - 1];
			int ret = k%a[m-1];
			count = 0;
			int i = 1;
			for (; i <= n; ++i)
			{
				if (!f[i])
				{
					count++;
				}
				if (count == num+1)
				{
					break;
				}
			}
			result += '0' + i;
			f[i] = true;
			k = ret;
			m--;
		}
		return result;
	}
};

int main()
{
	int n = 5;
	int k = 16;

	Solution solution;
	string result = solution.getPermutation(n, k);

	cout << result << endl;

	system("pause");
	return 0;
}

