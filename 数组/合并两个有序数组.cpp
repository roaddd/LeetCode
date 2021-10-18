#include <iostream>
#include <vector>
using namespace std;

//从后往前扫描,逆向双指针
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int cur = nums1.size() - 1;
		while (m > 0 && n > 0)
		{
			if (nums2[n-1] >= nums1[m-1])
			{
				nums1[cur] = nums2[n-1];
				n--;
			}
			else
			{
				swap(nums1[cur], nums1[m - 1]);
				m--;
			}
			cur--;
		}
		while (m == 0&&cur!=-1)
		{
			nums1[cur] = nums2[n-1];
			cur--;
			n--;
		}
	}
};

int main()
{

	return 0;
}