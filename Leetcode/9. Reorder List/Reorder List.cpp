/************************************************************************/
/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
	void reorderList(ListNode *head) {
		ListNode *p1 = head;
		ListNode *p2 = head;
		if (head == NULL || (head->next == NULL) || (head->next->next == NULL))
			return ;

		while (p2->next != NULL && p2->next->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}

		ListNode *h1 = head;
		ListNode *h2 = p1->next;
		p1->next = NULL;

		h2 = reverseNode(h2);
		ListNode* tmp = NULL;

		while (h2 != NULL)
		{
			tmp = h2->next;
			h2->next = h1->next;
			h1->next = h2;
			h1 = h2->next;
			h2 = tmp;
		}
	}
	ListNode* reverseNode(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		
		ListNode* nt = head->next;
		head->next = NULL;
		ListNode* newhead = head;
		ListNode* p = nt;

		while (p != NULL)
		{
			nt = p->next;
			p->next = newhead;
			newhead = p;
			p = nt;
		}
		return newhead;
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

	Solution solution;
	solution.reorderList(head);
	//head = solution.reverseNode(head);

	while (head!=NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	
	system("pause");
	return 0;
}