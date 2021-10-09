#include <iostream>
#include <vector>
using namespace std;

//双指针
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() <= 1)return;
		auto fast = nums.begin();
		auto slow = nums.begin();

		while (fast != nums.end())
		{
			fast++;
			while (fast != nums.end() && *fast == 0)fast++;//找到下一个不为0的位置
			while (slow < fast&&*slow != 0)slow++;
			if(fast!=nums.end()&&slow<fast)
				swap(*fast, *slow);
		}
	}
};

//双指针
class Solution2 {
public:
	void moveZeroes(vector<int>& nums) {
		int left = 0;//指向已排好序列的末尾
		int right = 0;//指向待处理序列的头部
		while (right < nums.size())
		{
			if (nums[right])
			{
				if (left < right)
				{
					//swap(nums[right], nums[left + 1]);
					nums[left] = nums[right];
					nums[right] = 0;
					
				}
				left++;
			}
			right++;
		}
	}
};



int main()
{
	Solution2*s = new Solution2;
	vector<int>vec{1 ,2,3,0,4,5};
	s->moveZeroes(vec);
	for (auto elm : vec)
		cout << elm << " ";
	return 0;
}