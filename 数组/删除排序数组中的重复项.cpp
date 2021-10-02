#include <iostream>
#include <vector>
using namespace std;

//暴力解法
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() == 0)return 0;

		vector<int>::iterator t1 = nums.begin();
		vector<int>::iterator t2 = nums.begin();

		int t=*t2;//保存t2指针的前一个值
		t2++;

		while(t2 != nums.end())
		{
			if (*t2 !=t)//如果t2指针与前一个值不相等
			{
				t1++;
				*t1 = *t2;
			}
			t = *t2;
			t2++;
		}
		return t1 - nums.begin() + 1;
	}
};


int main()
{
	Solution* s = new Solution();
	vector<int>nums = { 1,1,2 };
	int len = s->removeDuplicates(nums);
	int i = 0;
	for (i; i < len; i++)
		cout << nums[i] << " ";
	return 0;
}
