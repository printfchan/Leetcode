/************************************************************************/
/* 
https://oj.leetcode.com/problems/distinct-subsequences/
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		int S_Len = S.length();
		int T_Len = T.length();

		if (S_Len == 0 || T_Len == 0)
			return 0;
		
		if (S_Len < T_Len)
			return 0;
		
		vector<int> pre(S_Len);
		vector<int> cur(S_Len);
		int flag = 0;
		for (int i = 0; i < S_Len; ++i)
		{
			pre[i] = 0;
			if (S[i] == T[0])
			{
				cur[i] = flag + 1;
				flag++;
			}
			else
				cur[i] = flag;
		}
		pre = cur;

		for (int i = 1; i < T_Len; i++)
		{
			for (int j = 0; j < i; ++j)
			{
				cur[j] = 0;
			}
			for (int j = i; j < S_Len; j++)
			{
				if (T[i] == S[j])
				{
					cur[j] = cur[j - 1] + pre[j - 1];
				}
				else{
					cur[j] = cur[j - 1];
				}
			}
			pre = cur;
		}
		return cur[S_Len-1];
	}
};

int main()
{
	string S = "rabbbbit";
	string T = "rabbit";
	Solution solution;
	cout << solution.numDistinct(S, T);

	system("pause");
	return 0;
}