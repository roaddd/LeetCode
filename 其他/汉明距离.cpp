#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		//异或：同为0，异为1
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			ans += (x & 1) ^ (y & 1);
			x >>= 1;
			y >>= 1;
		}
		return ans;
	}
};

class Solution {
public:
	int hammingDistance(int x, int y) {
		//异或：同为0，异为1
		int ans = 0;
		int tmp = x ^ y;
		while (tmp)
		{
			tmp &= tmp - 1;
			ans++;
		}
		return ans;
	}
};