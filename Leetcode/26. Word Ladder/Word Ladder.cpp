/************************************************************************/
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		vector<string> item;

		unordered_map<string, vector<string>> pre;
		unordered_map<string, vector<string>>::iterator mit;

		dict.insert(end);

		unordered_set<string>::iterator sit;
		for (sit = dict.begin(); sit != dict.end(); ++sit)
		{
			pre[*sit] = item;
		}

		unordered_set<string> used_dict;
		unordered_set<string>::iterator suit;
		bool find = false;
		int level = 0;
		for (sit = dict.begin(); sit != dict.end();)
		{
			if (IsNear(start, *sit) == 1)
			{
				pre[*sit].push_back(start);
				used_dict.insert(*sit);
				if (*sit == end)
				{
					find = true;
					level = 2;
				}
				sit = dict.erase(sit);
			}
			else{
				sit++;
			}
		}

		if (find)
		{
			return level;
		}

		level = 2;
		unordered_set<string> tmp_set;
		while (true)
		{
			level++;
			bool hasNear = false;
			for (sit = dict.begin(); sit != dict.end();)
			{
				hasNear = false;
				for (suit = used_dict.begin(); suit != used_dict.end(); ++suit)
				{
					if (IsNear(*suit, *sit) == 1)
					{
						pre[*sit].push_back(*suit);
						tmp_set.insert(*sit);
						if (*sit == end)
						{
							find = true;
						}
						hasNear = true;
					}
				}
				if (find)
				{
					return level;
				}
				if (hasNear)
					sit = dict.erase(sit);
				else
					++sit;
			}

			if (find)
			{
				return level;
			}
			used_dict.clear();
			for (sit = tmp_set.begin(); sit != tmp_set.end();)
			{
				used_dict.insert(*sit);
				dict.erase(*sit);
				sit = tmp_set.erase(sit);
			}

			if (used_dict.empty() || dict.empty())
			{
				return 0;
			}
		}

		return level;
	}
	
	int IsNear(const string& a, const string& b)
	{
		int len = a.length();
		int dist = 0;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] != b[i])
			{
				dist++;
				if (dist > 1)
				{
					return 2;
				}
			}
		}
		return dist;
	}
};

int main()
{
	string start, end;
	start = "hit";
	end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	Solution solution;
	cout << solution.ladderLength(start, end, dict);

	system("pause");
	return 0;
}