/************************************************************************/
/* 
https://oj.leetcode.com/problems/symmetric-tree/
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
  1
 / \
2   2
 \   \
  3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	/*bool isSymmetricRecursive(TreeNode* leftNode, TreeNode* rightNode)
	{
		if (leftNode == NULL && rightNode == NULL)
			return true;
		if (leftNode == NULL || rightNode == NULL)
			return false;
		
		return ((leftNode->val == rightNode->val) &&
			isSymmetricRecursive(leftNode->left, rightNode->right) &&
			isSymmetricRecursive(leftNode->right, rightNode->left));
	}*/

	bool isSymmetricIterative(TreeNode* root)
	{
		if (root->left == NULL && root->right == NULL)
			return true;
		if (root->left == NULL || root->right == NULL)
			return false;

		queue<TreeNode*> queRight;
		queue<TreeNode*> queLeft;
		queLeft.push(root->left);
		queRight.push(root->right);

		while (!queLeft.empty() || !queRight.empty())
		{
			TreeNode* curLeft = queLeft.front();
			queLeft.pop();
			TreeNode* curRight = queRight.front();
			queRight.pop();

			if (curLeft == NULL && curRight == NULL)
				continue;
			if (curLeft == NULL || curRight == NULL)
				return false;

			if (curLeft->val != curRight->val)
				return false;

			queLeft.push(curLeft->left);
			queLeft.push(curLeft->right);
			queRight.push(curRight->right);
			queRight.push(curRight->left);
		}

		return true;
	}

	bool isSymmetric(TreeNode *root) {
		if (!root)
			return true;

		//return isSymmetricRecursive(root->left, root->right);
		return isSymmetricIterative(root);
	}
};

int main()
{
	TreeNode* root = NULL;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(3);

	Solution solution;
	cout << solution.isSymmetric(root);

	system("pause");
	return 0;
}
