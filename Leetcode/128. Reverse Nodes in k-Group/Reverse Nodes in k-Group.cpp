/************************************************************************/
/* 
https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
	void reverseList(ListNode *head, int k)
	{
		if (head == NULL || k < 1)
		{
			return;
		}

		ListNode *p = head;
		ListNode *q = head->next;
		ListNode *tmp = NULL;

		p->next = NULL;
		while (q != NULL && k-- > 1)
		{
			tmp = q->next;
			q->next = p;
			p = q;
			q = tmp;
		}
	}
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k < 1 || head == NULL)
			return head;

		ListNode *pre = NULL;
		ListNode *p = head;
		ListNode *post = head;

		ListNode *tmp = head;
		ListNode *result = head;

		int tick = 1;
		while (p != NULL)
		{
			if (tick == k)
			{
				tick = 1;
				if (pre == NULL)
				{
					pre = head;
					result = p;
				}
				else{
					tmp = pre;
					pre = pre->next;
					tmp->next = p;
				}
				p = p->next;
				reverseList(pre, k);
				pre->next = p;
			}
			else{
				tick++;
				p = p->next;
			}
		}
		return result;
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

	int k = 2;
	
	Solution solution;
	ListNode *result = solution.reverseKGroup(head, k);

	system("pause");
	return 0;
}