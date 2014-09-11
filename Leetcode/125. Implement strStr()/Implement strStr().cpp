/************************************************************************/
/* 
https://oj.leetcode.com/problems/implement-strstr/
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
	void GetNext(char *needle, int len, vector<int> &next)
	{
		// k 下一次要比较的元素下标
		int k = -1;
		next[0] = k;
		int i = 0;
		while (i < len-1)
		{
			if (k == -1 || needle[i] == needle[k])
			{
				i++;
				k++;
				next[i] = k;
			}
			else{
				// 递归重置
				k = next[k];
			}
		}
	}
	char *strStr(char *haystack, char *needle) {
		if (needle == NULL || haystack == NULL)
		{
			return NULL;
		}

		if (*needle == '\0')
		{
			return haystack;
		}

		int len_s = strlen(haystack);
		int len_p = strlen(needle);

		if (len_s < len_p)
		{
			return NULL;
		}

		if (len_s == len_p)
		{
			if (strcmp(haystack, needle) == 0)
			{
				return haystack;
			}
			else
			{
				return NULL;
			}
		}

		vector<int> next(len_p);
		GetNext(needle, len_p, next);
		int i = 0;
		int k = 0;
		while (i < len_s && k < len_p)
		{
			if (haystack[i] == needle[k])
			{
				i++;
				k++;
				if (k == len_p)
				{
					return &haystack[i - len_p];
				}
			}
			else
			{
				k = next[k];
				if (k == -1)
				{
					k = 0;
					i++;
				}
			}
		}
		return NULL;
	}
};

int main()
{
	char *haystack = "BBC ABCDAB ABCDABCDABDE";
	char *needle = "ABCDABD";
	Solution solution;
	cout << solution.strStr(haystack, needle);

	system("pause");
	return 0;
}