/************************************************************************/
/* 
https://oj.leetcode.com/problems/reverse-linked-list-ii/
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
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
	/************************************************************************/
	/* 
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,
	=> 1->   2<-3<-4  ->5
	start = 1;
	end = 2;
	tmp = 4;
	pre = cur = 5;
	return 1->4->3->2->5->NULL.                                             
	*/
	/************************************************************************/
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL)
			return head;

		ListNode *start = NULL;
		ListNode *end = NULL;

		ListNode *tmp = NULL;
		ListNode *pre = NULL;
		ListNode *cur = head;

		int i = 0;
		for (i = 0; i < m - 1; ++i)
		{
			pre = cur;
			cur = cur->next;
		}

		start = pre;
		end = cur;

		tmp = cur;
		cur = cur->next;
		pre = cur;
		tmp->next = NULL;
		for (; i < n - 1; ++i)
		{
			cur = cur->next;
			pre->next = tmp;
			tmp = pre;
			pre = cur;
		}

		if (start)
			start->next = tmp;
		else
			head = tmp;
		end->next = cur;

		return head;
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

	int m = 1;
	int n = 4;
	Solution solution;
	ListNode *result = solution.reverseBetween(head, m, n);

	while (result)
	{
		cout << result->val << " ";
		result = result->next;
	}
	system("pause");
	return 0;
}