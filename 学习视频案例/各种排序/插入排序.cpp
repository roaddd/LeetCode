#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void insertionSort(vector<int>&nums)
	{
		for (int i = 1; i < nums.size(); i++)
			for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--)
				swap(nums[j], nums[j + 1]);
	}
};

int main()
{
	vector<int>test = { 5,6,7,3,4,5,8,9 };
	Solution*s = new Solution;
	s->insertionSort(test);
	for (auto &elm : test)
		cout << elm << " ";
	return 0;
}