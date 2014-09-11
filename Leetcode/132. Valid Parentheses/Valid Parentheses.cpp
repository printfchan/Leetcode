/************************************************************************/
/* 
https://oj.leetcode.com/problems/valid-parentheses/
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() < 2)
			return false;

		vector<char> sta;
		for (int i = 0; i < s.length(); ++i)
		{
			switch (s[i])
			{
			case '(':
				sta.push_back(')');
				break;
			case '[':
				sta.push_back(']');
				break;
			case '{':
				sta.push_back('}');
				break;
			default:
				if (sta.empty() || sta.back() != s[i])
				{
					return false;
				}
				sta.pop_back();
				break;
			}
		}
		return sta.empty();
	}
};

int main()
{
	string s = "()[]{}{[]}";
	Solution solution;

	cout << solution.isValid(s);

	system("pause");
	return 0;
}