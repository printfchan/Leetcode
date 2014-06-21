/************************************************************************/
/* 
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if (len1 + len2 != len3)
			return false;
		if (len1 == 0)
			return s2 == s3;
		if (len2 == 0)
			return s1 == s3;

		int w = len1 + 1;
		int h = len2 + 1;
		int *mp = new int[w * h];
		memset(mp, 0, sizeof(mp[0]) * w * h);

		for (int i = 0; i < len1; ++i)
		{
			if (s1[i] == s3[i])
				mp[i + 1] = 1;
			else
				break;
		}

		for (int i = 0; i < len2; ++i)
		{
			if (s2[i] == s3[i])
				mp[(i + 1)*w] = 1;
			else
				break;
		}

		for (int i = 1; i < h; ++i)
		{
			for (int j = 1; j < w; ++j)
			{
				if (mp[i*w + j - 1] == 1)
				{
					if (s3[i + j - 1] == s1[j - 1])
						mp[i*w + j] = 1;
				}
				if (mp[(i - 1)*w + j] == 1)
				{
					if (s3[i + j - 1] == s2[i - 1])
						mp[i*w + j] = 1;
				}
			}
		}
		return mp[w*h - 1];
	}
};

int main()
{
	//string s1 = "aabcc";
	//string s2 = "dbbca";
	////string s3 = "aadbbcbcac";
	//string s3 = "aadbbbaccc";

	string s1 = "aa";
	string s2 = "ab";
	//string s3 = "aadbbcbcac";
	string s3 = "aaba";

	Solution solution;
	cout << solution.isInterleave(s1, s2, s3);

	system("pause");
	return 0;
}