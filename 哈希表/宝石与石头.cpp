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


class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_set<char>uset;
		int sum=0;
		for (char c : jewels)
		{
			uset.insert(c);
		}
		for (char c : stones)
		{
			if (uset.count(c) != 0)
				sum++;
		}
		return sum;
	}
};

//上面方法的简写版
class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		return count_if(stones.begin(), stones.end(), [&](char c) {return any_of(jewels.begin(), jewels.end(), [&](char a) {return a == c; }); });
	}
};

int main()
{
	Solution*s = new Solution;
	string J = "aA";
	string S = "aAAbbbb";
	cout << s->numJewelsInStones(J, S);
	return 0;
}