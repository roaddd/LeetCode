#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 此类题注意题目是否允许多次买卖 */
//动态规划
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int dp0 = 0, dp1 = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			dp0 = max(dp0, dp1 + prices[i] - fee);
			dp1 = max(dp1, dp0 - prices[i]);
		}
		return max(dp0, dp1);//因为含有手续费，所以最后利润最大时不一定是手里的股票卖出
	}
};