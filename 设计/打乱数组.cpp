#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	Solution(vector<int>& nums) :shuffled(nums.begin(), nums.end()), origin(nums.begin(), nums.end()) {

	}

	vector<int> reset() {
		return origin;
	}

	vector<int> shuffle() {
		int num;
		for (int i = 0; i < shuffled.size(); i++)
		{
			num = i + rand() % (shuffled.size() - i);
			swap(shuffled[i], shuffled[num]);
		}
		return shuffled;
	}
private:
	vector<int>origin;
	vector<int>shuffled;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */