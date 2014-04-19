/************************************************************************/
/* 
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
 \
  2
 /
3
return [3,2,1].

Recursive solution is trivial, could you do it iteratively
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
	vector<int> postorderTraversal(TreeNode *root) {
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
			
			if (p->left != NULL)
			{
				node_stack.push_back(p->left);
			}
			if (p->right != NULL)
			{
				node_stack.push_back(p->right);
			}
		}
		vector<int> ans;
		while (!result.empty())
		{
			ans.push_back(result.back());
			result.pop_back();
		}
		return ans;
	}
};

int main()
{
	TreeNode *root;
	root = new TreeNode(1);

	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution solution;
	vector<int> result = solution.postorderTraversal(root);
	while (!result.empty())
	{
		cout << result.back() << " ";
		result.pop_back();
	}
	system("pause");
	return 0;
}