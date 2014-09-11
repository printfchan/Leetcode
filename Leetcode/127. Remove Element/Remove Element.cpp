/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-element/
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void swap(int &a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int removeElement(int A[], int n, int elem) {
		if (n < 1)
			return 0;

		int last = n - 1;
		int cur = n - 1;
		while (cur >= 0)
		{
			if (A[cur] == elem)
			{
				swap(A[cur], A[last]);
				cur--;
				last--;
			}
			else
				cur--;
		}
		return last + 1;
	}
};

int main()
{
	int A[] = {2, 8, 9, 10, 7, 10, 32, 15, 10};
	int elem = 10;

	Solution solution;
	cout << solution.removeElement(A, sizeof(A) / sizeof(A[0]), elem);

	system("pause");
	return 0;
}