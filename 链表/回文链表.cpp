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

/* 如果使用递归反向迭代节点，同时使用递归函数外的变量向前迭代，就可以判断链表是否为回文。 */
class Solution {
	ListNode* frontPointer;
public:

	bool recursivelyCheck(ListNode*currentNode)
	{
		if (currentNode != NULL)
		{
			if (!recursivelyCheck(currentNode->next))
				return false;
			if (currentNode->val != frontPointer->val)
				return false;
			frontPointer = frontPointer->next;
		}
		return true;
	}

	bool isPalindrome(ListNode* head) {
		frontPointer = head;
		return recursivelyCheck(head);
	}
};
/*
时间复杂度：O(n)，其中 n 指的是链表的大小。
空间复杂度：O(n)，其中 n 指的是链表的大小。我们要理解计算机如何运行递归函数，在一个函数中调用一个函数时，
计算机需要在进入被调用函数之前跟踪它在当前函数中的位置（以及任何局部变量的值），通过运行时存放在堆栈中来实现（堆栈帧）。
在堆栈中存放好了数据后就可以进入被调用的函数。在完成被调用函数之后，他会弹出堆栈顶部元素，以恢复在进行函数调用之前所在的函数。
在进行回文检查之前，递归函数将在堆栈中创建 n 个堆栈帧，计算机会逐个弹出进行处理。所以在使用递归时空间复杂度要考虑堆栈的使用情况。

这种方法不仅使用了 O(n)O(n)O(n) 的空间，且比第一种方法更差，因为在许多语言中，堆栈帧的开销很大（如 Python），
并且最大的运行时堆栈深度为 1000（可以增加，但是有可能导致底层解释程序内存出错）。
为每个节点创建堆栈帧极大的限制了算法能够处理的最大链表大小。

*/

/*
	为了达到0(1)的空间复杂度，采用改变输入的方法。
	将链表的后半部分反转。但是该方法在并发的环境下有缺点，函数执行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改。
*/

class Solution {
public:
	bool isPalindrome(ListNode*head)
	{
		if (head == NULL)
			return true;
		//快慢指针寻找链表中点
		ListNode*fast = head;
		ListNode*slow = head;
		while (fast->next!=NULL&&fast->next->next!=NULL)
		{
			fast = fast->next->next;//快指针走两步
			slow=slow->next;//慢指针走一步
		}
		//反转后半部分
		slow->next=reverseList(slow->next);
		//前半部分与后半部分对比
		ListNode*p1 = head;
		ListNode*p2 = slow->next;
		bool result=true;
		while (result&&p2 != NULL)
		{
			if (p2->val != p1->val)
				result=false;
			p2 = p2->next;
			p1 = p1->next;
		}
		//还原链表的后半部分
		slow->next = reverseList(slow->next);
		return result;
	}

	//反转链表的递归写法
	ListNode* reverseList(ListNode*node)
	{
		if (node == NULL||node->next==NULL)
			return node;
		ListNode* nextNode = node->next;
		ListNode* reversed = reverseList(node->next);
		nextNode->next = node;
		node->next = NULL;
		return reversed;
	}
	//反转链表的非递归写法
	ListNode* reverseList(ListNode*node)
	{
		ListNode*prev = NULL;
		ListNode*curr = node;
		while (node != NULL)
		{
			ListNode*tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
	}

};