#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
		已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
	并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。
*/
class Solution {
public:
	void sortedArrDistanceLessK(vector<int>&nums,int k)
	{
		//小根堆
		priority_queue<int, vector<int>, greater<int>>heap;
		int n = nums.size();
		//若n大于k，则把前k个元素放进小根堆
		int i = 0;
		for (; i < min(n, k+1); i++)
			heap.push(nums[i]);
		//堆顶元素必定对应是排好序之后的元素
		int j = 0;
		for (; i<n; j++,i++)
		{
			nums[j] = heap.top();
			heap.pop();
			heap.push(nums[i]);
		}
		//把堆中剩余的元素覆盖掉原数组
		while (!heap.empty())
		{
			nums[j++] = heap.top();
			heap.pop();
		}
	}
};

//重写小根堆
class SmallHeap {
public:
	/* 删除并返回堆顶元素 */
	int top(vector<int>&current)
	{
		int ret = *current.begin();
		current.erase(current.begin());
		return ret;
	}
	/* 堆里放入新元素 */
	void push(vector<int>&current,int newnum)
	{
		current.push_back(newnum);
		heapify(current, 0, current.size() - 1);
	}
	/* 从下向上调整 */
	void heapify(vector<int>&nums, int index, int size)
	{
		int left = index * 2 + 1;
		while (left <= size)
		{
			int minest = left + 1 <= size && nums[left] > nums[left + 1] ? left + 1 : left;
			minest = nums[index] > nums[minest] ? minest : index;
			if (minest == index)
				break;
			swap(nums[index], nums[minest]);
			index = minest;
			left = index * 2 + 1;
		}
	}
	/* 向堆中放入新元素并且向上调整 */
	void heapInsert(vector<int>&nums,int number,int index)
	{
		nums.push_back(number);
		while (nums[index] < nums[(index - 1) / 2])
		{
			swap(nums[index], nums[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}

	void sortedArrDistanceLessK(vector<int>&origin, int k)
	{
		int n = origin.size();
		int m = min(n, k);
		//建造前k+1个元素的小根堆
		vector<int>current;
		for (int i = 0; i <=m; i++)
			heapInsert(current, origin[i],i);
		//下面流程与上面方法一样
		int i = k+1,j=0;
		for (; i < n; i++, j++)
		{
			origin[j] = top(current);
			push(current, origin[i]);
		}
		while (!current.empty())
			origin[j++] = top(current);
	}
};

int main()
{
	vector<int>test = { 3,2,1,5,4 };
	Solution*s = new Solution;
	s->sortedArrDistanceLessK(test,2);
	for (auto &elm : test)
		cout << elm << " ";

	cout << "\n";

	SmallHeap*sh = new SmallHeap;
	sh->sortedArrDistanceLessK(test, 2);
	for (auto &elm : test)
		cout << elm << " ";

	return 0;
}