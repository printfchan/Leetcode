/************************************************************************/
/* 
https://oj.leetcode.com/problems/scramble-string/
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
		   / \
		  a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
      / \
     t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

/************************************************************************/
/* 
�ַ�������Ϊ1�������ַ���������ȫ��ͬ�ſ���
�ַ�������Ϊ2����s1="ab", s2ֻ��"ab"����"ba"�ſ��ԡ�
�������ⳤ�ȵ��ַ��������ַ���s1��Ϊa1,b1�������֣�s2��Ϊa2,b2��������.
���㣨(a1~a2) && (b1~b2)������ ��(a1~b2) && (a1~b2)��
*/
/************************************************************************/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len = 0;
		if (len1 != len2)
			return false;

		len = len1;

		if (len == 1)
			return s1 == s2;
		if (len == 2)
		{
			return (s1 == s2) || (s1[0] == s2[1] && s1[1] == s2[0]);
		}

		// ���������кܴ����
		if (!isSimilar(s1, s2))
			return false;
		
		string sub11, sub12;
		string sub21, sub22;
		for (int i = 0; i < len-1; ++i)
		{
			sub11 = s1.substr(0, i + 1);
			sub12 = s1.substr(i + 1, string::npos);

			sub21 = s2.substr(0, i + 1);
			sub22 = s2.substr(i + 1, string::npos);
			if (isScramble(sub11, sub21) && isScramble(sub12, sub22))
				return true;
			
			sub21 = s2.substr(0, len-i-1); 
			sub22 = s2.substr(len-i-1, string::npos);
			if (isScramble(sub11, sub22) && isScramble(sub12, sub21))
				return true;
		}
		
		return false;
	}
	bool isSimilar(string &s1, string &s2)
	{
		// �������ʡ�ԣ���Ϊ����ǰ�Ѿ�ȷ�Ϲ�
		if (s1.length() != s2.length())
			return false;
		int len = s1.length();

		const int num = 26;
		static int alpha[num];
		memset(alpha, 0, num*sizeof(alpha[0]));

		for (int i = 0; i < len; ++i)
		{
			alpha[tolower(s1[i] - 'a')]++;
			alpha[tolower(s2[i] - 'a')]--;
		}
		
		for (int i = 0; i < num; ++i)
		{
			if (alpha[i] != 0)
				return false;
		}
		return true;
	}
};

int main()
{
	string s1 = "great";
	string s2 = "rgtae";

	Solution solution;
	cout << solution.isScramble(s1, s2);

	system("pause");
	return 0;
}