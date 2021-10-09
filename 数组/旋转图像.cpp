#include <iostream>
#include <vector>
using namespace std;

//先内旋转再外旋转
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		for (int i = 0; i < len / 2; i++)
		{
			int j = len - 2 * i;
			for (int m = 0; m < j - 1; m++)
			{
				int tmp = matrix[i][i + m];
				matrix[i][i + m] = matrix[len - i -m - 1][i];
				matrix[len - i - m - 1][i] = matrix[len-i-1][len-i-m-1];
				matrix[len - i - 1][len - i - m - 1] = matrix[m+i][len - i - 1];
				matrix[m + i][len - i - 1] = tmp;
			}
		}
	}
};
/*
				matrix[times][times + i] = matrix[times + len - i - 1][times];
				matrix[times + len - i - 1][times] = matrix[times + len - 1][times + len - i - 1];
				matrix[times + len - 1][times + len - i - 1] = matrix[times + i][times + len - 1];
				matrix[times + i][times + len - 1] = temp;

*/

//翻转
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		//水平翻转
		for (int i = 0; i < len / 2; i++)
			for (int j = 0; j < len; j++)
				swap(matrix[i][j], matrix[len - i - 1][j]);
		//对角线翻转
		for (int i = 0; i < len - 1; i++)
			for (int j = 0; j < i; j++)
				swap(matrix[i][j], matrix[j][i]);
	}
};

int main()
{
	vector<vector<int>>vec = { {1,2},{3,4} };
	Solution*s = new Solution;
	s->rotate(vec);
	for (auto elm : vec)
		for (auto elme : elm)
			cout << elme << " ";
	return 0;
}