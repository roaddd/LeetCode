#include <iostream>
#include <vector>
#include <string>
using namespace std;

//纵向比较
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1)return strs[0];

		int i = 0;
		string s;
		
		int cur = 0;
		auto iter = strs.begin();
		while (cur < (*iter).size() && cur < (*(iter + 1)).size())
			if ((*iter)[cur] == (*(iter + 1))[cur])
			{
				s.push_back((*iter)[cur]);
				cur++;
			}
			else
				break;
		int ret = cur;

		if (strs.size() > 2)
		{
			for (auto iter = strs.begin() + 2; iter != strs.end(); iter++)
			{
				cur = 0;
				while (cur < (*iter).size())
					if ((*iter)[cur] != s[cur])
						break;
					else
						cur++;
				if (cur < ret)
					ret = cur;
			}
		}
		
		return s.substr(0, ret);
	}
};

//分治
class Solution2 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())return "";
		else
			return longestCommonPrefix(strs, 0, strs.size() - 1);
	}

	string longestCommonPrefix(vector<string>&strs, int start, int end)
	{
		if (start == end)return strs[start];
		int mid = (start + end) / 2;
		string lcpleft = longestCommonPrefix(strs, start, mid);
		string lcpright = longestCommonPrefix(strs, mid + 1, end);
		return commonPrefix(lcpleft, lcpright);
	}

	string commonPrefix(string s1, string s2)
	{
		if (s1.size() == 0 || s2.size() == 0)return "";
		int t1 = 0;
		int t2 = 0;
		while (t1 < s1.size() && t2 < s2.size())
		{
			if (s1[t1] != s2[t2])
				break;
			t1++;
			t2++;
		}
		return s1.substr(0, t1);
	}
};

int main()
{
	vector<string>strs = {"flower","flow","flight"};
	Solution2*s = new Solution2;
	cout << s->longestCommonPrefix(strs);
	//cout<<strs[0].substr(0, 3);
	return 0;
}