/************************************************************************/
/* 
https://oj.leetcode.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.length();
		if (len < 2)
		{
			return 0;
		}

		vector<int> sta;

		int max_len = 0;
		int cur_len = 0;
		int cur_start = -1;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '(')
			{
				sta.push_back(i);
			}
			if (s[i] == ')')
			{
				if (!sta.empty())
				{
					sta.pop_back();
					if (!sta.empty())
					{
						cur_len = i - sta.back();
					}
					else
						cur_len = i - cur_start;

					if (cur_len > max_len)
					{
						max_len = cur_len;
					}
				}
				else
				{
					cur_start = i;
				}
			}
		}
		return max_len;
	}
};

int main()
{
	//string s = ")()())()";
	//string s = ")()())()(()())))";
	string s = "()(()";
	Solution solution;
	cout << solution.longestValidParentheses(s);

	system("pause");
	return 0;
}