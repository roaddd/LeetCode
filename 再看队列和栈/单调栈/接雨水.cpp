#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//每个点都进行一趟遍历,时间复杂度较高
class Solution4 {
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
class Solution3 {
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
/* 在栈中存储元素的下标，栈中下标对应的元素大小为递减的 */
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int>stack;
		stack.push(0);
		int sum = 0;
		for (int i = 1; i < height.size(); i++)
		{
			//当栈不为空并且新加入的元素大于栈顶元素
			while (!stack.empty() && height[i] > height[stack.top()])
			{
				int top = stack.top();
				stack.pop();
				//如果栈中只有一个元素则跳出此次循环
				if (stack.empty())
					break;
				//如果栈中元素至少两个，则此时一定能存雨水
				int left = stack.top();
				//left始终代表当前元素左边的比它大的元素，总的过程可以理解为一层层的往上叠加雨水
				int width = i - left - 1;
				sum += width * (min(height[left], height[i]) - height[top]);
			}
			stack.push(i);
		}
		return sum;
	}
};

//双指针优化动态规划
/* 该方法用两个指针代替了动态规划方法中leftMax数组和rightMax数组，
因为在动态规划方法中计算雨水量时只用到了leftMax和rightMax中的较小值，因此在一次遍历中可以维护两个变量，
当当前元素的左边最大值小于等于右边最大值时，更新为左边最大值为自身值和左边最大值当中的较大值，同时计算该元素的
接水量；当前元素的右边最大值同理。
*/
class Solution2 {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int left = 0, right = n - 1;
		int leftMax = 0, rightMax = 0;
		int sum = 0;
		while (left < right)
		{
			while (left < right&&height[left] <= height[right])
			{
				leftMax = max(leftMax,height[left]);
				left++;
				sum += (leftMax - height[left]>0? (leftMax - height[left]):0);
			}
			while (left < right&&height[right] <= height[left])
			{
				rightMax = max(rightMax,height[right]);
				right--;
				sum += (rightMax - height[right]>0?(rightMax - height[right]):0);
			}
		}
		return sum;
	}
};

int main()
{
	vector<int>height{0,1,0,2,1,0,1,3,2,1,2,1};
	Solution*s = new Solution;
	cout << s->trap(height);
	return 0;
}