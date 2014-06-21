/************************************************************************/
/* 
https://oj.leetcode.com/problems/restore-ip-addresses/
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void getAllValidIP(vector<string> &result, const string &s, const int &length, int index, string item, int step)
	{
		if ((step >= 4) || ((length - index) > 3 * (4 - step)) || ((length - index) < (4 - step)))
			return;
		
		if (step)
			item += ".";
		
		string subip = item;
		string num;
		for (int i = 0; i < 3; ++i)
		{
			subip = item;
			// 0~999
			if ((i+index) < length)
			{
				num = s.substr(index, i + 1);
				if (i == 2)
				{
					if (num > "255" || num < "100")
					{
						break;
					}
				}
				if (i == 1)
				{
					if (num < "10")
					{
						continue;
					}
				}
				subip += num;
				if (step == 3 && (i + index) == (length-1))
				{
					result.push_back(subip);
					return;
				}
				getAllValidIP(result, s, length, i+index+1, subip, step+1);
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4 || s.length() > 12)
			return result;
		
		string item;
		getAllValidIP(result, s, s.length(), 0, item, 0);

		return result;
	}
};

int main()
{
	string s = "010010";
	Solution solution;
	vector<string> result = solution.restoreIpAddresses(s);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	
	system("pause");
	return 0;
}