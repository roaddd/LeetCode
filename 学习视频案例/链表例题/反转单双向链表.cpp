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
}node,*Node;

typedef struct doubleNode
{
	int value;
	struct doubleNode*next;
	struct doubleNode*pre;
	doubleNode(int data)
	{
		value = data;
	}
}doubleNode,*DoubleNode;

class Solution {
public:
	/* 反转单向链表 */
	Node reverseList(Node head)
	{
		Node pre = NULL;
		Node next = NULL;
		while (head != NULL)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
	/* 反转双向链表 */
	DoubleNode reverseList(DoubleNode head)
	{
		DoubleNode pre = NULL;
		DoubleNode next = NULL;
		while (head != NULL)
		{
			next = head->next;
			head->next = pre;
			head->pre = next;
			pre = head;
			head = next;
		}
		return pre;
	}
};

int main()
{
	//反转单向链表测试
	Node head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = NULL;
	Solution*s = new Solution;
	head1 = s->reverseList(head1);
	Node tmp = head1;
	while (tmp)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << "\n";
	//反转双向链表测试
	DoubleNode head2 = new doubleNode(1);
	head2->pre = NULL;
	head2->next = new doubleNode(2);
	head2->next->pre = head2;
	head2->next->next = new doubleNode(3);
	head2->next->next->next = NULL;
	head2->next->next->pre = head2->next;
	head2 = s->reverseList(head2);
	DoubleNode tmp2 = head2;
	while (tmp2)
	{
		cout << tmp2->value << " ";
		tmp2 = tmp2->next;
	}

	return 0;
}