/************************************************************************/
/* 
https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word 
in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		int word_count = L.size();
		int word_len = L[0].length();
		int str_len = word_count * word_len;
		int tot_len = S.length();

		vector<int> result;

		map<string, int> mp_word;
		map<string, int> mp_count;
		for (int i = 0; i < word_count; ++i)
			mp_word[L[i]]++;

		for (int i = 0; i <= tot_len - str_len; ++i)
		{
			int index = 0;
			mp_count.clear();
			bool flag = true;
			for (int j = 0; j < word_count; ++j)
			{
				string sub = S.substr(i + index, word_len);
				if (mp_word.find(sub) == mp_word.end())
				{
					flag = false;
					break;
				}
				mp_count[sub]++;
				if (mp_count[sub] > mp_word[sub])
				{
					flag = false;
					break;
				}
				index += word_len;
			}
			if (flag)
			{
				result.push_back(i);
			}
		}

		return result;
	}
};

int main()
{
	string S = "barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");

	//string S = "a";
	//vector<string> L;
	//L.push_back("a");
	////L.push_back("a");

	Solution solution;
	
	vector<int> result = solution.findSubstring(S, L);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ' ';
	}
	
	system("pause");
	return 0;
}