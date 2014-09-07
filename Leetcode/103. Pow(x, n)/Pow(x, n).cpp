/************************************************************************/
/* 
https://oj.leetcode.com/problems/powx-n/
Implement pow(x, n).
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double pow(double x, int n) {
		if (x == 0)
			return 0;
		if (x == 1)
			return 1;
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (n == -1)
			return 1 / x;

		long long m = n;
		if (n < 0)
			m = -m;

		double result = x;
		unsigned long long i = 2;
		while (i < m)
		{
			result *= result;
			i = (i << 1);
		}
		if (i == m)
		{
			result *= result;
		}
		else{
			i = (i >> 1);
			result *= pow(x, int(m - i));
		}
		if (n < 0)
		{
			return 1 / result;
		}
		return result;
	}
};

int main()
{
	double x = -1.00000;
	int n = 2147483648;
	Solution solution;
	cout << solution.pow(x, n);

	system("pause");
	return 0;
}