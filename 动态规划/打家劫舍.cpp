#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
class Solution {
public:
	int rob(vector<int>& nums) {
		int dp1 = nums[0], dp0 = 0;//dp1表示这一家被偷了，dp0表示这一家没被偷
		for (int i = 1; i < nums.size(); i++)//从第二家开始
		{
			int tmp = max(dp1, dp0);
			dp1 = dp0 + nums[i];
			dp0 = tmp;
		}
		return max(dp0, dp1);
	}
};

int main()
{

	return 0;
}