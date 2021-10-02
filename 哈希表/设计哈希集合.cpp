#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
public:
	MyHashSet():data(base){
	}

	void add(int key) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if (*iter == key)return;
		}
		data[h].push_back(key);
	}

	void remove(int key) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if (*iter == key)
			{
				data[h].erase(iter);
				return;
			}
		}
	}

	bool contains(int key) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if (*iter == key)return true;
		}
		return false;
	}
private:
	vector<list<int>>data;
	static const int base = 769;
	static int hash(int key)
	{
		return key % base;
	}
};

int main()
{
	return 0;
}