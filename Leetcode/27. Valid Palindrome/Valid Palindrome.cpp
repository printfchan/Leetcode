/************************************************************************/
/* 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
	bool isValid(char ch)
	{
		if (ch>='a' && ch <= 'z')
			return true;
		if (ch >= 'A' && ch <= 'Z')
			return true;
		if (ch >= '0' && ch <= '9')
			return true;
		return false;
	}
	bool equalIgnoreCase(char ch1, char ch2)
	{
		if (isValid(ch1) && isValid(ch2))
		{
			if (ch1 == ch2 || (ch1 >= 'A' && ch2 >= 'A' && (abs(ch1 - ch2) == 'a' - 'A')))
			{
				return true;
			}
		}
		return false;
	}
	bool isPalindrome(string s) {
		int length = s.length();
		if (length < 2)
		{
			return true;
		}
		int l = 0;
		int r = length - 1;
		while (l<=r)
		{
			while (l < r && !isValid(s[l]))
				l++;
			while (l < r && !isValid(s[r]))
				r--;
			if (l>=r)
			{
				return true;
			}
			if (!equalIgnoreCase(s[l], s[r]))
				return false;
			l++;
			r--;
		}
		return true;
	}
};

int main()
{
	Solution solution;
	cout << solution.isPalindrome("1a2");
	//cout << solution.isPalindrome("A man, a plan, a canal: Panama");

	system("pause");
	return 0;
}