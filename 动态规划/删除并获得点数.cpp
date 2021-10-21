#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int rob(vector<int>&nums)
	{
		if (nums.size() == 1)
			return nums[0];
		int dp0 = 0, dp1 = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = max(dp1, dp0);
			dp1 = dp0 + nums[i];
			dp0 = tmp;
		}
		return max(dp1, dp0);
	}
	//转化为打家劫舍问题
	int deleteAndEarn(vector<int>& nums) {
		int maxVal = 0;
		for (auto elm : nums)
			maxVal = max(elm, maxVal);
		vector<int>sum(maxVal + 1);
		for (auto elm : nums)
			sum[elm] += elm;
		return rob(sum);
	}
};