#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


/*
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
(待解决)如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/


//哈希表
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			intersect(nums2, nums1);//将较小的一个进行哈希映射
		vector<int>vec;
		unordered_map<int, int>umap;
		for (int elm : nums1)
			umap[elm]++;
		for (auto elm : nums2)
		{
			if (umap[elm] > 0)
			{
				vec.push_back(elm);
				umap[elm]--;
			}
		}
		return vec;
	}
};

//排序双指针
class Solution2 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto iter1 = nums1.begin();
		auto iter2 = nums2.begin();
		vector<int>ret;
		while (iter1 != nums1.end() && iter2 != nums2.end())
		{
			if (*iter1 == *iter2)
			{
				ret.push_back(*iter1);
				iter1++;
				iter2++;
			}
			else if (*iter1 < *iter2)
				iter1++;
			else iter2++;
		}
		return ret;
	}
};

int main()
{
	Solution2*s = new Solution2;
	vector<int>nums1 = {4,9,5 };
	vector<int>nums2 = {9,4,9,8,4};
	vector<int>vec = s->intersect(nums1, nums2);
	for (int elm : vec)
		cout << elm << " ";
	return 0;
}