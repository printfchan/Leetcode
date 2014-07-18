/************************************************************************/
/* 
https://oj.leetcode.com/problems/climbing-stairs/
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;

		int m = n + 1;
		int *step = new int[m];
		memset(step, 0, sizeof(int) * m);

		step[0] = 0;
		step[1] = 1;
		step[2] = 2;

		for (int i = 3; i <= n; ++i)
		{
			step[i] = step[i - 1] + step[i - 2];
		}

		return step[n];		
	}
};

int main()
{
	int n = 5;

	Solution solution;
	cout << solution.climbStairs(n);

	system("pause");
	return 0;
}