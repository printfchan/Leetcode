/************************************************************************/
/* 
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

  1
 / \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25
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
	void DFS(TreeNode *root, int fact, int* sum)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			(*sum) += fact * 10 + root->val;
			return;
		}
		else{
			DFS(root->left, fact * 10 + root->val, sum);
			DFS(root->right, fact * 10 + root->val, sum);
		}
	}
	int sumNumbers(TreeNode *root) {
		if (root == NULL)
		{
			return 0;
		}
		int sum = 0;
		DFS(root, 0, &sum);
		return sum;
	}
};

int main()
{
	TreeNode* root;
	root = new TreeNode(4);
	root->left = new TreeNode(9);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(5);

	Solution solution;
	cout << solution.sumNumbers(root);

	system("pause");
	return 0;
}