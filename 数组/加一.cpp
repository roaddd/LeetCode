#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 0;//½øÎ»
		vector<int>ans;
		*(digits.end() - 1) += 1;
		for (auto iter = digits.end() - 1; iter != digits.begin();iter--)
		{
			int sum = carry + *iter;
			if (sum > 9)
			{
				ans.push_back(sum % 10);
			}
			else
				ans.push_back(sum);
			carry = sum > 9 ? 1 : 0;
		}
		int sum = carry + *digits.begin();
		if (sum > 9)
		{
			ans.push_back(sum % 10);
			ans.push_back(1);
		}
		else
			ans.push_back(sum);

		for (auto iter1 = ans.begin(), iter2 = ans.end()-1; iter1 < iter2; iter1++, iter2--)
			swap(*iter1, *iter2);
		return ans;
	}
};

int main()
{
	vector<int>vec{4,3,2,1};
	Solution*s = new Solution;
	vector<int>ans = s->plusOne(vec);
	for (auto elm : ans)
		cout << elm << " ";
	return 0;
}