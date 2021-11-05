#include <iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node* next;
	node(int data)
	{
		value = data;
	}
}node, *Node;

/* 给定两个可能有环也可能无环的单链表，头节点head1和head2。请实
现一个函数，如果两个链表相交，请返回相交的第一个节点。如果不相交,返
回null */
class Solution {
public:
	/* 若链表有环则返回环的入口结点，若没有环则返回空 */
	Node getLoopNode(Node head)
	{
		if (head->next == NULL || head->next->next == NULL)
			return NULL;
		//先让快慢指针走一步
		Node fast = head->next->next;
		Node slow = head->next;
		while (fast != slow)
		{
			if (fast->next == NULL || fast->next->next == NULL)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		//快慢指针在环内相遇之后令快指针置为头结点，快慢指针同时移动一步，再次相遇时即为环入口
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}

	Node noLoop(Node head1, Node head2)
	{
		int n = 0;
		Node cur1 = head1;
		Node cur2 = head2;
		while (cur1 != NULL)
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2 != NULL)
		{
			n--;
			cur2 = cur2->next;
		}
		//如果最末端结点不同则两链表肯定不相交
		if (cur1 != cur2)
			return NULL;
		//将cur1指向最长的链表
		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		//将cur1前进abs(n)
		n = abs(n);
		while (n != 0)
		{
			n--;
			cur1 = cur1->next;
		}
		//cur1与cur2同时前进
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	Node bothLoop(Node head1,Node loop1, Node head2,Node loop2)
	{
		Node cur1 = head1;
		Node cur2 = head2;
		if (loop1 == loop2)
		{
			int n = 0;
			while (cur1 != loop1)
			{
				n++;
				cur1 = cur1->next;
			}
			while (cur2 != loop2)
			{
				n--;
				cur2 = cur2->next;
			}
			cur1 = n > 0 ? head1 : head2;
			cur2 = cur1 == head1 ? head2 : head1;
			n = abs(n);
			while (n != 0)
			{
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
		else
		{
			cur1 = loop1->next;
			while (cur1 != loop1)
			{
				if (cur1 == loop2)
					return loop1;
				cur1 = cur1->next;
			}
			return NULL;//两个链表都有环但是不相交
		}
	}

	Node findFirstIntersectNode(Node head1,Node head2)
	{
		if (head1 == NULL || head2 == NULL)
			return NULL;
		Node loop1 = getLoopNode(head1);
		Node loop2 = getLoopNode(head2);
		//情况一：两个链表都无环
		if (loop1 == NULL && loop2 == NULL)
			return noLoop(head1, head2);
		//情况二：两个链表都有环
		if (loop1 != NULL && loop2 != NULL)
			return bothLoop(head1,loop1, head2,loop2);
		return NULL;
	}
};

int main()
{
	// 1->2->3->4->5->6->7->null
	Node head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = new node(4);
	head1->next->next->next->next = new node(5);
	head1->next->next->next->next->next = new node(6);
	head1->next->next->next->next->next->next = new node(7);

	// 0->9->8->6->7->null
	Node head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	

	// 1->2->3->4->5->6->7->4...
	head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = new node(4);
	head1->next->next->next->next = new node(5);
	head1->next->next->next->next->next = new node(6);
	head1->next->next->next->next->next->next = new node(7);
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

	// 0->9->8->2...
	head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next; // 8->2


	// 0->9->8->6->4->5->6..
	head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6

	Solution*s = new Solution;
	Node ans = s->findFirstIntersectNode(head1, head2);
	cout << ans->value;

	return 0;
}