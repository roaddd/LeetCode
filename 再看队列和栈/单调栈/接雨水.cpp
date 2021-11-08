#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//每个点都进行一趟遍历,时间复杂度较高
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = 0;
		int len = height.size();
		int sum = 0;
		//遍历第二个到倒数第二个
		for (int i = 1; i < len - 1; i++)
		{
			left =i-1;
			right = i + 1;
			int leftMax = INT_MIN;
			int rightMax = INT_MIN;
			//遍历该点的左边
			while (left >= 0)
			{
				leftMax = max(height[left], leftMax);
				left--;
			}
			//遍历该点的右边
			while (right <= len - 1)
			{
				rightMax = max(height[right], rightMax);
				right++;
			}
			if (leftMax >= height[i] && rightMax >= height[i] && (leftMax != 0 || rightMax != 0))
			{
				sum += min(leftMax, rightMax) - height[i];
			}
		}
		return sum;
	}
};

//动态规划对leftMax和rightMax进行优化
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		vector<int>leftMax(len);
		vector<int>rightMax(len);
		leftMax[0] = height[0];
		rightMax[len - 1] = height[len - 1];
		int sum = 0;
		for (int i = 1; i < len - 1; i++)
			leftMax[i]=max(leftMax[i - 1], height[i]);	
		for (int i = len-2; i >=0; i--)
			rightMax[i] = max(rightMax[i + 1], height[i]);
		for (int i = 1; i < len - 1; i++)
			sum += min(leftMax[i], rightMax[i]) - height[i];
		return sum;
	}
};

//单调栈
class Solution {
public:
	int trap(vector<int>& height) {
		
	}
};

//双指针
class Solution {
public:
	int trap(vector<int>& height) {

	}
};

int main()
{

	return 0;
}