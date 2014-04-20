/************************************************************************/
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/
/************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return NULL;

		ListNode* p1 = head;
		ListNode* p2 = head;

		while (p1 != NULL && p2->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == NULL || p2 == NULL)
				return NULL;
			// first time to meet
			if (p1 == p2)
			{
				break;
			}
		}
		if (p2->next == NULL)
			return NULL;

		p1 = head;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};

int main()
{
	ListNode *head;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = head->next;

	Solution solution;
	ListNode *meetP = solution.detectCycle(head);
	//head = solution.reverseNode(head);

	if (meetP != NULL)
		cout << meetP->val;

	system("pause");
	return 0;
}