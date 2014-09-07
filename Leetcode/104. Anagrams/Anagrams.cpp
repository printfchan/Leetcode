/************************************************************************/
/* 
https://oj.leetcode.com/problems/anagrams/
Given an array of strings, return all groups of strings that are anagrams.(µßµ¹´ÊÐò)

Note: All inputs will be in lower-case.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		if (strs.size() == 0)
			return result;
		
		unordered_map<string, vector<string>> mp;
		mp.clear();
		for (int i = 0; i < strs.size(); i++)
		{
			string key_str(strs[i]);
			sort(key_str.begin(), key_str.end());
			mp[key_str].push_back(strs[i]);
		}
		
		unordered_map<string, vector<string>>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if ((it->second).size() > 1)
			{
				for (int i = 0; i < (it->second).size(); i++)
					result.push_back((it->second)[i]);
			}
		}
		
		return result;
	}
};

int main()
{
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("cba");

	Solution solution;
	vector<string> result = solution.anagrams(strs);

	system("pause");
	return 0;
}