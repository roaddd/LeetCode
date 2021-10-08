#include <iostream>
#include <unordered_set>
using namespace std;

//利用unordered_set
class RandomizedSet {
public:
	RandomizedSet() {
		uset = {};
	}

	bool insert(int val) {
		if (uset.count(val) != 0)
			return false;
		uset.insert(val);
		return true;
	}

	bool remove(int val) {
		if (uset.count(val) == 0)
			return false;
		uset.erase(val);
		return true;
	}

	int getRandom() {
		auto iter = uset.begin();
		advance(iter, rand() % uset.size());
		return *iter;
	}
private:
	unordered_set<int>uset;
};

/*
	看了leetcode解法，Java版本使用一个动态数组和哈希表实现：
	动态数组：存储元素值
	哈希表：键为元素值，值为元素值在动态数组中的索引。
	插入和随机获取值可实现常数的时间复杂度
	在删除元素时，采用先查到元素值的索引，然后在数组中找到它，时间复杂度为常数，
	然后在将要删除的值与数组末尾的值交换，最后将数组末尾的值删除，在这过程中即时更新
	元素在哈希表中对应的索引，整个过程的时间复杂度为常数。
*/

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

	return 0;
}