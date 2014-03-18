// 7.4 Overlapping lists - No lists have cycles

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
		ListNode* cycleNode(ListNode *head)
		{
			ListNode *slow = NULL;
			ListNode *fast = head;
			while (fast != NULL && slow != fast)
			{
				if (fast->next == NULL || fast->next->next == NULL)
				{
					return NULL;
				}
				if (slow == NULL)
				{
					slow = head->next;
				}
				else
				{
					slow = slow->next;
				}
				fast = fast->next->next;
			}
			if (fast == NULL)
			{
				return NULL;
			}

			slow = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}

		ListNode* overlappedNode(ListNode *l1, ListNode *l2)
		{
			if (l1 == NULL || l2 == NULL)
			{
				return NULL;
			}

			ListNode *tail1 = l1;
			while (tail1->next != NULL)
			{
				tail1 = tail1->next;
			}

			// tempoarily link the tail of list 1 to the head of list 2
			tail1->next = l2;

			ListNode *node = cycleNode(l1);
			tail1->next = NULL;
			return node;
		}
};

int main()
{
	Solution solu;

	ListNode *node;

	ListNode *l = new ListNode(1);
	l->next = new ListNode(2);
	l->next->next = new ListNode(3);
	l->next->next->next = new ListNode(4);
	l->next->next->next->next = new ListNode(5);
	l->next->next->next->next->next = new ListNode(6);
	l->next->next->next->next->next->next = new ListNode(7);
	l->next->next->next->next->next->next->next = new ListNode(8);
	l->next->next->next->next->next->next->next->next = new ListNode(9);
	ListNode *t = new ListNode(100);
	t->next = new ListNode(200);
	t->next->next = new ListNode(200);
	t->next->next->next = new ListNode(200);
	t->next->next->next->next = l->next->next->next->next->next->next->next;

	if ((node = solu.overlappedNode(l, t)) == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << node->val << endl;
	}

	return 0;
}
