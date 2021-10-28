#include <iostream>
using namespace std;

//逐位颠倒
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t rev = 0;
		int i = 0;
		while (n)
		{
			rev |= ((n & 1) << (31 - i));
			i++;
			n >>= 1;
		}
		return rev;
	}
};

//位运算分治
class Solution {
private:
	const uint32_t M1 = 0x55555555;
	const uint32_t M2 = 0x33333333;
	const uint32_t M3 = 0x0f0f0f0f;
	const uint32_t M4 = 0x00ff00ff;
	const uint32_t M5 = 0x0000ffff;
public:
	uint32_t reverseBits(uint32_t n) {
		n = ((n >> 1)&M1) | ((n&M1) << 1);
		n = ((n >> 2)&M2) | ((n&M2) << 2);
		n = ((n >> 4)&M3) | ((n&M3) << 4);
		n = ((n >> 8)&M4) | ((n&M4) << 8);
		n = ((n >> 16)&M5) | ((n&M5) << 16);
		return n;
	}
};