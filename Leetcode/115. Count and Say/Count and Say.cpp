/************************************************************************/
/* 
https://oj.leetcode.com/problems/count-and-say/
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		string new_result;
		char buf[100];
		for (int i = 1; i < n; ++i)
		{
			char chd = result[0];
			int count = 1;
			new_result = "";
			for (int j = 1; j < result.length(); ++j)
			{
				if (result[j] == chd)
				{
					count++;
				}
				else
				{
					sprintf_s(buf, 100, "%d", count);
					//sprintf(buf, "%d", count);
					new_result += buf;
					new_result += chd;
					chd = result[j];
					count = 1;
				}
			}
			sprintf_s(buf, 100, "%d", count);
			new_result += buf;
			new_result += chd;
			result = new_result;
		}
		return result;
	}
};

int main()
{
	int n = 5;
	Solution solution;
	cout << solution.countAndSay(n);

	system("pause");
	return 0;
}