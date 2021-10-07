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

//哈希映射
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>vec;
		unordered_map<string, vector<string>>umap;
		for (int i = 0; i < strs.size(); i++)
		{
			string s = transtr(strs[i]);
			umap[s].push_back(strs[i]);
		}
		
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
			vec.push_back(iter->second);
		return vec;
	}
	//设计哈希映射的键
	string transtr(string s)
	{
		sort(s.begin(), s.end());
		return s;
	}
};

//计数
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// 自定义对 array<int, 26> 类型的哈希函数
		auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
			return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
				int a = acc;
				int b = num;
				int d = acc << 1;
				int e = fn(num);
				int c = (acc << 1) ^ fn(num);
				return (acc << 1) ^ fn(num);
			});
		};

		unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
		for (string& str : strs) {
			array<int, 26> counts{};
			int length = str.length();
			for (int i = 0; i < length; ++i) {
				counts[str[i] - 'a'] ++;
			}
			mp[counts].emplace_back(str);
		}
		vector<vector<string>> ans;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ans.emplace_back(it->second);
		}
		return ans;
	}
};


int main()
{
	Solution2*S = new Solution2;
	vector<string>s = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>>ret = S->groupAnagrams(s);
	for (auto elm : ret)
	{
		for (auto elem : elm)
		{
			cout << elem << " ";
		}
		cout << "\n";
	}



	return 0;
}