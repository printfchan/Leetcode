/************************************************************************/
/* 
https://oj.leetcode.com/problems/longest-common-prefix/
Write a function to find the longest common prefix string amongst an array of strings.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int count = strs.size();
		if (count == 0)
			return "";
		if (count == 1)
			return strs[0];

		string pre_str = "";
		
		int len = strs[0].length();
		
		for (int i = 0; i < len; ++i)
		{
			for (int j = 1; j < count; ++j)
			{
				if (i >= strs[j].length() || strs[0][i] != strs[j][i])
				{
					return pre_str;
				}
			}
			pre_str += strs[0][i];
		}
		return pre_str;
	}
};

int main()
{
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("abcde");
	strs.push_back("abcdefg");

	Solution solution;
	cout << solution.longestCommonPrefix(strs);

	system("pause");
	return 0;
}