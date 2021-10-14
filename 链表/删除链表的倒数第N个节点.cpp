#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head;
		ListNode* slow = head;
		for (int i = 0; i < n; i++)
			fast = fast->next;

		if (fast == NULL)
			return head->next;

		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};

class Solution2 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int pos = length(head, n);
		//说明删除的是头结点
		if (pos == n)
			return head->next;
		return head;
	}

	int length(ListNode*node, int n)
	{
		if (node == NULL)return 0;
		int pos = length(node->next, n)+1;
		if (pos == n + 1)
			node->next = node->next->next;
		return pos;
	}
};

int main()
{

	return 0;
}