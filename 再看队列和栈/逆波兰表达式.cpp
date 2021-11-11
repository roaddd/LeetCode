#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>stack;
		int ans = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if ((tokens[i][0] >= '0'&&tokens[i][0] <= '9')||(tokens[i][1] >= '0'&&tokens[i][1] <= '9'))
				stack.push(atoi(tokens[i].c_str()));
			else
			{
				int a = stack.top();
				stack.pop();
				int b = stack.top();
				stack.pop();
				if (tokens[i] == "+")
					stack.push(a + b);
				else if (tokens[i] == "-")
					stack.push(b - a);
				else if (tokens[i] == "*")
					stack.push(a*b);
				else
					stack.push(b / a);
			}
		}
		return stack.top();
	}
};

int main()
{
	vector<string>test = { "10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	Solution*s = new Solution;
	cout << s->evalRPN(test);
	return 0;
}