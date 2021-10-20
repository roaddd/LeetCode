#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		int q = 0, p = 0,r=1;
		for (int i = 2; i <= n; i++)
		{
			q = p;
			p = r;
			r = q + p;
		}
		return r;
	}
};
