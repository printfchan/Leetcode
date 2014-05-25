/************************************************************************/
/* 
given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
	["aa","b"],
	["a","a","b"]
]
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void DFS(const string& str, vector<vector<string>>& result, vector<string>& item, int ** table, int index, const int length)
	{
		if (index >= length)
		{
			result.push_back(item);
			return;
		}
		
		for (int i = index; i < length; ++i)
		{
			if (table[index][i])
			{
				item.push_back(str.substr(index, i - index + 1));
				DFS(str, result, item, table, i+1, length);
				item.pop_back();
			}
		}
		
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> item;
		if (s.length() < 2)
		{
			item.push_back(s);
			result.push_back(item);
			return result;
		}

		int length = s.length();

		int** table = new int*[length];
		table[0] = new int[length * length];
		for (int i = 1; i < length; ++i)
		{
			table[i] = table[i-1] + length;
		}

		memset(table[0], 0, length * length * sizeof(int));

		for (int i = 0; i < length; ++i)
		{
			table[i][i] = 1;
		}

		for (int i = 0; i < length; ++i)
		{
			// i as the mid char, length is odd
			int j, k;
			j = i - 1;
			k = i + 1;
			while (j >= 0 && k < length)
			{
				if (s[j] == s[k])
				{
					table[j][k] = 1;
					j--;
					k++;
				}else
					break;
			}

			// i as the mid char, length is even
			j = i;
			k = i + 1;
			while (j >= 0 && k < length)
			{
				if (s[j] == s[k])
				{
					table[j][k] = 1;
					j--;
					k++;
				}
				else
					break;
			}
		}
		
		DFS(s, result, item, table, 0, length);

		return result;
	}
};

int main()
{
	Solution solution;
	
	string str = "add";

	vector<vector<string>> result = solution.partition(str);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			if (j)
			{
				cout << " , ";
			}
			cout << result[i][j];
		}
		cout << endl;
	}
	

	system("pause");
	return 0;
}