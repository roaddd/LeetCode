#include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
		{
			ans += n & 1;
			n >>= 1;
		}
		return ans;
	}
};

//循环检查二进制位
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n&(1 << i))
				ans++;
		}
		return ans;
	}
};

//位运算优化
/* n&(n-1)：运算结果恰好为把二进制中的最低位1变为0之后的结果。
	时间复杂度：log(n)*/
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
		{
			n &= n - 1;
			ans++;
		}
		return ans;
	}
};