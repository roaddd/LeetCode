#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int f1 = -prices[0];//第i天手里持有股票的最大收益
		int f2 = 0;//第i天手里没有股票并且存在冷冻期情况下的最大收益
		int f3 = 0;//第i天手里没有股票并且不存在冷冻期的情况下的最大收益
		for (int i = 0; i < prices.size(); i++)
		{
			int tmpf1 = f1;
			int tmpf2 = f2;
			f1 = max(f1, f3 - prices[i]);
			f2 = tmpf1 + prices[i];
			f3 = max(tmpf2, f3);
		}
		return max(f2, f3);
	}
};