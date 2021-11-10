#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//单调栈
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int>stack;
		int ans = 0;
		stack.push(0);
		for (int i = 1; i < heights.size(); i++)
		{
			while (!stack.empty() && heights[i] < heights[stack.top()])
			{
				int top = stack.top();
				stack.pop();
				if (stack.empty())
				{
					ans = max(ans, heights[top]*i);
					break;
				}
				int left = stack.top();
				ans = max(ans, heights[top] * (i - left - 1));
			}
			stack.push(i);
		}
		//处理栈中剩余元素，剩余元素肯定是递增
		while (!stack.empty())
		{
			int curHeight = heights[stack.top()];
			stack.pop();
			while (!stack.empty() && curHeight == heights[stack.top()])
				stack.pop();
			int curWidth;
			if (stack.empty())
				curWidth = heights.size();
			else
				curWidth = heights.size() - stack.top() - 1;//注意理解此公式
			ans = max(ans, curHeight*curWidth);
		}
		return ans;
	}
};

//单调栈加哨兵
class Solution2 {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int>stack;
		int ans = 0;
		//加两个哨兵
		/* 第一个哨兵比原数组中的任一个元素都小，所以它不会出栈；第二个哨兵是保证原数组所有元素都能够出栈。 */
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		stack.push(0);
		for (int i = 1; i < heights.size(); i++)
		{
			while (!stack.empty()&&heights[i]<heights[stack.top()])
			{
				int top = stack.top();
				stack.pop();
				ans = max(ans, heights[top] * (i - stack.top()-1));
			}
			stack.push(i);
		}
		return ans;
	}
};

int main()
{
	vector<int>test{ 5,5,1,7,1,1,5,2,7,6 };
	Solution*s = new Solution;
	cout << s->largestRectangleArea(test);
	return 0;
}