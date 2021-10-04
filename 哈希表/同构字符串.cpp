#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char>umap;
		unordered_set<char>uset1;
		unordered_set<char>uset2;
		int len = s.length();
		int len2 = t.length();
		for (int i = 0; i < len; i++)
			uset1.insert(s[i]);
		for (int i = 0; i < len2; i++)
			uset2.insert(t[i]);
		if (uset1.size() != uset2.size())return false;
		if (s.length() != t.length())return false;
		
		for (int i = 0; i <len; i++)
		{
			auto iter = umap.find(s[i]);
			if (iter != umap.end() && iter->second != t[i])
				return false;
			umap[s[i]] = t[i];
		}
		return true;
	}
};

class Solution2 {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char>umap1;
		unordered_map<char, char>umap2;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if ((umap1.count(s[i]) && umap1[s[i]] != t[i]) || (umap2.count(t[i]) && umap2[t[i]] != s[i]))
				return false;
			umap1[s[i]] = t[i];
			umap2[t[i]] = s[i];
		}
		return true;
	}
};


int main()
{
	Solution2* S = new Solution2();
	string s = "badc";
	string t = "baba";
	cout<<S->isIsomorphic(s, t);
	return 0;
}