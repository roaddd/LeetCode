#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() == 1)
			return cost[0];
		if (cost.size() == 2)
			return cost[0] > cost[1] ? cost[1] : cost[0];
		/* 因为题目描述为： 每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
		当支付了脚下台阶的体力后可以继续往上。所以r表示爬到某个台阶时已经花费了的体力*/
		int q = 0, p = 0, r = 0;//q表示爬到前前一个台阶花费最少的体力，p表示爬到前一台阶花费最少的体力
		for (int i = 2; i <= cost.size(); i++)
		{
			q = p;
			p = r;
			r = min(q + cost[i - 2], p + cost[i - 1]);
		}
		return r;
	}
};
