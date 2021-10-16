#include <iostream>
#include <algorithm>
#include <queue>
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

//深度优先
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		return max(maxDepth(root->left),maxDepth(root->right))+1;
	}
};

//广度优先
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)return 0;
		int ans = 0;
		queue<TreeNode*>que;
		que.push(root);
		while (!que.empty())
		{
			int sz = que.size();
			while (sz > 0)
			{
				TreeNode*node = que.front();
				que.pop();
				if (node->left)que.push(node->left);
				if (node->right)que.push(node->right);
				sz--;
			}
			ans++;
		}
		return ans;
	}
};