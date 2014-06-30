/************************************************************************/
/* 
https://oj.leetcode.com/problems/partition-list/
Given a linked list and a value x, partition it such that all nodes less than x come before nodes 
greater than or equal to x.
(所有小于x的节点要在大于等于x的节点之前，就是把小于x的节点提取到大于等于x的节点之前去，不改变相对位置)

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
	ListNode *partition(ListNode *head, int x) {
		ListNode *result = NULL;
		if (head == NULL)
			return head;

		ListNode *smNode = NULL;
		ListNode *lgNode = NULL;

		ListNode *p = head;
		ListNode *tmp = NULL;

		if (p->val < x)
		{
			smNode = head;
			result = smNode;
		}
		else
		{
			lgNode = head;
			tmp = head;
		}
		
		p = p->next;

		while (p)
		{
			if (p->val < x)
			{
				if (smNode)
				{
					smNode->next = p;
					smNode = smNode->next;
				}
				else{
					smNode = p;
					result = p;
				}
			}
			else{
				if (lgNode)
				{
					lgNode->next = p;
					lgNode = lgNode->next;
				}
				else{
					lgNode = p;
					tmp = p;
				}
			}
			p = p->next;
		}

		if (!smNode)
		{
			result = tmp;
		}
		else{
			smNode->next = tmp;
			if (lgNode)
			{
				lgNode->next = NULL;
			}
		}
		
		return result;
	}
};

int main()
{
	ListNode *head;
	head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	int x = 0;

	Solution solution;
	ListNode *result = solution.partition(head, 3);

	while (result != NULL)
	{
		cout << result->val << ' ';
		result = result->next;
	}

	system("pause");
	return 0;
}