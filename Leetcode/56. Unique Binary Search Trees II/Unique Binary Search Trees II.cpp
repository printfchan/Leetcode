/************************************************************************/
/* 
https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

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

class Solution {
public:
	vector<TreeNode *> generate(int begin, int end)
	{
		vector<TreeNode *> ret;
		if (begin > end)
		{
			ret.push_back(NULL);
			return ret;
		}
		
		TreeNode *root = NULL;
		// i is the root node if tree.
		for (int i = begin; i <= end; ++i)
		{
			vector<TreeNode *> left = generate(begin, i - 1);
			vector<TreeNode *> right = generate(i + 1, end);

			for (int j = 0; j < left.size(); ++j)
			{
				for (int k = 0; k < right.size(); ++k)
				{
					root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					ret.push_back(root);
				}
			}
		}
		return ret;
	}

	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> result;
		
		result = generate(1, n);
		return result;
	}
};

int main()
{
	Solution solution;
	solution.generateTrees(5);

	system("pause");
	return 0;
}