/************************************************************************/
/* 
https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int max(int a, int b)
	{
		return (a > b ? a : b);
	}

	int lengthOfLongestSubstring(string s) {
		if (s.length() < 2)
			return s.length();

		int flag[256];
		for (int i = 0; i < 256; ++i)
		{
			flag[i] = -1;
		}

		int max_len = 0;
		int len = 0;
		// 第一个不重复的位置
		int dup = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (flag[s[i]] >= dup)
				dup = flag[s[i]] + 1;
			
			len = i - dup + 1;
			if (len > max_len)
			{
				max_len = len;
			}
			flag[s[i]] = i;
		}
		return max_len;
	}
};

int main()
{
	//string s = "abccbdefg";
	//string s = "wlrbbmqbhcdarzowkk";
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";

	Solution solution;
	cout << solution.lengthOfLongestSubstring(s);

	system("pause");
	return 0;
}