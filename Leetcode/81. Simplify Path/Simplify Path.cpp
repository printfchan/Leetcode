/************************************************************************/
/* 
https://oj.leetcode.com/problems/simplify-path/
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int len = path.length();
		if (len == 0 || path[0] != '/')
			return "";
		
		vector<string> spath;
		vector<string> abspath;

		// previous '/'
		int pre = 0;
		string cur;
		for (int i = 1; i < len; ++i)
		{
			if (path[i] == '/')
			{
				if (pre != i-1)
				{
					cur = path.substr(pre + 1, i - pre - 1);
					abspath.push_back(cur);
				}
				pre = i;
				continue;
			}
			if (i == len-1 && path[i] != '/')
			{
				cur = path.substr(pre + 1, string::npos);
				abspath.push_back(cur);
			}
		}
		
		for (int i = 0; i < abspath.size(); ++i)
		{
			if (abspath[i] == "..")
			{
				if (!spath.empty())
					spath.pop_back();
				
				continue;
			}
				
			if (abspath[i] == ".")
				continue;

			// other path
			spath.push_back(abspath[i]);
		}

		if (spath.size() == 0)
			return "/";
		
		string result = "";
		for (int i = 0; i < spath.size(); ++i)
		{
			result += "/";
			result += spath[i];
		}

		return result;
	}
};

int main()
{
	string path = "/..";
	Solution solution;
	cout << solution.simplifyPath(path);

	system("pause");
	return 0;
}