#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);

		int dp0 = 0, dp1 = 0,sum1=0,sum0=0;
		//第一个房间偷
		for (int i = 2; i < nums.size(); i++)
		{
			int tmp = dp0;
			dp0 = max(dp0, dp1);
			dp1 = tmp + nums[i];
		}
		sum1 = dp0 + nums[0];

		dp0 = 0, dp1 = 0;
		//第一个房间不偷
		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = dp0;
			dp0 = max(dp0, dp1 );
			dp1 = tmp + nums[i];
		}
		sum0 = max(dp0, dp1);

		return max(sum1, sum0);
	}
};