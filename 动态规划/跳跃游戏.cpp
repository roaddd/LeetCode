#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cur = nums[0], i = 1;
		for (; cur != 0 && i < nums.size(); i++)
		{
			cur--;
			if (cur < nums[i])
				cur = nums[i];
		}
		return i == nums.size();
	}
};

//Ì°ÐÄ
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int rightmost = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i < rightmost)
			{
				rightmost = max(rightmost, i + nums[i]);
				if (rightmost >= nums.size() - 1)
					return true;
			}
			
		}
		return false;
	}
};