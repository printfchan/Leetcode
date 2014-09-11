/************************************************************************/
/* 
https://oj.leetcode.com/problems/divide-two-integers/
Divide two integers without using multiplication, division and mod operator.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag1 = 1;
		int flag2 = 1;

		long long da = dividend;
		if (dividend < 0)
		{
			flag1 = -1;
			da = 0 - (long long)dividend;
		}

		long long db = divisor;
		if (divisor < 0)
		{
			flag2 = -1;
			db = 0 - (long long)divisor;
		}

		if (da < db)
		{
			return 0;
		}
		if (da == db)
		{
			return (flag1 == flag2 ? 1 : -1);
		}

		long long num = db;
		int result = 0;
		int  count = 1;
		while (da - num >= 0)
		{
			da -= num;
			result += count;
			count <<= 1;
			num += num;
		}
		
		result += divide(da, db);
		if (flag1 ^ flag2)
		{
			return 0 - result;
		}
		return result;
	}
};

int main()
{
	int dividend = 1;
	int divisior = 1;

	Solution solution;
	cout << solution.divide(dividend, divisior);

	system("pause");
	return 0;
}