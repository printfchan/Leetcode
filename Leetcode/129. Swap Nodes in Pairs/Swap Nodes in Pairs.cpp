/************************************************************************/
/* 
https://oj.leetcode.com/problems/swap-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
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
	ListNode *swapPairs(ListNode *head) {
		return reverseKGroup(head, 2);
	}
};

int main()
{
	Solution solution;


	system("pause");
	return 0;
}