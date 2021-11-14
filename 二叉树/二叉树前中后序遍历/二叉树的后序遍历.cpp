#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归
class Solution {
	vector<int>ans;
public:
	void postorder(TreeNode*root)
	{
		if (root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		ans.push_back(root->val);
		return;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		postorder(root);
		return ans;
	}
};

//迭代
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>ans;

		if (root == NULL)
			return ans;

		stack<TreeNode*>stack;
		TreeNode* node = root;
		TreeNode* prenode = NULL;

		while (!stack.empty() || node != NULL)
		{
			while (node != NULL)
			{
				stack.push(node);
				node = node->left;
			}
			node = stack.top();
			stack.pop();
			if (node->right == NULL || node->right == prenode)
			{
				ans.push_back(node->val);
				prenode = node;
				node = NULL;
			}
			else
			{
				stack.push(node);//再次入栈
				node = node->right;
			}
		}
		return ans;
	}
};