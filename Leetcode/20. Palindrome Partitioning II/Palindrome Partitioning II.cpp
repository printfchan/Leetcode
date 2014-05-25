/************************************************************************/
/* 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
/************************************************************************/
#include <iostream>
using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))
class Solution {
public:
	int minCut(string s) {
		if (s.length() < 2)
			return 0;

		int length = s.length();

		int** table = new int*[length];
		table[0] = new int[length * length];
		for (int i = 1; i < length; ++i)
		{
			table[i] = table[i - 1] + length;
		}

		memset(table[0], 0, length * length * sizeof(int));

		for (int i = 0; i < length; ++i)
		{
			table[i][i] = 1;
		}

		for (int i = 0; i < length; ++i)
		{
			// i as the mid char, length is odd
			int j, k;
			j = i - 1;
			k = i + 1;
			while (j >= 0 && k < length)
			{
				if (s[j] == s[k])
				{
					table[j][k] = 1;
					j--;
					k++;
				}
				else
					break;
			}

			// i as the mid char, length is even
			j = i;
			k = i + 1;
			while (j >= 0 && k < length)
			{
				if (s[j] == s[k])
				{
					table[j][k] = 1;
					j--;
					k++;
				}
				else
					break;
			}
		}

		int* mincut = new int[length];
		for (int i = 0; i < length; ++i)
		{
			mincut[i] = i;
			for (int j = 0; j <= i; ++j)
			{
				// 0....j,j~i.
				if (table[j][i] == 1)
				{
					if (j == 0)
						mincut[i] = 0;
					else
						mincut[i] = min(mincut[j-1]+1, mincut[i]);
				}
			}
		}
		return mincut[length-1];
	}
};

int main()
{
	Solution solution;

	string str = "abbab";

	cout << solution.minCut(str);

	system("pause");
	return 0;
}