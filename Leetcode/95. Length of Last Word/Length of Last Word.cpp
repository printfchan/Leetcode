/************************************************************************/
/* 
https://oj.leetcode.com/problems/length-of-last-word/
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == NULL)
		{
			return 0;
		}
		
		int start = -1, end = -1;
		int hasspace = true;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (isalpha(s[i]))
			{
				if (hasspace)
				{
					start = i;
				}
				end = i;
				hasspace = false;
			}
			else
			{
				hasspace = true;
			}
		}

		if (start != -1)
		{
			return end - start + 1;
		}
		return 0;
	}
};

int main()
{
	char *s = "Hello World";
	Solution solution;
	int result = solution.lengthOfLastWord(s);

	cout << result;

	system("pause");
	return 0;
}