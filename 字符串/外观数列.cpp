#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s="1";
		s = strToList(n, s);
		return s;
	}

	string strToList(int n, string s)
	{
		if (n == 1)return s;
		int fast = 0;
		int slow = 0;
		string ret="";
		while (fast < s.size() && slow < s.size())
		{
			while (s[fast] == s[slow] && fast < s.size())
				fast++;
			ret = ret + to_string(fast - slow) + s[slow];
			slow = fast;
		}
		return strToList(n - 1, ret);
	}
};

class Solution2 {
public:
	string countAndSay(int n) {
		if (n == 1)return "1";
		string pre=countAndSay(n - 1), ans;
		int count = 1;
		for (int i = 0; i < pre.size(); i++)
		{
			if (pre[i] != pre[i + 1])
			{
				ans += to_string(count);
				ans += pre[i];
				count = 0;
			}
			count++;
		}
		return ans;
	}
};

int main()
{
	Solution2*s = new Solution2;
	cout << s->countAndSay(4);
	return 0;
}