/************************************************************************/
/* 
https://oj.leetcode.com/problems/multiply-strings/
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result = "";
		if (num1 == "0" || num2 == "0")
			return "0";

		if (num1 == "1")
			return num2;

		if (num2 == "1")
			return num1;

		int len1 = num1.length();
		int len2 = num2.length();

		int max_len = len1 + len2;
		vector<int> tmpResult(max_len);
		for (int i = 0; i < max_len; ++i)
		{
			tmpResult[i] = 0;
		}

		int c = 0;
		int h = max_len - 1;
		int max_h = max_len - 1;
		for (int i = len2 - 1; i >= 0; --i)
		{
			for (int j = len1 - 1; j >= 0; --j)
			{
				h = max_len - 1 - (len1 - 1 - j) - c;
				tmpResult[h] += (num2[i] - '0') * (num1[j] - '0');
				tmpResult[h - 1] += tmpResult[h] / 10;
				tmpResult[h] %= 10;
				if (tmpResult[h - 1] > 0)
					h--;
				if (max_h > h)
				{
					max_h = h;
				}
			}
			c++;
		}
		if (tmpResult[max_h] > 9)
		{
			tmpResult[max_h-1] = tmpResult[max_h] / 10;
			tmpResult[max_h] %= 10;
			max_h--;
		}
		for (int i = max_h; i < max_len; ++i)
		{
			result += tmpResult[i] + '0';
		}
		return result;
	}
};

int main()
{
	string num1 = "10";
	string num2 = "10";

	Solution solution;
	cout << solution.multiply(num1, num2);

	system("pause");
	return 0;
}