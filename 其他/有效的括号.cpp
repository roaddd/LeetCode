#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
	unordered_map<char, char>umap = {
		{'(',')'},
		{'{','}'},
		{'[',']'}
	};
public:
	bool isValid(string s) {
		int n = s.length();
		if (n % 2 != 0)
			return false;

		stack<char>isTrue;
		for (int i = 0; i < n; i++)
		{
			if (isTrue.empty())
				isTrue.push(s[i]);
			else
			{
				if (umap[isTrue.top()] == s[i])
					isTrue.pop();
				else
					isTrue.push(s[i]);
			}

		}
		return isTrue.empty() ? true : false;
	}
};