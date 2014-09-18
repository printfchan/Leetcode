/************************************************************************/
/* 
https://oj.leetcode.com/problems/longest-palindromic-substring/
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int min_n(int a, int b)
	{
		return (a < b ? a : b);
	}

	string longestPalindrome(string s) {
		if (s.length() < 2)
			return s;

		// str不算开始的'?'长度一定是奇数
		string str("?");
		for (int i = 0; i < s.length(); ++i)
		{
			str += '#';
			str += s[i];
		}
		str += '#';

		int max_index = 1;

		int right_max = 0;
		int id = 0;
		int len = str.length();
		// p记录了当前坐标下的回文长度(一半)
		vector<int> p(len);
		p[0] = 0;

		for (int i = 1; i < len; ++i)
		{
			// 右边界已经大于i，可以给出当前i的一个下界：即至少等于MIN（与id对称的(id << 1) - i的长度，右界-i）
			if (right_max > i)
				p[i] = min_n(p[(id << 1) - i], right_max - i);
			else
				// 否则，没有下界，重新从1开始算
				p[i] = 1;

			// 符合，长度+1
			while (str[i - p[i]] == str[i + p[i]])
			{
				p[i]++;
			}
			//最长，记录
			if (p[i] + i > right_max)
			{
				right_max = p[i] + i;
				id = i;
			}
			if (p[max_index] < p[i])
			{
				max_index = i;
			}
		}

		int t = max_index - p[max_index] + 1;
		if (str[t] != '#')
		{
			return s.substr((t - 1) >> 1, p[max_index]);
		}
		else{
			return s.substr((t - 1) >> 1, p[max_index]-1);
		}
	}
};

int main()
{
	//string s = "sdfskdasdfghhgfdsasodfj";
	string s = "sdsdfcbacbaccabcabcfstu";
	Solution solution;

	cout << solution.longestPalindrome(s);

	system("pause");
	return 0;
}