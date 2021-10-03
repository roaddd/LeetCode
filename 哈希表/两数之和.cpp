#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>umap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (umap.find(target - nums[i]) != umap.end())
				return { i,umap[target - nums[i]] };
			umap[nums[i]] = i;
		}
		return { -1,-1 };
	}
};

int main()
{
	Solution*s = new Solution;
	vector<int>vec = { 3,3 };
	vector<int>vec1 = s->twoSum(vec,6);
	for (auto elm : vec1)
		cout << elm << " ";
	return 0;
}