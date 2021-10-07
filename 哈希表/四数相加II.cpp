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

//利用加法的结合律
class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int,int>umap;
		int sum=0;
		for(int i=0;i<nums1.size();i++)
			for (int j = 0; j < nums2.size(); j++)
			{
				umap[nums1[i] + nums2[j]]++;
			}
		for (int i = 0; i < nums3.size(); i++)
			for (int j = 0; j < nums4.size(); j++)
			{
				if (umap.count(-(nums3[i] + nums4[j])) != 0)
					sum+=umap[-(nums3[i] + nums4[j])];
			}
		return sum;
	}
};

int main()
{
	vector<int>nums1 = { -1,-1 };
	vector<int>nums2 = { -1,1 };
	vector<int>nums3 = {-1,1 };
	vector<int>nums4 = { 1,-1 };
	Solution*s = new Solution;
	cout << s->fourSumCount(nums1, nums2, nums3, nums4);
	return 0;
}