/************************************************************************/
/* 
https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;



int main()
{
	ListNode *head = NULL;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	Solution solution;
	solution.sortedListToBST(head);

	system("pause");
	return 0;
}