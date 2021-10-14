#include <iostream>
using namespace std;


class Solution {
public:
	int myAtoi(string s) {
		if (!s.size())return 0;
		//丢弃前导空格
		int i = 0;
		while (s[i] == 32)i++;
		int flag = 1;//正数还是负数
		if (s[i] == '+')
		{
			flag = 1;
			i++;
		}
		else if (s[i] == '-')
		{
			i++;
			flag = 0;
		}
		int ans=0;
		while (isdigit(s[i]))
		{
			if (ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && s[i] - '0' > 7))
				return flag ? INT32_MAX : INT32_MIN;
			ans = ans * 10 + (s[i] - '0');
			i++;
		}
		return flag?ans:-ans;
	}
};

int main()
{
	string s = "-2147483648";
	Solution*S = new Solution;
	cout << S->myAtoi(s);
	return 0;
}