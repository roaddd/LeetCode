#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//动态规划
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//利用滚动数组
		int pre = 0,maxAns=nums[0];//pre表示终点在i的子序列的最佳子序和
		for (int i = 0; i < nums.size(); i++)
		{
			//pre = max(pre, 0) + nums[i];//如果前一最佳子序和小于0直接舍去，会越加越小；大于0则与本位相加,无论正反都会越加越大
			pre = max(pre + nums[i], nums[i]);
			maxAns = max(maxAns, pre);//更新最大值为当前最大值与当前累加值之间的最大值
		}
		return maxAns;
	}
};

int main()
{

	return 0;
}