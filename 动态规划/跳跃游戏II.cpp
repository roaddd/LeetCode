#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//贪心
class Solution {
public:
	int jump(vector<int>& nums) {
		int rightmost = 0;//可到达的最远位置
		int cur = 0;//目前所在位置
		int sum = 0;//步数
		while (rightmost < nums.size() - 1)
		{
			int tmpMax=0;
			int i = cur;
			while (i <= rightmost)
			{
				if (i + nums[i] > tmpMax)
				{
					tmpMax = i + nums[i];
					cur = i;
				}
				i++;
			}
			rightmost = tmpMax;
			sum++;//步数加一
		}
		return sum;
	}
};

class Solution {
public:
	int jump(vector<int>& nums) {
		int rightmost = 0;
		int step = 0;
		int end = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			rightmost = max(rightmost, i + nums[i]);
			if (i == end)
			{
				end = rightmost;
				step++;
			}
		}
		return step;
	}
};

