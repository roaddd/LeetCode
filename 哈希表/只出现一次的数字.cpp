#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//¹şÏ£¼¯
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int>uset;
		for (auto elm : nums)
		{
			if (uset.count(elm) != 0)
				uset.erase(elm);
			else
			{
				uset.insert(elm);
			}
			
		}
		return *uset.begin();
	}
};

//Î»ÔËËã
class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			ret ^= *iter;
		}
		return ret;
	}
};


int main()
{
	Solution2*s = new Solution2();
	vector<int>nums = { 2,2,1 };
	cout<<s->singleNumber(nums);
	return 0;
}