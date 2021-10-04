#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int>umap;
		int sum;//Ë÷ÒýºÍ
		int min=999999;
		vector<string>ret;
		vector<string>::iterator iter=list1.begin();
		while (iter != list1.end())
		{
			umap[*iter] = iter - list1.begin();
			iter++;
		}
		for (int i = 0; i < list2.size(); i++)
		{
			if (umap.count(list2[i]) != 0)
			{
				sum = i + umap[list2[i]];
				if (sum == min)
				{
					ret.push_back(list2[i]);
				}else if (sum < min)
				{
					ret.clear();
					min = sum;
					ret.push_back(list2[i]);
				}
			}
		}
		return ret;
	}
};


int main()
{
	Solution* s = new Solution;
	vector<string>s1{ "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string>s2{ "KFC", "Shogun", "Burger King" };
	vector<string>ret = s->findRestaurant(s1, s2);
	cout << ret[0];
	return 0;
}