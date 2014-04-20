/************************************************************************/
/* 
Given a linked list, determine if it has a cycle in it.

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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;

		ListNode* p1 = head;
		ListNode* p2 = head;

		while (p1 != NULL && p2->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == NULL || p2 == NULL)
				return false;
			// first time to meet
			if (p1 == p2)
			{
				return true;
			}
		}
		return false;
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
	bool hascircle = solution.hasCycle(head);
	//head = solution.reverseNode(head);

	if (hascircle)
		cout << "has circle." << endl;
	else
		cout << "don't has circle." << endl;

	system("pause");
	return 0;
}