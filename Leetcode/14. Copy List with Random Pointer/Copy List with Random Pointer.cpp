/************************************************************************/
/* 
A linked list is given such that each node contains an additional random pointer \
which could point to any node in the list or null.

Return a deep copy of the list.
*/
/************************************************************************/

#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *copy = NULL;
		if (head == NULL)
			return copy;

		RandomListNode* p1 = head;
		RandomListNode* p2 = copy;
		
		while (p1 != NULL)
		{
			p2 = new RandomListNode(p1->label);
			p2->next = p1->next;
			p1->next = p2; 
			if (p1->random != NULL)
				p2->random = p1->random;
			p1 = p2->next;
		}
		
		copy = head->next;

		p1 = head;
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p2->random != NULL)
			{
				p2->random = p2->random->next;
			}
			if (p2->next != NULL)
			{
				p2 = p2->next->next;
			}
			else{
				break;
			}
		}

		p1 = head;
		p2 = p1->next;
		while (p1 != NULL)
		{
			p1->next = p2->next;

			if (p2->next != NULL)
			{
				p2->next = p2->next->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		return copy;
	}
};

int main()
{
	Solution solution;

	RandomListNode *head;
	head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(3);
	head->next->next->next = new RandomListNode(4);
	head->next->next->next->next = new RandomListNode(5);
	//head->next->next->next->next->next = head->next;
	

	RandomListNode *copy = solution.copyRandomList(head);

	system("pause");
	return 0;
}