/************************************************************************/
/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL)
			return result;

		TreeNode *p = root;
		vector<TreeNode*> node_stack;
		node_stack.push_back(p);

		while (!node_stack.empty())
		{
			p = node_stack.back();
			node_stack.pop_back();

			result.push_back(p->val);

			if (p->right != NULL)
			{
				node_stack.push_back(p->right);
			}
			if (p->left != NULL)
			{
				node_stack.push_back(p->left);
			}
			
		}
		return result;
	}
};

int main()
{
	TreeNode *root;
	root = new TreeNode(1);

	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution solution;
	vector<int> result = solution.preorderTraversal(root);
	while (!result.empty())
	{
		cout << result.back() << " ";
		result.pop_back();
	}
	system("pause");
	return 0;
}