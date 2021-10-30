#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void selectionSort(vector<int>&nums)
	{
		if (nums.size() < 2)
			return;
		for (int i = 0; i < nums.size()-1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < nums.size(); j++)
				minIndex = nums[j] < nums[minIndex] ? j : minIndex;
			swap(nums[i], nums[minIndex]);
		}
	}
};

int main()
{
	vector<int>test = { 5,6,7,3,4,5,8,9 };
	Solution*s = new Solution;
	s->selectionSort(test);
	for (auto &elm : test)
		cout << elm << " ";
	return 0;
}