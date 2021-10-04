#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

/*
第一遍编写出现的问题：
（1）map迭代输出的顺序和insert的顺序是不一样的；
（2）unordered_map迭代输出顺序和insert顺序是一样的；
另外，如果有相同的键值，insert似乎没有起不到作用：既没有改变原有的数据，也没有插入新的数据。想要将数据存入map/unordered_map中，需要先判断是否key是否已经存在：
如果存在，则用 [] 方式修改value；如果不存在，则直接insert。
因此不需要再查找符合要求的字符在原字符串中的索引
*/
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int>umap;
		int i = 0;
		int ret=999999;
		for (i = 0; i < s.length(); i++)
		{
			if (umap.count(s[i]) != 0)
				umap[s[i]]++;
			else
				umap[s[i]] = 1;
		}
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
		{
			if (iter->second == 1)
			{
				int index = s.find(iter->first);
				if (index < ret)ret = index;
			}
		}
		return ret<999999?ret:-1;
	}
};
//修改后的版本
class Solution2 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> umap;
		for (char ch : s) {
			umap[ch]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (umap[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

//使用哈希表存储索引
class Solution3 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> umap;
		for (int i = 0; i < s.size(); i++)
		{
			if (umap.count(s[i]) != 0)
			{//表明出现多次，置为-1
				umap[s[i]] = -1;
			}
			else
				umap[s[i]] = i;//存储对应索引
		}
		int first = s.size();
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
			if (iter->second != -1&& iter->second<first)first=iter->second;
		return first==s.size()?-1:first;
	}
};

//使用队列
class Solution4 {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> umap;
		queue<pair<char, int>>que;
		for (int i = 0; i < s.size(); i++)
		{
			if (umap.count(s[i]) == 0)
			{//如果字符没有出现过，则加入哈希映射以及队列
				umap[s[i]] = i;
				que.emplace(make_pair(s[i], i));
			}
			else 
			{//如果字符出现过，则置位-1并且如果队列首元素值为-1则出队
				umap[s[i]] = -1;
				while (!que.empty() && umap[que.front().first] == -1)
					que.pop();
			}
		}
		//如果队列不空，队首则为第一个唯一字符，如果队列空，则此字符不存在
		return que.empty() ? -1 : que.front().second;
	}
};


int main()
{
	Solution4*S = new Solution4;
	string s = "loveleetcode";
	cout << S->firstUniqChar(s);
	return 0;
}