/************************************************************************/
/* 
https://oj.leetcode.com/problems/regular-expression-matching/
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0')
			return *s == '\0';

		if (*(p+1) != '*')
		{
			// 标准匹配，s必须还没匹配完
			if (*p == *s || (*p == '.' && *s != '\0'))
			{
				return isMatch(s + 1, p + 1);
			}
			return false;
		}
		else{
			// 匹配1个或多个
			while (*s == *p || (*p == '.' && *s!= '\0'))
			{
				if (isMatch(s, p+2))
				{
					return true;
				}
				s++;
			}

			// 匹配0个
			return isMatch(s, p+2);
		}
	}
};

int main()
{
	/*char *s = "aab";
	char *p = "c*a*b";*/

	char *s = "a";
	char *p = "ab*";

	Solution solution;
	cout << solution.isMatch(s, p);

	system("pause");
	return 0;
}