#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class QuickSort {
public:
	vector<int>	partition(vector<int>&nums, int l, int r)
	{
		int less = l;
		int more = r+1;
		int tmp = nums[l];
		int left = l;
		while (l < more)
		{
			if (nums[l] < tmp)
				swap(nums[++less], nums[l++]);
			else if (nums[l] > tmp)
				swap(nums[--more], nums[l]);//右边交换过来的值还没有看过，所以此时l不自增
			else
				l++;
		}
		swap(nums[left], nums[less]);
		return { less,more - 1 };
	}

	void quickSort(vector<int>&nums, int l, int r)
	{
		if (l < r)
		{
			//随机快速排序
			swap(nums[l], nums[l + rand() % (r - l + 1)]);
			vector<int>p = partition(nums, l, r);
			quickSort(nums, l, p[0] - 1);
			quickSort(nums, p[1] + 1, r);
		}
	}

	void quickSort(vector<int>&nums)
	{
		if (nums.size() < 2)
			return;
		quickSort(nums, 0, nums.size() - 1);
	}

};

int main()
{
	vector<int>test = { 3,5,6,2,4,8 };
	QuickSort*qs = new QuickSort;
	qs->quickSort(test);
	for (auto &elm : test)
		cout << elm << " ";
	cout << "\n";
	return 0;
}