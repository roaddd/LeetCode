#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//版本一
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int>::iterator i = prices.begin();//头指针
		vector<int>::iterator j = prices.begin();//尾指针
		int sum=0;
		vector<int>::iterator ht = j;//记录尾指针的前一个位置
		j++;
		while (j != prices.end())
		{
			if (*i >= *j)//当头指针大于等于尾指针的时候，头尾指针都前进
			{
				ht = j;
				i = j;
				j++;
			}
			else if (*ht<=*j)//如果尾指针前一位置的值小则加和
			{
				sum = sum + *j - *ht;
				ht = j;
				j++;

			}
			else if (*ht > *j)//如果尾指针前一位置的值大则将头指针置为尾指针的位置，尾指针前进
			{
				i =ht;
				i++;
				ht = j;
				j++;
			}
		}
		return sum;
	}
};

//动态规划
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int dp0 = 0;//当天交易完后手里没有股票的利润
		int dp1 = -prices[0];//当天交易完后手里有股票的利润
		int len = prices.size();
		for (int i = 0; i < len; i++)
		{
			dp0 = max(dp0, dp1 + prices[i]);//1、之前卖出 2、今天卖出
			dp1 = max(dp1, dp0 - prices[i]);//1、之前买入 2、今天买入
		}
		return dp0;//利润最大肯定是最后手里没有股票的时候
	}
};

//贪心算法
class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int sum = 0;
		for (int i = 1; i < len; i++)
		{
			if (prices[i - 1] <= prices[i])
				sum += prices[i] - prices[i - 1];
		}
		return sum;
	}
};

int main()
{
	//Solution* s = new Solution();
	//Solution2* s = new Solution2();
	Solution3* s = new Solution3();
	vector<int> prices = {5,2,3,2,6,6,2,9,1,0,7,4,5,0};
	cout << s->maxProfit(prices);
	return 0;
}