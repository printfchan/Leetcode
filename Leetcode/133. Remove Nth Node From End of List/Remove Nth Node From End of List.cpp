/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL || n < 1)
			return head;

		ListNode *pre = NULL;
		ListNode *post = head;
		for (int i = 0; i < n; ++i)
		{
			post = post->next;
		}
		while (post != NULL)
		{
			post = post->next;
			if (pre != NULL)
			{
				pre = pre->next;
			}
			else
				pre = head;
		}
		if (pre == NULL)
		{
			head = head->next;
			pre = head;
		}
		else{
			pre->next = pre->next->next;
		}
		return head;
	}
};

int main()
{
	ListNode *head = NULL;

	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	int n = 5;

	Solution solution;
	ListNode *result = solution.removeNthFromEnd(head, n);

	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}

	system("pause");
	return 0;
}