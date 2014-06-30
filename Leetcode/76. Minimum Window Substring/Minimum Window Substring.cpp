/************************************************************************/
/* 
https://oj.leetcode.com/problems/minimum-window-substring/
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		
		int slen = S.length();
		int tlen = T.length();

		if (slen < tlen || tlen == 0)
			return "";
		
		int table[256][3] = { 0 };
		for (int i = 0; i < tlen; ++i)
		{
			table[T[i]][0]++;
			table[T[i]][1] = 0;
			table[T[i]][2] = -1;
		}
		
		int start, end;
		start = -1; 
		end = -1;

		int minLen = slen+1;
		int resultIndex = -1;
		int count = 0;

		for (int i = 0; i < slen; ++i)
		{
			if (table[S[i]][0] > 0)
			{
				if (start < 0)
					start = i;
				
				// find one
				table[S[i]][1]++;
				// if this one is useful
				if (table[S[i]][1] <= table[S[i]][0])
					count++;

				// if find all alpha
				if (count == tlen)
				{
					if (S[i] == S[start] || end == -1)
					{
						end = i;

						for (int j = start; j < i; ++j)
						{
							if (table[S[j]][0] > 0)
							{
								if (table[S[j]][1] > table[S[j]][0])
								{
									table[S[j]][1]--;
								}
								else
								{
									start = j;
									break;
								}
							}
						}
					}

					if (minLen > (end - start + 1))
					{
						minLen = (end - start + 1);
						resultIndex = start;
					}
				}
			}
		}

		if (resultIndex >= 0)
		{
			return S.substr(resultIndex, minLen);
		}
		
		return "";
	}
};

int main()
{
	//string S = "ADOBECODEBANC";
	//string T = "ABC";

	//string S = "a";
	//string T = "b";

	/*string S = "aa";
	string T = "aa";*/

	string S = "cabwefgewcwaefgcf";
	string T = "cae";

	Solution solution;
	cout << solution.minWindow(S, T);

	system("pause");
	return 0;
}