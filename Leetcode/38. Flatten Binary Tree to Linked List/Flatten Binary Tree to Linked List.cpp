/************************************************************************/
/* 
https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
	void flatten(TreeNode *root) {
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			return;
		
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if (left != NULL)
		{
			root->right = left;
			flatten(root->left);
			LeftRight(left)->right = right;
			root->left = NULL;
		}
		if (right != NULL)
		{
			flatten(right);
		}
	}
	//  find most right node of the left sub tree
	TreeNode* LeftRight(TreeNode* node)
	{
		TreeNode* ret = node;
		while (ret->right != NULL)
		{
			ret = ret->right;
		}
		return ret;
	}
};

int main()
{
	TreeNode *root = NULL;
	root = new TreeNode(1);
	/*root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(5);
	root->left->right->right = new TreeNode(6);
	root->right->left = new TreeNode(8);
	root->right->right = new TreeNode(9);
	root->right->right = new TreeNode(10);*/

	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(5);

	Solution solution;
	solution.flatten(root);


	system("pause");
	return 0;
}