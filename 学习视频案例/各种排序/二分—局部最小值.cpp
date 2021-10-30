#include <iostream>
#include <vector>
using namespace std;

/* 二分查找应用到求局部最小值的位置问题,该数组是无序的 */
//数组无序，相邻元素不相等，找到局部最小值的位置
class Solution {
public:
	int getLessIndex(vector<int>&nums)
	{
		if (nums.size() == 0)
			return -1;//不存在
		if (nums.size() == 1 || nums[0] < nums[1])
			return 0;
		if (nums[nums.size() - 1] < nums[nums.size() - 2])
			return nums.size() - 1;
		int left = 1;
		int right = nums.size() - 2;
		while (left < right)
		{
			int mid = left + ((right - left) >> 1);
			if (nums[mid] > nums[mid - 1])
				right = mid - 1;
			else if (nums[mid] > nums[mid + 1])
				left = mid + 1;
			else
				return mid;
		}
		return left;
	}
};

int main()
{
	vector<int>test = { 6,5,7,3,5,8,9 };
	Solution*s = new Solution;
	cout << s->getLessIndex(test);
	return 0;
}