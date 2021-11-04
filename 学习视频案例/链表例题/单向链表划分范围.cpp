#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	int value;
	struct node* next;
	node(int data)
	{
		value = data;
	}
}node,*Node;

/* 将单向链表按某值划分成左边小、中间相等、右边大的形式 */
class Solution {
public:
	/* 方法一：利用额外空间 */
	void arrPartion(vector<node*>&nodeArr, int pivot)
	{
		int small = -1;
		int big = nodeArr.size();
		for (int i = 0; i < nodeArr.size(); i++)
		{
			if (nodeArr[i]->value < pivot)
				swap(nodeArr[i++], nodeArr[++small]);
			else if (nodeArr[i]->value > pivot)
				swap(nodeArr[i], nodeArr[--big]);
			else
				i++;
		}
	}

	Node smallerEqualBigger1(Node head,int pivot)
	{
		if (head == NULL)
			return head;
		node* cur = head;
		vector<node*>nodeArr;
		while (cur != NULL)
		{
			nodeArr.push_back(cur);
			cur = cur->next;
		}
		arrPartion(nodeArr, pivot);
		int i = 0;
		for (; i < nodeArr.size() - 1; i++)
			nodeArr[i]->next = nodeArr[i + 1];
		nodeArr[i]->next = NULL;
		return nodeArr[0];
	}

	/* 方法二：不使用额外空间 */
	Node smallerEqualBigger2(Node head, int pivot)
	{
		Node smallHead=NULL;
		Node smallTail = NULL;
		Node equalHead = NULL;
		Node equalTail = NULL;
		Node bigHead = NULL;
		Node bigTail = NULL;
		node* cur = head;
		while (cur != NULL)
		{
			if (cur->value < pivot)
				if (smallHead == NULL)
					smallHead = smallTail = cur;
				else
				{
					smallTail->next = cur;
					smallTail = smallTail->next;
				}
			else if (cur->value > pivot)
				if (bigHead == NULL)
					bigHead = bigTail = NULL;
				else
				{
					bigTail->next = cur;
					bigTail = bigTail->next;
				}
			else
				if (equalHead == NULL)
					equalHead = equalTail = NULL;
				else
				{
					equalTail->next = cur;
					equalTail = equalTail->next;
				}
		}
		if (smallTail != NULL)
		{
			smallTail->next = equalHead;
			equalTail = equalTail == NULL ? smallTail : equalTail;
		}
		if (equalTail != NULL)
		{
			equalTail->next = bigHead;
			bigTail = bigTail == NULL ? equalTail : bigTail;
		}
		return smallHead != NULL ? smallHead : equalHead != NULL ? equalHead : bigHead;
	}
};

int main()
{
	Node head = new node(3);
	head->next = new node(2);
	head->next->next = new node(1);
	head->next->next->next = NULL;
	Solution*s = new Solution;
	//Node ans = s->smallerEqualBigger1(head, 2);
	Node ans = s->smallerEqualBigger2(head, 2);
	while (ans)
	{
		cout << ans->value;
		ans = ans->next;
	}
	return 0;
}