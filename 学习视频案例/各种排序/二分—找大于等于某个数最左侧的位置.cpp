#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int bsNearLeft(vector<int>&nums,int value){
		//int ans = INT32_MAX;//比value大的值的最小的索引
		int ans = -1;
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (nums[mid] >= value)
			{
				//if (mid < ans)
					ans = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		return ans;
	}
};

int main()
{
	vector<int>test = { 0,1,2,3,4,5,6,7 };
	Solution*s = new Solution;
	cout << s->bsNearLeft(test,4);
	return 0;
}