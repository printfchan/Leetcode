/************************************************************************/
/* 
https://oj.leetcode.com/problems/add-binary/
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int lena = a.length();
		int lenb = b.length();
		if (lena == 0)
			return b;
		if (lena == 0)
			return a;

		string result;
		int indexa = lena - 1;
		int indexb = lenb - 1;
		int flag = 0;
		while (indexa >= 0 && indexb >= 0)
		{
			result = (((a[indexa]-'0') + (b[indexb] - '0') + flag) % 2? "1":"0") + result;
			flag = ((a[indexa] - '0') + (b[indexb] - '0') + flag) / 2 ? 1 : 0;
			indexa--;
			indexb--;
		}

		while (indexa >= 0)
		{
			result = (((a[indexa] - '0') + flag) % 2 ? "1" : "0") + result;
			flag = (((a[indexa] - '0') + flag) / 2) ? 1 : 0;
			indexa--;
		}

		while (indexb >= 0)
		{
			result = (((b[indexb] - '0') + flag) % 2 ? "1" : "0") + result;
			flag = (((b[indexb] - '0') + flag) / 2) ? 1 : 0;
			indexb--;
		}

		if (flag)
			result = "1" + result;
		
		return result;
	}
};

int main()
{
	string a = "11";
	string b = "1";

	Solution solution;
	cout << solution.addBinary(a, b);

	system("pause");
	return 0;
}