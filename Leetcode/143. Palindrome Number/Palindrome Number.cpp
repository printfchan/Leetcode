/************************************************************************/
/* 
https://oj.leetcode.com/problems/palindrome-number/
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;

		int p = 1;
		while (true)
		{
			if (x / p >= 10)
				p *= 10;
			else
				break;
		}
		while (x > 0)
		{
			if (x/p != x%10)
			{
				return false;
			}
			x %= p;
			x /= 10;
			p /= 100;
		}
		return true;
	}
};

int main()
{
	int x = 131;

	Solution solution;
	cout << solution.isPalindrome(x);

	system("pause");
	return 0;
}