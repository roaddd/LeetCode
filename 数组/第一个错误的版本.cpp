#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;
		while (left < right)
		{
			//int mid = (left + right) / 2;会溢出导致mid为负数
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
	
};