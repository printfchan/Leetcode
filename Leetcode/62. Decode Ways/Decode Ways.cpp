/************************************************************************/
/* 
https://oj.leetcode.com/problems/decode-ways/
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int BinarySearch(const string& s, int begin, int end)
	{
		if (begin > end)
			return 1;

		if (begin == end)
		{
			if (s[begin] != '0')
				return 1;
			else
				return 0;
		}

		int mid = begin + ((end - begin) >> 1);
		int count = 0;
		int left = BinarySearch(s, begin, mid);
		int right = BinarySearch(s, mid+1, end);

		int subleft = 0;
		int subright = 0;
		if (s[mid] != '0' && s.substr(mid, 2) <= "26")
		{
			subleft = BinarySearch(s, begin, mid - 1);
			subright = BinarySearch(s, mid+2, end);
		}

		if (left * right)
		{
			count += (left *right);
		}

		if (subleft * subright)
		{
			count += (subleft * subright);
		}
		
		return count;
	}
	int numDecodings(string s) {
		int length = s.length();
		if (length == 0)
			return 0;
		
		int count = 0;
		count = BinarySearch(s, 0, length-1);
		return count;
	}
};

int main()
{
	string s = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
	//string s = "12";
	//string s = "0";
	//string s = "";

	Solution solution;
	cout << solution.numDecodings(s);

	system("pause");
	return 0;
}