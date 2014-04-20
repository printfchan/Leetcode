/************************************************************************/
/* 
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
/************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			result ^= A[i];
		}
		return result;
	}
};

int main()
{
	int n = 9;
	
	int *A = new int[n];
	A[0] = 3;
	A[1] = 5;
	A[2] = 8;
	A[3] = 3;
	A[4] = 7;
	A[5] = 5;
	A[6] = 9;
	A[7] = 7;
	A[8] = 8;
	
	Solution solution;
	cout << solution.singleNumber(A, n) << endl;

	system("pause");
	return 0;
}