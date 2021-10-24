#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int fmax = nums[0], fmin = nums[0], maxSum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int mx = fmax, mi = fmin;
			fmax = max(mx*nums[i], max(mi*nums[i], nums[i]));
			fmin = min(mx*nums[i], min(mi*nums[i], nums[i]));
			maxSum = max(maxSum, fmax);
		}
		return maxSum;
	}
};