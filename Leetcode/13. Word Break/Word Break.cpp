/************************************************************************/
/* 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
/************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	/************************************************************************/
	/* recursive version                                                    */
	/************************************************************************/
	//bool wordBreak(string s, unordered_set<string> &dict) {
	//	if (s.length() == 0)
	//	{
	//		return true;
	//	}
	//	int length = s.length();
	//	bool result = false;

	//	for (int i = 0; i < length; i++)
	//	{
	//		if (dict.find(s.substr(0,i+1)) != dict.end())
	//		{
	//			result = wordBreak(s.substr(i + 1, string::npos), dict);
	//			if (result)
	//			{
	//				return true;
	//			}
	//		}
	//	}
	//	return false;
	//}

	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.length() == 0)
		{
			return true;
		}

		int length = s.length();
		bool result = false;

		vector<vector<int>> vec_index(length);

		for (int i = 0; i < length; i++)
		{
			if (dict.find(s.substr(0, i + 1)) != dict.end())
			{
				vec_index[i].push_back(0);
			}
			for (int j = 1; j <= i; ++j)
			{
				if (vec_index[j-1].size() > 0)
				{
					if (dict.find(s.substr(j, i - j + 1)) != dict.end())
					{
						vec_index[i].push_back(j);
					}
				}
			}
		}
		if (vec_index[length - 1].size() > 0)
			return true;
		return false;
	}
};

int main()
{
	Solution solution;
	
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("sand");
	dict.insert("and");
	dict.insert("dog");

	bool can = solution.wordBreak("catsanddog", dict);

	cout << (can ? "can" : "cann't") << endl;
	system("pause");
	return 0;
}