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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		if (IsNear(start, end) == 1)
			return 2;
		
		// 记录从start到当前字符串的距离
		unordered_map<string, int> mp;
		// 记录已经走过的字符串
		queue<string> trans_queue;

		trans_queue.push(start);
		dict.insert(end);
		mp[start] = 1;

		while (!trans_queue.empty())
		{
			string last = trans_queue.front();
			trans_queue.pop();

			string query = last;
			int dist = mp[last];
			for (int i = 0; i < last.length(); ++i)
			{
				query = last;
				for (int j = 0; j < 26; ++j)
				{
					query[i] = 'a' + j;
					if (query == end)
					{
						return dist + 1;
					}

					if (dict.find(query) != dict.end() && mp.find(query) == mp.end())
					{
						trans_queue.push(query);
						mp[query] = dist + 1;
					}
				}
			}
		}
		return 0;
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