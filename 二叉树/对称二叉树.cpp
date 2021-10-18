#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//迭代
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return false;

		stack<TreeNode*>stack_left;
		stack<TreeNode*>stack_right;

		TreeNode*left = root->left;
		TreeNode*right = root->right;
		//这里注意思考为什么要添加left!=NULL的条件
		while ((!stack_left.empty()||left!=NULL) && (!stack_right.empty()||right!=NULL))
		{
			while (left != NULL&&right!=NULL)
			{
				stack_left.push(left);
				left = left->left;
				stack_right.push(right);
				right = right->right;
				if (left == NULL ^ right == NULL)//异或位运算：相异为1
					return false;
			}
			TreeNode*nodel = stack_left.top();
			TreeNode*noder = stack_right.top();
			stack_left.pop();
			stack_right.pop();
			if (nodel->val != noder->val)
				return false;
			left = nodel->right;
			right = noder->left;
		}

		if (stack_left.empty() && stack_right.empty())
			if(left==NULL&&right==NULL)
				return true;
		return false;
	}
};

//递归
class Solution {
public:
	bool check(TreeNode*p, TreeNode*q)
	{
		if (!p && !q)return true;
		if (!p || !q)return false;
		return p->val == q->val&&check(p->left, q->right) && check(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}
};

void create(TreeNode*&T)
{
	char c;
	cin >> c;
	T = new TreeNode;
	if (c == '#')T = NULL;
	else
	{
		T->val = c;
		create(T->left);
		create(T->right);
	}
}

int main()
{
	TreeNode* T;
	create(T);
	Solution*s = new Solution;
	cout << s->isSymmetric(T);
	return 0;
}