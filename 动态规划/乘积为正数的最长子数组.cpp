#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int positive = nums[0] > 0 ? 1 : 0;//以第i个元素为结尾的数组的乘积为正的最大个数
		int negative = nums[0] < 0 ? 1 : 0;//以第i个元素为结尾的数组的乘积为负的最大个数
		int maxNum = positive;
		for (int i = 1; i < nums.size(); i++)
		{
			//元素为正，不改变乘积的符号
			if (nums[i] > 0)
			{
				positive = positive + 1;
				negative = negative > 0 ? (negative + 1) : 0;//当乘积为负的个数为0时，正数并不会增加此个数
			}
			else if (nums[i] < 0)
			{
				int tmpPositive = positive;
				int tmpNegative = negative;//将数据用临时变量进行计算，以免改变原数据
				positive = tmpNegative > 0 ? (tmpNegative + 1) : 0;
				negative = tmpPositive + 1;
			}
			else//当元素为0时，直接截断
			{
				positive = 0;
				negative = 0;
			}
			maxNum = max(maxNum, positive);
		}
		return maxNum;
	}
};