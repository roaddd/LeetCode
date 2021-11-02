#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node {
	int value;
	struct node* next;
	node(int data)
	{
		value = data;
	}
}node, *Node;

class Solution {
public:
	void printCommonPart(Node head1,Node head2)
	{
		Node h1 = head1;
		Node h2 = head2;
		while (h1&&h2)
		{
			if (h1->value > h2->value)
				h2 = h2->next;
			else if (h1->value < h2->value)
				h1 = h1->next;
			else
			{
				cout << h1->value << " ";
				h1 = h1->next;
				h2 = h2->next;
			}
		}
	}
};

/*
	如果两个链表的长度之和为N，时间复杂度要求为O(N)，额外空间复杂度要求为O(1)
*/
int main()
{
	Node head2 = new node(1);
	head2->next = new node(2);
	head2->next->next = new node(5);
	head2->next->next->next = NULL;

	Node head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = NULL;
	Solution*s = new Solution;
	s->printCommonPart(head1, head2);
	return 0;
}