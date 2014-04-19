/************************************************************************/
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
/************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	static void reverseWords(string &s) {
		int len = s.length();
		int index = len - 1;
		bool flag = false;
		string result = "";

		for (int i = len - 1; i >= 0; --i)
		{
			if (s[i] != ' ' && i != 0)
			{
				if (s[index] == ' ')
				{
					index = i;
				}
			}
			else{
				if (s[index] == ' ')
				{
					index = i;
				}
				if (s[index] != ' ')
				{
					if (flag)
						result += " ";
					flag = true;

					if (s[i] != ' ')
						result += s.substr(i, index - i + 1);
					else
						result += s.substr(i + 1, index - i);
					index = i;
				}
			}
		}
		s = result;
		cout << s;
	}
};

int main()
{
	string str = "1  1";

	Solution::reverseWords(str);

	system("pause");
	return 0;
}