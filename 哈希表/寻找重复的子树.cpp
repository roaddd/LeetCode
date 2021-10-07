#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <array>
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
//定义二叉树结点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//深度优先搜索
class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		collect(root);
		return ret;
	}
	string collect(TreeNode *root)
	{
		if (root == NULL)return "#";
		//to_string：将整数转换为字符串
		string serial = to_string(root->val) +","+ collect(root->left) +","+ collect(root->right);//先序遍历二叉树
		umap[serial]++;
		if (umap[serial] == 2)//有重复的二叉子树
			ret.push_back(root);
		return serial;
	}
private:
	unordered_map<string, int>umap;
	vector<TreeNode*>ret;
};

//唯一标识符
class Solution
{
public:
	vector<TreeNode*>findDuplicateSubtrees(TreeNode* root)
	{
		t = 1;
		book(root);
		return ret;
	}
	string book(TreeNode*node)
	{
		if (node == NULL)return 0;
		string s = to_string(node->val) + "," + book(node->left) + "," + book(node->right);
		if (umap.count(s) == 0)
			umap[s] = t++;
		int uid = umap[s];//记录该子树对应的id
		count[uid]++;//该子树映射的id出现的次数加一
		if (count[uid] == 2)//如果该子树对应的id出现过
			ret.push_back(node);
		return to_string(uid);
	}
private:
	int t;//用来映射子树，递增保证不重复
	unordered_map<string, int>umap;
	unordered_map<int, int>count;
	vector<TreeNode*>ret;
};

TreeNode* create()
{
	char ch;
	cin >> ch;
	TreeNode* T = new TreeNode;
	if (ch == '#')T = NULL;
	else
	{
		T->val = (int)(ch-'0');//将字符转换为整数
		T->left=create();
		T->right=create();
	}
	return T;
}

int main()
{
	TreeNode* T=create();
	Solution*s = new Solution;
	vector<TreeNode*>ans = s->findDuplicateSubtrees(T);
	for (auto elm : ans)
		cout << elm->val << " ";
	return 0;
}