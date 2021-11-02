#include <iostream>
#include <stack>
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
	/* 利用栈 */
	bool isPalindromeList(Node head1)
	{
		stack<int>stack;
		Node fast= head1,slow=head1;
		while (fast!=NULL&&fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		Node mid = slow;
		//将链表后半部分的值入栈
		while (slow != NULL)
		{
			stack.push(slow->value);
			slow = slow->next;
		}
		fast = head1;
		while (fast != mid)
		{
			if (fast->value != stack.top())
				return false;
			stack.pop();
			fast = fast->next;
		}
		return true;
	}
	/* 利用反转部分链表 */
	bool isPalindromeList1(Node head1)
	{
		Node n1 = head1, n2 = head1;
		while (n1->next!= NULL && n1->next->next != NULL)
		{
			n1 = n1->next->next;
			n2 = n2->next;
		}
		n1 = n2->next;//右半部分的头结点
		n2->next = NULL;//mid.next=NULL
		//进行反转
		Node n3 = NULL;
		while (n1 != NULL)
		{
			n3 = n1->next;
			n1->next = n2;
			n2 =n1;
			n1 = n3;
		}
		n3 = n2;//
		n1 = head1;
		bool res = true;
		while (n2!=NULL&&n1!=NULL)
		{
			if (n2->value != n1->value)
			{
				res= false;
				break;
			}
			n2 = n2->next;
			n1 = n1->next;
		}
		//还原链表
		n2 = n3->next;
		n3->next = NULL;
		while (n2)
		{
			n1 = n2->next;
			n2->next = n3;
			n3 = n2;
			n2 = n1;
		}
		return res;
	}
};

int main()
{
	Node head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(1);
	head1->next->next->next = NULL;
	Solution*s = new Solution;
	cout << s->isPalindromeList(head1)<<"\n";
	cout << s->isPalindromeList1(head1);
	return 0;
}