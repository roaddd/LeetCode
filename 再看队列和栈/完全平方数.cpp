#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

//动态规划
class Solution1 {
public:
	int numSquares(int n) {
		vector<int>vec(n + 1);
		for (int i = 1; i <= n; i++)
		{
			vec[i] = i;
			for (int j = 1; i - j * j >= 0; j++)
				vec[i] = min(vec[i], vec[i - j * j] + 1);
		}
		return vec[n];
	}
};

//广度优先搜索
class Solution {
public:
	int numSquares(int n) {
		vector<int>square;
		for (int i = 1; i*i < n + 1; i++)
			square.push_back(i*i);

		queue<int>que;
		que.push(n);
		unordered_set<int>visited{n};

		int count = 0;

		while (!que.empty())
		{
			int len = que.size();
			count++;
			for (int i = 0; i < len; i++)
			{
				int head = que.front();
				que.pop();
				for (int j = 0; j<square.size()&&square[j] <= head; j++)
				{
					if (head - square[j] == 0)
						return count;
					if (!visited.count(head - square[j]))
						que.push(head - square[j]);
					visited.insert(head - square[j]);
				}
			}
		}
		return count;
	}
};

int main()
{
	Solution*s = new Solution;
	cout << s->numSquares(12);
	return 0;
}