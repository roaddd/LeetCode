#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <array>
using namespace std;

//我是个白痴
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1)return s.length();
		unordered_set<char>uset;
		int ans=0;
		int len = s.size();
		int rk = 0;//右指针
		for (int i=0;i<len; i++)//左指针枚举每个元素
		{
			if (i != 0)uset.erase(s[i - 1]);//左指针每前进一个，删除掉前一个元素
			while (rk < len && (uset.count(s[rk])) == 0)
			{
				uset.insert(s[rk]);
				rk++;
			}
			ans = ans > (rk - i) ? ans : (rk - i);
		}
		return ans;
	}
};


int main()
{
	Solution*S = new Solution;
	string s = "anviaj";
	cout << S->lengthOfLongestSubstring(s);
	return 0;
}