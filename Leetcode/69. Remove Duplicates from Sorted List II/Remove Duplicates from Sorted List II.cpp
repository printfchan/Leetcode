/************************************************************************/
/* 
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
		
		ListNode *pre = NULL;
		ListNode *p = head;
		ListNode *root = NULL;
		ListNode *sameStart = NULL;
		while (p)
		{
			if (p->next == NULL)
			{
				if (!pre)
				{
					root = p;
					pre = p;
					p = p->next;
					pre->next = NULL;
				}
				else
				{
					pre->next = p;
					pre = p;
					p = p->next;
					pre->next = NULL;
				}
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
				continue;
			}
			
			if (!pre)
			{
				root = p;
				pre = p;
				p = p->next;
				pre->next = NULL;
			}
			else
			{
				pre->next = p;
				pre = p;
				p = p->next;
				pre->next = NULL;
			}		
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