/************************************************************************/
/* 
https://oj.leetcode.com/problems/generate-parentheses/
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// 任何时候，(个数都要大于等于)
	void generate(vector<string> &result, string path, int left, int right, int n)
	{
		if (left < right)
		{
			return;
		}
		else if (left == right)
		{
			if (left == n)
			{
				result.push_back(path);
				return;
			}
			else{
				generate(result, path + "(", left + 1, right, n);
			}
		}
		else 
		{
			if (left < n)
			{
				generate(result, path + "(", left + 1, right, n);
			}
			generate(result, path + ")", left, right + 1, n);
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n < 1)
			return result;
		
		string path = "";
		generate(result, path, 0, 0, n);

		return result;
	}
};

int main()
{
	int n = 3;

	Solution solution;
	vector<string> result = solution.generateParenthesis(n);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	
	system("pause");
	return 0;
}