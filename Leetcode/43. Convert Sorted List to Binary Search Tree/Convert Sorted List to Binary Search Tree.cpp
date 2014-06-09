/************************************************************************/
/* 
https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
BST: Binary Search Tree
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
	TreeNode *BinSearch(vector<int> &num, int start, int end)
	{
		if (start > end)
			return NULL;
		if (start == end)
		{
			TreeNode* leave = new TreeNode(num[start]);
			return leave;
		}
		
		int mid = (end + start) >> 1;
		TreeNode* left = BinSearch(num, start, mid - 1);
		TreeNode* right = BinSearch(num, mid+1, end);
		TreeNode* node = new TreeNode(num[mid]);
		node->left = left;
		node->right = right;
		return node;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		int size = num.size();

		return BinSearch(num, 0, size - 1);
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);

	Solution solution;
	solution.sortedArrayToBST(num);

	system("pause");
	return 0;
}