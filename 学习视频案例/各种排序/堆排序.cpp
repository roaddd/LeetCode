#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//向下调整
	void heapify(vector<int>&nums, int index,int size)
	{
		int left = index * 2 + 1;//左孩子
		//需调整的堆的大小
		while (left < size)
		{
			//得到左右孩子中的最大值
			int largest = left + 1 < size&&nums[left] < nums[left + 1] ? left + 1 : left;
			//得到左右孩子以及父节点的最大值
			largest = nums[index]>nums[largest]?index:largest;
			//如果父节点最大，则不再调整
			if (largest == index)
				break;
			//否则交换，继续调整
			swap(nums[index], nums[largest]);
			index = largest;
			left = index * 2 + 1;
		}
		
	}
	//大根堆
	void heapSort(vector<int>&nums)
	{
		int size = nums.size();
		if (size < 2)
			return;
		for (int i =size - 1; i >= 0; i--)
			heapify(nums, i,size);
		swap(nums[0], nums[--size]);
		while (size > 0)
		{
			heapify(nums, 0,size);
			swap(nums[0], nums[--size]);
		}
	}
};

int main()
{
	vector<int>test = { 1,3,4,2,5 };
	Solution*s = new Solution;
	s->heapSort(test);
	for (auto &elm : test)
		cout << elm << " ";
	return 0;
}