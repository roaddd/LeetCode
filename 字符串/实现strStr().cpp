#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)return 0;
		int j = 0,i=0;
		int next[10000];
		getNext(next, needle);
		//bool a ;
		//bool b ;
		int len = needle.size();
		while(i<haystack.size()&&j<len)
		{
			if (j==-1||haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
				j = next[j];
		}
		if (j == needle.size())return i - needle.size();
		else
			return -1;
	}

	void getNext(int next[],string s)
	{
		next[0] = -1;
		int j = 0;
		int k = -1;
		while (j < s.size() - 1)
		{
			if (k == -1 || s[j] == s[k])
				next[++j] = ++k;
			else
				k = next[k];
		}
	}
};

int main()
{
	string haystack = "hello";
	string needle = "ll";
	Solution*s = new Solution;
	cout << s->strStr(haystack, needle);
	return 0;
}