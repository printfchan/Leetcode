/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *p = head;
		ListNode *root = head;
		ListNode *sameStart = NULL;
		while (p)
		{
			if (p->next == NULL)
			{
				break;
			}

			if (p->next->val == p->val)
			{
				sameStart = p;
				p = p->next;
				while (p)
				{
					if (p->val == sameStart->val)
						p = p->next;
					else
						break;
				}
				sameStart->next = p;
			}
			else
				p = p->next;
		}
		return root;
	}
};

int main()
{
	ListNode *head = NULL;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next->next = new ListNode(5);

	Solution solution;
	ListNode *result = solution.deleteDuplicates(head);

	while (result)
	{
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	system("pause");
	return 0;
}