/************************************************************************/
/* 
https://oj.leetcode.com/problems/edit-distance/
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int minLine(int a, int b, int c)
	{
		if (a < b)
			return (a < c ? a : c);
		else
			return (b < c ? b : c);
	}

	// word1 -> word2
	int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();

		if (len1 == 0)
			return len2;
		if (len2 == 0)
			return len1;
		
		vector<int> preline(len1 + 1);
		vector<int> curline(len1 + 1);

		for (int i = 0; i < len1 + 1; ++i)
			preline[i] = i;

		for (int i = 0; i < len2; ++i)
		{
			curline[0] = i + 1;
			for (int j = 0; j < len1; ++j)
			{
				if (word2[i] == word1[j])
					curline[j + 1] = preline[j];
				else
					curline[j + 1] = minLine(preline[j + 1], curline[j], preline[j]) + 1;
			}
			preline = curline;
		}

		return curline[len1];
	}
};

int main()
{
	string word1 = "sea";
	string word2 = "ate";
	
	Solution solution;
	cout << solution.minDistance(word1, word2) << endl;

	system("pause");
	return 0;
}