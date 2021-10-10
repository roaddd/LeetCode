#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int>umap;
		for (char c : s)
			umap[c]++;
		for (int i = 0; i < t.size(); i++)
		{
			if (umap.count(t[i]) == 0)return false;
			umap[t[i]]--;
		}
		for (auto c : umap)
		{
			if (c.second != 0)return false;
		}
		return true;
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	Solution*S = new Solution;
	cout << S->isAnagram(s, t);
	return 0;
}