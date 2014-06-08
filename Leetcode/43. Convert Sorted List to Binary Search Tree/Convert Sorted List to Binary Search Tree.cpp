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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {

	}
};

int main()
{
	ListNode *head = NULL;

	Solution solution;
	solution.sortedListToBST(head);

	system("pause");
	return 0;
}