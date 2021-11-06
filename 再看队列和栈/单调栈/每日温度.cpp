#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//暴力解法
/*
	next：存放温度值第一次出现的下标，初始化为最大值
*/
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int size = temperatures.size();
		vector<int>next(101, INT_MAX),ans(size);
		//从后往前遍历
		for (int i = size-1; i>=0; i--)
		{
			int wamerIndex = INT_MAX;
			for (int j = temperatures[i] + 1; j < 101; j++)
				wamerIndex = min(wamerIndex, next[j]);
			if (wamerIndex != INT_MAX)
				ans[i] = wamerIndex - i;
			next[temperatures[i]] = i;
		}
		return ans;
	}
};

//单调栈
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<int>index;//用来存放温度的下标
		int size = temperatures.size();
		vector<int>ans(size);
		for (int i = 0; i < size; i++)
		{
			while (!index.empty() && temperatures[i] > temperatures[index.top()])
			{
				ans[index.top()] = i - index.top();
				index.pop();
			}
			index.push(i);
		}
		return ans;
	}
};