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

//此处递归画图便于理解
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MAX, LONG_MIN);
	}
	bool isValidBST(TreeNode*root, long maxVal, long minVal)
	{
		if (root == NULL)
			return true;
		if (root->val >= maxVal || root->val <= minVal)
			return false;
		return isValidBST(root->left, root->val, minVal) && isValidBST(root->right, maxVal, root->val);
	}
};

//递归中序遍历
class Solution {
	long min = LONG_MIN;
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		if(!isValidBST(root->left))
			return false;

		if (root->val <= min)
			return false;
		min = root->val;

		if(!isValidBST(root->right))
			return false;

		return true;
	}
};

//迭代中序遍历
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*>stack;
		long inorder = LONG_MIN;
		while (!stack.empty()||root!=NULL)
		{
			while (root)
			{
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			if (root->val <= inorder)
				return false;
			inorder = root->val;
			root = root->right;
		}
		return true;
	}
};