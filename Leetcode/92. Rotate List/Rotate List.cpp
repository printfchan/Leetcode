/************************************************************************/
/* 
https://oj.leetcode.com/problems/rotate-list/
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		if (k <= 0)
		{
			return head;
		}

		ListNode *pre = NULL;
		ListNode *post = head;
		int len = 1;
		for (int i = 1; i < k; ++i)
		{
			post = post->next;
			if (post == NULL)
				break;
			
			len++;
		}
		if (post == NULL)
		{
			k %= len;
			if (k == 0)
			{
				return head;
			}

			post = head;
			k--;
			while (k > 0 && post != NULL)
			{
				post = post->next;
				k--;
			}
		}

		while (post->next != NULL)
		{
			post = post->next;
			if (pre)
			{
				pre = pre->next;
			}
			else
			{
				pre = head;
			}
		}
		
		if (pre == NULL)
		{
			return head;
		}

		ListNode *newhead = pre->next;
		pre->next = NULL;
		post->next = head;

		return newhead;
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
	ListNode *result = solution.rotateRight(head, k);

	system("pause");
	return 0;
}

