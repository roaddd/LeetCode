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
	ListNode* reverseList(ListNode* head) {
		if (head->next == NULL)return head;
		ListNode*  nextNode = head->next;

		ListNode* reversedHead =reverseList(head->next);
		
		nextNode->next = head;
		head->next = NULL;
		return reversedHead;
	}
};

int main()
{
	return 0;
}