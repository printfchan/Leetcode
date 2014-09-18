/************************************************************************/
/* 
https://oj.leetcode.com/problems/longest-palindromic-substring/
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int min_n(int a, int b)
	{
		return (a < b ? a : b);
	}

	string longestPalindrome(string s) {
		if (s.length() < 2)
			return s;

		// str���㿪ʼ��'?'����һ��������
		string str("?");
		for (int i = 0; i < s.length(); ++i)
		{
			str += '#';
			str += s[i];
		}
		str += '#';

		int max_index = 1;

		int right_max = 0;
		int id = 0;
		int len = str.length();
		// p��¼�˵�ǰ�����µĻ��ĳ���(һ��)
		vector<int> p(len);
		p[0] = 0;

		for (int i = 1; i < len; ++i)
		{
			// �ұ߽��Ѿ�����i�����Ը�����ǰi��һ���½磺�����ٵ���MIN����id�ԳƵ�(id << 1) - i�ĳ��ȣ��ҽ�-i��
			if (right_max > i)
				p[i] = min_n(p[(id << 1) - i], right_max - i);
			else
				// ����û���½磬���´�1��ʼ��
				p[i] = 1;

			// ���ϣ�����+1
			while (str[i - p[i]] == str[i + p[i]])
			{
				p[i]++;
			}
			//�����¼
			if (p[i] + i > right_max)
			{
				right_max = p[i] + i;
				id = i;
			}
			if (p[max_index] < p[i])
			{
				max_index = i;
			}
		}

		int t = max_index - p[max_index] + 1;
		if (str[t] != '#')
		{
			return s.substr((t - 1) >> 1, p[max_index]);
		}
		else{
			return s.substr((t - 1) >> 1, p[max_index]-1);
		}
	}
};

int main()
{
	//string s = "sdfskdasdfghhgfdsasodfj";
	string s = "sdsdfcbacbaccabcabcfstu";
	Solution solution;

	cout << solution.longestPalindrome(s);

	system("pause");
	return 0;
}