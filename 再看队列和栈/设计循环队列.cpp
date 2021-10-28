#include <iostream>
#include <vector>
using namespace std;

//队空时设置head=tail=-1;队满时(tail+1)%vec.size()==head
class MyCircularQueue {
	vector<int>vec;
	int head;
	int tail;
public:
	MyCircularQueue(int k) {
		vec.resize(k);
		head = tail = -1;
	}

	bool enQueue(int value) {
		if (isFull())
			return false;
		if (isEmpty())
			head = 0;
		tail = (tail + 1) % vec.size();
		vec[tail] = value;
		return true;
	}

	bool deQueue() {
		if (isEmpty())
			return false;
		if (head == tail)
		{
			head = tail = -1;
			return true;
		}
		head = (head + 1) % vec.size();
		return true;
	}

	int Front() {
		if (isEmpty())
			return -1;
		return vec[head];
	}

	int Rear() {
		if (isEmpty())
			return -1;
		return vec[tail];
	}

	bool isEmpty() {
		return head == -1 ;
	}

	bool isFull() {
		return (tail + 1) % vec.size() == head ;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */