/************************************************************************/
/* 
https://oj.leetcode.com/problems/merge-k-sorted-lists/
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
	ListNode* MergeList(ListNode *first, ListNode *second)
	{
		ListNode *result = NULL;
		ListNode *head = NULL;

		if (first == NULL)
		{
			return second;
		}
		if (second == NULL)
		{
			return first;
		}

		ListNode *p1 = first;
		ListNode *pn1 = NULL;

		ListNode *p2 = second;
		ListNode *pn2 = NULL;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val < p2->val)
			{
				if (result == NULL)
				{
					head = p1;
					result = p1;
					p1 = p1->next;
					result->next = NULL;
				}
				else
				{
					result->next = p1;
					result = p1;
					p1 = p1->next;
					result->next = NULL;
				}
			}
			else
			{
				if (result == NULL)
				{
					head = p2;
					result = p2;
					p2 = p2->next;
					result->next = NULL;
				}
				else
				{
					result->next = p2;
					result = p2;
					p2 = p2->next;
					result->next = NULL;
				}
			}
		}
		if (p1)
		{
			result->next = p1;
		}
		if (p2)
		{
			result->next = p2;
		}
		return head;
	}

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.size() == 0)
			return NULL;

		ListNode *result = lists[0];
		for (int i = 1; i < lists.size(); ++i)
		{
			result = MergeList(result, lists[i]);
		}
		return result;
	}
};

int main()
{
	vector<ListNode *> lists;

	ListNode *list1 = NULL;

	list1 = new ListNode(2);
	list1->next = new ListNode(6);
	list1->next->next = new ListNode(8);
	list1->next->next->next = new ListNode(10);

	lists.push_back(list1);

	ListNode *list2 = NULL;

	list2 = new ListNode(1);
	list2->next = new ListNode(5);
	list2->next->next = new ListNode(9);
	list2->next->next->next = new ListNode(14);

	lists.push_back(list2);

	Solution solution;
	ListNode *result = solution.mergeKLists(lists);

	while (result != NULL)
	{
		cout << result->val << "->";
		result = result->next;
	}

	system("pause");
	return 0;
}