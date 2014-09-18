/************************************************************************/
/* 
https://oj.leetcode.com/problems/
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *result = NULL;
		ListNode *head= NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		result = new ListNode(l1->val + l2->val);
		l1 = l1->next;
		l2 = l2->next;
		head = result;

		while (l1 && l2)
		{
			result->next = new ListNode(result->val / 10);
			result->val %= 10;
			result = result->next;
			result->val += l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			result->next = new ListNode(result->val / 10);
			result->val %= 10;
			result = result->next;
			result->val += l1->val;
			l1 = l1->next;
		}
		while (l2)
		{
			result->next = new ListNode(result->val / 10);
			result->val %= 10;
			result = result->next;
			result->val += l2->val;
			l2 = l2->next;
		}
		if (result->val > 9)
		{
			result->next = new ListNode(result->val / 10);
			result->val %= 10;
		}

		return head;
	}
};

int main()
{
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;

	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution solution;
	ListNode *result = solution.addTwoNumbers(l1, l2);

	while (result != NULL)
	{
		cout << result->val << "->";
		result = result->next;
	}
	
	system("pause");
	return 0;
}