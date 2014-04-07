#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	static ListNode *sortList(ListNode *head) {
		
	}
};
int main()
{
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

	Solution::sortList(&list);

	system("pause");
	return 0;
}


