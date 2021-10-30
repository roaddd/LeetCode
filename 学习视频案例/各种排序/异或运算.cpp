#include <iostream>
#include <vector>
using namespace std;

/* 一个数组中有两个数字出现了奇数次，找出这两个数字 */
class Solution {
public :
	vector<int> oddNumber(vector<int>&nums)
	{
		int eor = 0;
		
		for (int i = 0; i < nums.size(); i++)
			eor ^= nums[i];

		//取出eor中最右侧为1的二进制位
		int tmpEor = eor & (~eor + 1);

		//将数组中所有符合该二进制位为1的数异或，得到奇数次数字的其中一个
		int a = 0;
		for (int i = 0; i < nums.size(); i++)
			if(nums[i]&tmpEor==1)
				a ^= nums[i];

		//然后将a与eor异或得到奇数次数字的另一个
		int b = eor ^ a;

		return { a,b };
	}
};

int main()
{
	vector<int>test = { 0,0,3,4,6,5,5,6 };
	Solution*s = new Solution;
	vector<int>ans = s->oddNumber(test);
	for (auto &elm : ans)
		cout << elm << " ";
	return 0;
}