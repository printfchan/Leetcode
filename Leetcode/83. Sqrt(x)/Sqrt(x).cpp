/************************************************************************/
/* 
https://oj.leetcode.com/problems/sqrtx/
Implement int sqrt(int x).

Compute and return the square root of x.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x <= 0)
			return 0;

		unsigned long long left = 1;
		unsigned long long right = x/2;
		unsigned long long mid = 1;
		unsigned long long tmp = mid;
		while (left < right)
		{
			mid = left + ((right - left) >> 1);

			tmp = mid * mid;
			if (tmp > INT_MAX)
			{
				right = mid - 1;
				continue;
			}
			if (tmp == x)
				return mid;
			if (tmp > x)
				right = mid - 1;
			if (tmp < x)
				left = mid + 1;
		}
		if (left*left > x)
			return left - 1;
		return left;
	}
};

int main()
{
	int x = 2147483647;

	Solution solution;
	cout << solution.sqrt(x);

	system("pause");
	return 0;
}