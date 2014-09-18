/************************************************************************/
/* 
https://oj.leetcode.com/problems/reverse-integer/
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (-10 < x && x < 10)
			return x;

		long long result = 0;
		int isNeg = 1;
		if (x < 0)
		{
			isNeg = -1;
			x *= -1;
		}

		while (x > 0)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}

		return isNeg * result;
	}
};

int main()
{
	int x = 12353246;

	Solution solution;
	cout << solution.reverse(x);

	system("pause");
	return 0;
}