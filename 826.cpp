#include<iostream>
#include"stdlib.h"
using namespace std;
struct ListNode {

	ListNode* next;
	int data;
	ListNode() :data(0), next(0) {};
	ListNode(int x) :data(x), next(0) {};
};
class MyQueue {
private:
	ListNode* front;
	ListNode* rear;
	int size;
public:
	MyQueue();
	bool IsEmpty();
	void Enqueue(int);
	int  Dequeue();
	int Search(int);
	int getFront();
	int getBack();

};

MyQueue::MyQueue() {
	size = 0;
	front = NULL;
	rear = NULL;
}
bool MyQueue::IsEmpty() {
	return(front == NULL);
}

void MyQueue::Enqueue(int data) {
	ListNode *p = new ListNode(data);
	if (IsEmpty())
		front = p;
	else rear->next = p;
	rear = p;
}

int MyQueue::Dequeue() {
	int ret_value;
	if (!IsEmpty())
	{
		ret_value = front->data;
		front = front->next;
	}
	return ret_value;
}
int  MyQueue::Search(int data) {
	int i = 1;
	ListNode *p = front;
	ListNode *r = rear;
	while (p->next != NULL)
	{
		if (p->data == data) {
			i = 0;
		}
		p = p->next;
	}
	if (r->data == data) {
		i = 0;
	}
	return i;
}


int MyQueue::getFront() {

	if (IsEmpty()) {
		std::cout << "Queue is empty.\n";
		return -1;
	}

	return front->data;
}

int MyQueue::getBack() {

	if (IsEmpty()) {
		std::cout << "Queue is empty.\n";
		return -1;
	}

	return rear->data;
}

int main() {
	int m, n, value;
	int i = 1;
	int count = 0;
	MyQueue s;
	cin >> m >> n;
	if (m < 1 || m>100) {
		return 0;
	}
	if (n < 1 || n>1000) {
		return 0;
	}
	while (n--) {
		cin >> value;
		
		if (i == 1) {
			s.Enqueue(value);
			count++;
			i++;
		}
		else if (i <= m && s.Search(value) != 0) {
			s.Enqueue(value);
			count ++;
			i++;
		}
		else if (i <= m && s.Search(value) == 0) {
			count = count + 0;
		}
		else if (i > m && s.Search(value) == 0	) {
			count = count + 0;
			i++;
		}
		else{
			s.Enqueue(value);
			s.Dequeue();
			count++;
			i++;
		}
	
	}
	cout << count<<endl;
	return 0;
}