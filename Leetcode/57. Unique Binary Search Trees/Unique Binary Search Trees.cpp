/************************************************************************/
/*
https://oj.leetcode.com/problems/unique-binary-search-trees/
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	int *tot = new int[20];
//
//	Solution()
//	{
//		preCompute(tot);
//	}
//
//	void preCompute(int tot[20])
//	{
//		tot[0] = 1;
//		tot[1] = 1;
//		tot[2] = 2;
//		for (int i = 3; i <= 20; ++i)
//		{
//			tot[i] = 0;
//			for (int j = 0; j < i; ++j)
//			{
//				tot[i] += tot[j] * tot[i - 1 - j];
//			}
//		}
//	}
//	int numTrees(int n) {
//		if (n < 0)
//			return 0;
//		if (n == 0)
//			return 1;
//		if (n == 1)
//			return 1;
//		
//		return tot[n];
//	}
//};

class Solution {
public:
	int numTrees(int n) {
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;

		// 20 is the up boundary of int
		int *tot = new int[n+1];
		tot[0] = 1;
		tot[1] = 1;
		tot[2] = 2;
		for (int i = 3; i <= n; ++i)
		{
			tot[i] = 0;
			for (int j = 0; j < i; ++j)
			{
				tot[i] += tot[j] * tot[i - 1 - j];
			}
		}
		return tot[n];
	}
};

int main()
{
	Solution solution;
	for (int i = 0; i < 20; ++i)
		cout << i << ":" << solution.numTrees(i) << endl;

	system("pause");
	return 0;
}