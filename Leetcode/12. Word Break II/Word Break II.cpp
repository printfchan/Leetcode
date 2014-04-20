/************************************************************************/
/* 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		if (s.length() == 0)
			return result;

		int length = s.length();
		vector<vector<int>> vec_index(length);

		for (int i = 0; i < length; i++)
		{
			if (dict.find(s.substr(0, i + 1)) != dict.end())
			{
				vec_index[i].push_back(0);
			}
			for (int j = 1; j <= i; ++j)
			{
				if (vec_index[j - 1].size() > 0)
				{
					if (dict.find(s.substr(j, i - j + 1)) != dict.end())
					{
						vec_index[i].push_back(j);
					}
				}
			}
		}
		
		// no valid result
		if (vec_index[length - 1].size() == 0)
			return result;
		// backtracking
		int kind = 0;
		string post = "";
		BackTeacking(s, vec_index, result, length-1, post);
		return result;
	}
	void BackTeacking(string & s, vector<vector<int>>& vec_index, vector<string>& result, int index, string post_str)
	{
		if (index < 0)
		{
			result.push_back(post_str);
			return;
		}
		int size = vec_index[index].size();
		vector<string> str_vec(size);
		string tmp;
		while (size-- > 0)
		{
			tmp = s.substr(vec_index[index][size], index - vec_index[index][size] + 1);
			if (post_str != "")
				tmp += " ";
			tmp += post_str;
			BackTeacking(s, vec_index, result, vec_index[index][size] - 1, tmp);
		}
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

	vector<string> result = solution.wordBreak("catsanddog", dict);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
	return 0;
}