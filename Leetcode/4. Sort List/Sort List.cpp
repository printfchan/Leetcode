#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	// O(n log n), O(constant)
	ListNode *sortList(ListNode *head) {
		if (head == NULL)
			return head;
		if (head->next == NULL)
			return head;

		return MergeSort(head);
	}

	ListNode* MergeSort(ListNode *head)
	{
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;

		ListNode* left = head;
		ListNode* right = head;
		while (right->next != NULL && right->next->next != NULL)
		{
			left = left->next;
			right = right->next->next;
		}

		// divide the list into two list
		ListNode* div = left->next;
		left->next = NULL;
		left = div;

		ListNode* lr = MergeSort(head);
		ListNode* rr = MergeSort(left);
		return Merge(lr, rr);
	}

	ListNode* Merge(ListNode* left, ListNode* right)
	{
		ListNode* head = NULL;
		ListNode* p = NULL;

		while (left != NULL && right != NULL)
		{
			if ((left->val) > (right->val))
			{
				if (p != NULL)
				{
					p->next = right;
					p = p->next;
				}
				else
				{
					p = right;
					head = p;
				}
				right = right->next;
			}
			else{
				if (p != NULL)
				{
					p->next = left;
					p = p->next;
				}
				else
				{
					p = left;
					head = p;
				}
				left = left->next;
			}
		}
		if (left == NULL)
		{
			p->next = right;
		}
		if (right == NULL)
		{
			p->next = left;
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
	lp = lp->next;
	lp->next = new ListNode(5);
	lp = lp->next;
	lp->next = new ListNode(7);
	lp = lp->next;
	lp->next = new ListNode(2);
	lp = lp->next;
	lp->next = new ListNode(6);
	lp = lp->next;
	lp->next = new ListNode(4);
	lp = lp->next;

	lp = solution.sortList(&list);

	
	while (lp != NULL)
	{
		cout << lp->val << ' ';
		lp = lp->next;
	}
	system("pause");
	return 0;
}


