#include <iostream>
#include <vector>
using namespace std;

//Ã¶¾Ù
class Solution {
public:
	bool isPrime(int x)
	{
		for (int i = 2; i*i <= x; i++)
			if (x%i == 0)
				return false;
		return true;
	}

	int countPrimes(int n) {
		int sum = 0;
		int i = 2;
		for (; i < n; i++)
		{
			sum += isPrime(i);
		}
		return sum;
	}
};

//°£ÊÏÉ¸
class Solution {
public:
	int countPrimes(int n) {
		int sum = 0;
		vector<int>isPrime(n, 1);
		for (int i = 2; i < n; i++)
		{
			if (isPrime[i])
			{
				sum++;
				if ((long long)i*i < n)
				{
					for (int j = i * i; j < n; j += i)
						isPrime[j] = 0;
				}
			}
		}
		return sum;
	}
};