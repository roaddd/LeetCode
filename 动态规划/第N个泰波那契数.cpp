#include <iostream>

using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		int q = 0, p = 0, k = 1, r = 1;
		for (int i = 3; i <= n; i++)
		{
			q = p;
			p = k;
			k = r;
			r = q + p + k;
		}
		return r;
	}
};