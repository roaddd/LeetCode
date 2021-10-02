#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
public:
	MyHashSet() :data(base) {
	}

	void put(int key,int value) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if ((*iter).first == key)
			{
				(*iter).second = value;
				return;
			}
		}
		data[h].push_back(make_pair(key,value));
	}

	int get(int key) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if ((*iter).first == key)
			{
				return (*iter).second;
			}
		}
		return -1;
	}

	bool remove(int key) {
		int h = hash(key);
		for (auto iter = data[h].begin(); iter != data[h].end(); iter++)
		{
			if ((*iter).first == key)
			{
				data[h].erase(iter);
				return;
			}
		}
	}
private:
	vector<list<pair<int,int>>>data;
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