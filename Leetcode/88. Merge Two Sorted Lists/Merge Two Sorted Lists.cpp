/************************************************************************/
/* 
https://oj.leetcode.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL)
		{
			l1 = l2;
			return l1;
		}
		if (l2 == NULL)
		{
			return l1;
		}

		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *p3 = NULL;
		ListNode *result = NULL;

		while (p2 != NULL && p1 != NULL)
		{
			if (p1->val < p2->val)
			{
				if (p3 == NULL)
				{
					p3 = p1;
					result = p3;
				}
				else{
					p3->next = p1;
					p3 = p1;
				}
				p1 = p1->next;
			}
			else{
				if (p3 == NULL)
				{
					p3 = p2;
					result = p3;
				}
				else{
					p3->next = p2;
					p3 = p2;
				}
				p2 = p2->next;
			}
		}
		if (p1 != NULL)
		{
			p3->next = p1;
		}
		if (p2 != NULL)
		{
			p3->next = p2;
		}
		return result;
	}
};

int main()
{
	ListNode *l1 = NULL;
	l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	l1->next->next->next = new ListNode(5);

	ListNode *l2 = NULL;
	l2 = new ListNode(3);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(7);
	l2->next->next->next = new ListNode(10);

	Solution solution;
	ListNode* result = solution.mergeTwoLists(l1, l2);

	while (result != NULL)
	{
		cout << result->val << ' ';
		result = result->next;
	}
	

	system("pause");
	return 0;
}