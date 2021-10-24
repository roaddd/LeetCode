#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int pre = nums[0],maxSum=nums[0],minSum=0,sum=nums[0];
		//不发生越界的情况
		for (int i = 1; i < nums.size(); i++)
		{
			sum += nums[i];
			pre = max(pre, 0) + nums[i];
			maxSum = max(pre, maxSum);
		}
		//发生越界的情况，必定包含nums[0]与nums[n-1],数组两边的数据最大，中间的数据和最小，求出中间最小的和即可。
		pre = nums[0];
		for (int i = 1; i < nums.size() - 1; i++)
		{
			pre = min(pre, 0) + nums[i];
			minSum = min(pre, minSum);
		}
		return max(sum - minSum, maxSum);
	}
};

//邻接数组
class Solution2 {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int pre = nums[0],ans=nums[0];
		//没有越界
		for (int i = 1; i < n; i++)
		{
			pre = max(pre, 0) + nums[i];
			ans = max(ans, pre);
		}
		//处理越界
		// rightsums[i] = A[i] + A[i+1] + ... + A[N-1]
		vector<int>rightsums(n);
		rightsums[n - 1] = nums[n - 1];
		for (int i = n - 2; i > 1; i--)
			rightsums[i] = rightsums[i + 1] + nums[i];
		//maxright[i] = max_{j >= i} rightsums[j]
		vector<int>maxright(n);
		maxright[n - 1] = rightsums[n - 1];
		for (int i = n - 2; i > 1; i--)
			maxright[i] = max(maxright[i + 1], rightsums[i]);

		//将左边部分数组的和与右边部分数组的最大值相加
		int leftsum = 0;
		for (int i = 0; i < n - 2; i++)
		{
			leftsum += nums[i];
			ans = max(ans, leftsum + maxright[i + 2]);
		}
		return ans;
	}
};

int main()
{
	vector<int>vec = { 1,-2,3,-2 };
	Solution2*s = new Solution2;
	cout << s->maxSubarraySumCircular(vec);
	return 0;
}