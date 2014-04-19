/************************************************************************/
/* 
Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* pre = head;
		ListNode* p = head->next;
		ListNode* sp = NULL;
		while (pre->next != NULL)
		{
			// p is the node need to be insert to the previous node
			while (p != NULL && pre->val <= p->val)
			{
				pre = p;
				p = p->next;
			}
			if (p == NULL)
				break;
			// pre->val > p->val
			pre->next = p->next;
			if (p->val <= head->val)
			{
				p->next = head;
				head = p;
				p = pre->next;
				continue;
			}
			// else
			sp = head;
			while (p->val > sp->next->val)
			{
				sp = sp->next;
			}
			p->next = sp->next;
			sp->next = p;

			p = pre->next;
		}
		return head;
	}
};

int main()
{
	Solution solution;
	struct ListNode list(8);
	struct ListNode *lp = &list;

	lp->next = new ListNode(10);
	/*lp = lp->next;
	lp->next = new ListNode(5);
	lp = lp->next;
	lp->next = new ListNode(7);
	lp = lp->next;
	lp->next = new ListNode(2);
	lp = lp->next;
	lp->next = new ListNode(6);
	lp = lp->next;
	lp->next = new ListNode(4);
	lp = lp->next;*/

	lp = solution.insertionSortList(&list);

	while (lp != NULL)
	{
		cout << lp->val << ' ';
		lp = lp->next;
	}
	system("pause");
	return 0;
}


