#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


//两个集合
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int>uset1;
		unordered_set<int>uset2;
		vector<int>nums3;
		for (vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++)uset1.insert(*iter);
		for (vector<int>::iterator iter = nums2.begin(); iter != nums2.end(); iter++)uset2.insert(*iter);
		unordered_set<int>::iterator t1 = uset1.begin();
		while (t1 != uset1.end())
		{
			if (uset2.count(*t1) != 0)
				nums3.push_back(*t1);
			t1++;
		}
		return nums3;
	}
};

//排序+双指针
class Solution2 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int>::iterator t1 = nums1.begin();
		vector<int>::iterator t2 = nums2.begin();
		vector<int>nums3;
		while (t1 != nums1.end() && t2 != nums2.end())
		{
			if (*t1 == *t2)
			{//保证加入元素的唯一性
				if (!nums3.size() || *t1 != nums3.back())
				{
					nums3.push_back(*t1);
				}
				t1++;
				t2++;
			}
			else if (*t1 < *t2)
				t1++;
			else t2++;
		}
		return nums3;
	}
};

int main()
{
	Solution2* s = new Solution2();
	vector<int>vec1{ 1,2,2,1 };
	vector<int>vec2{ 2,2 };
	vector<int>vec3 = s->intersection(vec1, vec2);
	for (int elm : vec3)
		cout << elm << " ";
	return 0;
}