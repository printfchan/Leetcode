/************************************************************************/
/* 
https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string mp[10];
public:
	void GetResult(vector<string> &result, string &digits, int index, string path)
	{
		if (index < digits.size())
		{
			for (int i = 0; i < mp[digits[index]-'0'].length(); ++i)
			{
				GetResult(result, digits, index + 1, path + mp[digits[index] - '0'][i]);
			}
		}
		else{
			result.push_back(path);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.length() == 0)
		{
			result.push_back("");
			return result;
		}

		mp[0] = "";
		mp[1] = "";
		mp[2] = "abc";
		mp[3] = "def";
		mp[4] = "ghi";
		mp[5] = "jkl";
		mp[6] = "mno";
		mp[7] = "pqrs";
		mp[8] = "tuv";
		mp[9] = "wxyz";

		GetResult(result, digits, 0, "");

		return result;
	}
};

int main()
{
	string digits = "23";
	Solution solution;

	vector<string> result = solution.letterCombinations(digits);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	
	system("pause");
	return 0;
}
