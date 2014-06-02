/************************************************************************/
/* 
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

  1
 / \
2   3
Return 6.
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

class Solution {
public:
	int maxPathSum(TreeNode *root) {

	}
};

int main()
{
	Solution solution;


	system("pause");
	return 0;
}