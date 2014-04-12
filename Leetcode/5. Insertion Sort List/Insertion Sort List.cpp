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

	lp = solution.insertionSortList(&list);


	while (lp != NULL)
	{
		cout << lp->val << ' ';
		lp = lp->next;
	}
	system("pause");
	return 0;
}


