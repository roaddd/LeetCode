#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <array>
#include <deque>
using namespace std;

class Solution {
	//小根堆
public:
	
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>umap;
		vector<int>ret;
		for (int i = 0; i < nums.size(); i++)
			umap[nums[i]]++;
		priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(&cmp)>q(cmp);
		for (auto iter=umap.begin();iter!=umap.end();iter++)
		{
			if (q.size() == k)
			{
				if (q.top().second < iter->second)
				{
					q.pop();
					q.emplace(iter->first, iter->second);
				}
			}
			else {
				q.emplace(iter->first, iter->second);
			}
		}
		while (!q.empty()) {
			ret.push_back(q.top().first);
			q.pop();
		}
		
		return ret;
		
	}
private:
	static bool cmp(pair<int, int>&m, pair<int, int>&n)
	{
		return m.second > n.second;
	}
};

//基于快速排序
class Solution2 {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>umap;
		
		for (int i = 0; i < nums.size(); i++)
			umap[nums[i]]++;
		for (auto elm : umap)
			vec.push_back(elm);
		quicksort(0,vec.size()-1,k);
		return ans;
	}
	void quicksort(int left, int right,int k)
	{
		if (left > right)return;
		int i = left,j=right;//设置哨兵
		auto tmp = vec[left];//设置基准值
		while (i < j)
		{
			while (i < j&&vec[j].second <= tmp.second)j--;
			while (i<j&&vec[i].second>=tmp.second)i++;
			if (i < j)
			{
				swap(vec[i], vec[j]);
			}
		}
		//基准值归位
		swap(tmp, vec[i]);
		/*
			如果k比i-left小，则前k大的数在前i-left中，再次将i-left中的值进行快速排序;
			否则，首先将前i个数放入到要返回的vector中，此时，前i大的数已放好，
			再将i后面的值进行快速排序，选出继第i大后的i-left+1大的数字。
		*/
		if (k <= i-left)
			quicksort(left, i - 1, k);
		else {
			for (int m = left; m <= i; m++)
				ans.push_back(vec[m].first);
			if (k > i - left + 1)
				quicksort(i + 1, right,k-(i-left+1));
		}
	}
private:
	vector<pair<int, int>>vec;
	vector<int>ans;
};

int main()
{
	Solution2*s = new Solution2;
	vector<int>num = { 1 };
	vector<int>ans = s->topKFrequent(num,1);
	for (auto elm : ans)
		cout << elm << " ";
	return 0;
}