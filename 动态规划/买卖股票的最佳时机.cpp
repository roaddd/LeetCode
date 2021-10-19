#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int q=0,p=-prices[0];//q为不持有股票的利润，p为持有股票的利润
		for (int i = 1; i < prices.size(); i++)
		{
			q = max(p+prices[i],q);
			p = max(p, -prices[i]);
		}
		return q;
	}
};

int main()
{

	return 0;
}