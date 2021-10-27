#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int>umap = { {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900} };
		int ans = 0;
		int flag = 0;
		for (int i = 0; i < s.size() - 1; i++)
		{
			string tmps(1, s[i]);
			string tmps1(1, s[i+1]);
			if (umap.count(tmps+tmps1))
			{
				if (i == s.size() - 2)
					flag = 1;
				ans += umap[tmps + tmps1];
				i = i + 1;
			}
			else if (umap.count(tmps))
			{
				ans += umap[tmps];
			}
		}
		if (flag == 0)
		{
			string tmps2(1, s[s.size() - 1]);
			ans += umap[tmps2];
		}
		
		return ans;
	}
};

class Solution {
	unordered_map<char, int>umap = {
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000}
	};
public:
	int romanToInt(string s) {
		int ans = 0;
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (i < n - 1 && umap[s[i]] < umap[s[i + 1]])
				ans -= umap[s[i]];
			else
				ans += umap[s[i]];
		}
		return ans;
	}
};

int main()
{
	Solution*s = new Solution;
	string S = "XXVII";
	cout << s->romanToInt(S);
	return 0;
}