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

//µÝ¹é
class Solution {
	vector<int>ans;
public:
	void preorder(TreeNode*root)
	{
		if (root == NULL)
			return;
		ans.push_back(root->val);
		preorder(root->left);
		preorder(root->right);
		return;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		preorder(root);
		return ans;
	}
};

//µü´ú
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>ans;
		
		if (root == NULL)
			return ans;

		stack<TreeNode*>stack;

		TreeNode*node = root;

		while (node != NULL || !stack.empty())
		{
			while (node != NULL)
			{
				ans.emplace_back(node->val);
				stack.emplace(node);
				node = node->left;
			}
			node = stack.top();
			stack.pop();
			node = node->right;
		}
		return ans;
	}
};