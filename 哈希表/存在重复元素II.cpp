#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

//哈希映射
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int>umap;
		for (int i=0;i<nums.size();i++)
		{
			if (umap.count(nums[i]) != 0)
			{
				int sub = i - umap[nums[i]];
				if (sub <= k)return true;
			}
				umap[nums[i]] = i;
		}
		return false;
	}

};

//使用哈希集合维护一个大小为k的滑动窗口
class Solution2 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int>uset;
		for (int i = 0; i < nums.size(); i++)
		{
			if (uset.count(nums[i]) != 0)return true;
			uset.insert(nums[i]);
			if (uset.size() > k)uset.erase(nums[i - k]);
		}
		return false;
	}
};


int main()
{
	Solution2*s = new Solution2;
	vector<int>nums{1,2,3,1,2,3 };
	cout<<s->containsNearbyDuplicate(nums,2);

	return 0;
}