/************************************************************************/
/* 
https://oj.leetcode.com/problems/zigzag-conversion/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		string result;
		if (nRows == 1)
			return s;

		for (int i = 0; i < nRows; ++i)
		{
			for (int j = i; j < s.length();)
			{
				result += s[j];
				if (i == 0 || i == nRows - 1)
				{
					j += ((nRows - 1) << 1);
				}
				else
				{
					j += (nRows - 1 - i) * 2;
					if (j < s.length())
					{
						result += s[j];
						j += i * 2;
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	string s = "PAYPALISHIRING";
	int nRows = 3;

	Solution solution;
	cout << solution.convert(s, nRows);

	system("pause");
	return 0;
}