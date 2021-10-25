#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//使用辅助栈
class MinStack {
public:
	MinStack() {
		xstack.push(INT_MAX);
	}

	void push(int val) {
		minstack.push(val);
		xstack.push(min(val, xstack.top()));
	}

	void pop() {
		minstack.pop();
		xstack.pop();
	}

	int top() {
		return minstack.top();
	}

	int getMin() {
		return xstack.top();
	}
private:
	stack<int>minstack;
	stack<int>xstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//不使用辅助栈,存在溢出问题,将compare声明为long类型解决整形越界问题
class MinStack {
public:
	MinStack() {

	}

	void push(int val) {
		if (minstack.empty())
		{
			topmin = val;
			minstack.push(0);
		}
		else
		{
			long long compare = val - topmin;
			minstack.push(compare);
			topmin = compare > 0 ? topmin : val;
		}

	}

	void pop() {
		long long top = minstack.top();
		//如果top小于0，则更新topmin
		topmin = top < 0 ? (topmin - top) : topmin;
		minstack.pop();
	}

	int top() {
		if (minstack.top() <= 0)
			return topmin;
		else
		{
			return minstack.top() + topmin;//转换为原值
		}
	}

	int getMin() {
		return topmin;
	}
private:
	stack<long long>minstack;
	long long topmin;
};