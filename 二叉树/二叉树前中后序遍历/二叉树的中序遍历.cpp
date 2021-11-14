#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
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
	void inorder(TreeNode*node)
	{
		if (node == NULL)
			return;
		inorder(node->left);
		ans.push_back(node->val);
		inorder(node->right);
		return;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		inorder(root);
		return ans;
	}
};

//µü´ú
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>ans;

		if (root == NULL)
			return ans;

		stack<TreeNode*>stack;

		while (root != NULL || !stack.empty())
		{
			while (root != NULL)
			{
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			ans.push_back(root->val);
			root = root->right;
			stack.pop();
		}
		return ans;
	}
};

//MorrisÖÐÐò±éÀú
