#include <iostream>
#include <vector>
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

//广度优先搜索
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL)return {};
		queue<TreeNode*>que;
		que.push(root);
		vector<vector<int>>ret;
		while (!que.empty())
		{
			int sz = que.size();
			vector<int>sub_vec;
			while (sz > 0)
			{
				TreeNode*node = que.front();
				sub_vec.push_back(node->val);
				que.pop();
				if (node->left != NULL)
					que.push(node->left);
				if (node->right != NULL)
					que.push(node->right);
				sz--;
			}
			ret.push_back(sub_vec);
		}
		return ret;
	}
};