#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/* 
		给定一个数组arr，和一个数num，请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
	要求额外空间复杂度O(1)，时间复杂度O(N)
	*/
	vector<int> partition(vector<int>&arr, int l, int r, int p)
	{
		int less = l - 1;
		int more = r + 1;
		while (l < more)
		{
			if (arr[l] < p)
				swap(arr[l++], arr[++less]);
			else if (arr[l] > p)
				swap(arr[l++], arr[--more]);
			else
				l++;
		}
		return { less + 1,more - 1 };
	}

	void problem1(vector<int>&arr,int num)
	{
		partition(arr, 0,arr.size()-1,num);
	}
	/*
		给定一个数组arr，和一个数num，请把小于num的数放在数组的左边，等于num的数放在数组的中间，大于num的数放在数组的右边。
	要求额外空间复杂度O(1)，时间复杂度 O(N)
	*/
	void netherlandsFlag(vector<int>&arr,int num)
	{
		partition(arr, 0,arr.size()-1,num);
	}
};

int main()
{
	vector<int>test = { 3,5,6,2,4,8 };
	Solution*s = new Solution;
	s->problem1(test, 5);
	for (auto &elm : test)
		cout << elm << " ";
	cout << "\n";

	return 0;
}