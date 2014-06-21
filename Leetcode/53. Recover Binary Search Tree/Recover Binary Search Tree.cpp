/************************************************************************/
/* 
https://oj.leetcode.com/problems/recover-binary-search-tree/
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
	void findMistake(TreeNode* root, TreeNode *&first, TreeNode *&second, TreeNode *&pre)
	{
		if (!root)
			return;
		findMistake(root->left, first, second, pre);
		// if the previous node of this root is larger than root, record the node
		if (pre != NULL && pre->val > root->val)
		{
			// if is the first time to find the unordered pair
			if (first == NULL)
				first = pre;
			// just update the second to point the root
			second = root;
		}
		pre = root;
		findMistake(root->right, first, second, pre);		
	}

	void recoverTree(TreeNode *root) {
		if (root == NULL)
			return;
		if (!root->left && !root->right)
			return;

		TreeNode* first = NULL;
		TreeNode* second = NULL;
		TreeNode* pre = NULL;

		findMistake(root, first, second, pre);
		if (first && second)
			swap(first->val, second->val);
	}
};

int main()
{
	TreeNode *root = NULL;
	root = new TreeNode(0);
	root->right = new TreeNode(1);

	Solution solution;
	solution.recoverTree(root);

	system("pause");
	return 0;
}