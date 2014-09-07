/************************************************************************/
/*
https://oj.leetcode.com/problems/wildcard-matching/
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (s == NULL || p == NULL)
			return false;

		const char *str = s;
		const char *pat = p;

		const char *starStr = NULL;
		const char *starPat = NULL;

		while (*str != '\0')
		{
			// equal
			if (*str == *pat || *pat == '?')
			{
				str++;
				pat++;
				continue;
			}

			// '*' equals to any length of str
			if (*pat == '*')
			{
				starStr = str;
				starPat = pat;
				pat++;
				// str++;  // default, * match 0 length, so str not changed
				continue;
			}

			// not equal, check if exist *
			if (starPat != NULL)
			{
				pat = starPat + 1;
				str = starStr + 1; // * match one more char
				starStr++;	// if not match next time, * will match one more again
				continue;
			}
			return false;
		}

		// s finish match, check if p ended.
		while (*pat == '*')
		{
			pat++;
		}
		return *pat == '\0';
	}
};

//class Solution {
//public:
//	bool isMatch(const char *s, const char *p) {
//		//? match one
//		//* match 0,1,2,3..
//		// aaaabc *c true
//		const char* star = nullptr;
//		const char* rs = nullptr;
//
//		while (*s) {
//			if (*s == *p || *p == '?') { //match
//				s++; p++;
//				continue;
//			}
//			if (*p == '*') {
//				star = p; // record star
//				p++; //match from next p
//				rs = s; // record the position of s , star match 0
//				continue;
//			}
//			if (star != nullptr) { //if have star in front then backtrace
//				p = star + 1; //reset the position of p 
//				s = rs + 1;
//				rs++; //star match 1,2,3,4,5....
//				continue;
//			}
//			return false; //if not match return false
//		}
//		while (*p == '*') p++; //skip continue star
//		return *p == '\0'; // successful match
//	}
//};

int main()
{
	/*const char *s = "ababcba";
	const char *p = "*ab*a";*/
	const char *s = "b";
	const char *p = "*?*?";

	Solution solution;
	cout << solution.isMatch(s, p);

	system("pause");
	return 0;
}