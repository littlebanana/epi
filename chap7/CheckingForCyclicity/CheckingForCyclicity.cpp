// 7.2 Checking for cyclicity

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
};

int main()
{
	Solution solu;

	ListNode *node;
	if ((node = solu.cycleNode(NULL)) == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << node->val << endl;
	}

	ListNode *l = new ListNode(1);
	l->next = new ListNode(2);
	l->next->next = new ListNode(3);
	l->next->next->next = new ListNode(4);
	l->next->next->next->next = new ListNode(5);
	l->next->next->next->next->next = new ListNode(6);
	l->next->next->next->next->next->next = new ListNode(7);
	l->next->next->next->next->next->next->next = new ListNode(8);
	l->next->next->next->next->next->next->next->next = new ListNode(9);
	l->next->next->next->next->next->next->next->next->next = l->next->next->next->next->next;
	if ((node = solu.cycleNode(l)) == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << node->val << endl;
	}

	return 0;
}
