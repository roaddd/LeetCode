#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//结合单调栈和哈希表解决，其中单调栈是从前往后遍历
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int size = nums2.size();
		vector<int>ans;
		unordered_map<int, int>umap;
		stack<int>nums;
		for (int i = 0; i < nums2.size(); i++)
		{
			while (!nums.empty() && nums2[i] > nums.top())
			{
				umap[nums.top()] = nums2[i];
				nums.pop();
			}
			nums.push(nums2[i]);
		}
		for (auto &elm:nums1)
		{
			if (umap.count(elm))
				ans.push_back(umap[elm]);
			else
				ans.push_back(-1);
		}
		return ans;
	}
};

//从后往前遍历
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int>umap;
		stack<int>stack;
		int size = nums1.size();
		vector<int>ans;
		for (int i = nums2.size() - 1; i >= 0; i--)
		{
			while (!stack.empty() && nums2[i] > stack.top())
			{
				stack.pop();
			}
			umap[nums2[i]] = stack.empty() ? -1 : stack.top();
			stack.push(nums2[i]);
		}
		for (int i = 0; i < nums1.size(); i++)
		{
			ans.push_back(umap[nums1[i]]);
		}
		return ans;
	}
};