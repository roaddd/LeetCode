#include <iostream>
#include <string>
using namespace std;

//有符号的32位整数
class Solution {
public:
	int reverse(int x) {
		int ans = 0;
		while (x)
		{
			if (ans > INT32_MAX / 10 || ans < INT32_MIN)return 0;
			ans = ans * 10 + x % 10;
			x = x / 10;
		}
		return ans;
	}
};

int main()
{
	int x = 1534236469;
	Solution*s = new Solution;
	cout << s->reverse(x);
	return 0;
}