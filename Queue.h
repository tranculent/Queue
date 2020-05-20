#pragma once
#include <iostream>
using namespace std;

#define SIZE 10

class Queue
{
public:
	Queue(int size = SIZE);
	~Queue();

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
	void display();

private:
	int* arr;
	int capacity;
	int front;
	int last;
	int count;

};

Queue::Queue(int size) {
	arr = new int[size];
	capacity = size;
	front = 0;
	last = -1;
	count = 0;
}

Queue::~Queue() {
	cout << "Destroying queue..." << endl;
	delete arr;
}

void Queue::dequeue() {
	if (isEmpty()) {
		cout << "Underflow.." << endl;
		return;
	}

	cout << "Removing " << arr[front] << endl;

	front++;
	count--;
}

void Queue::enqueue(int x) {
	if (isFull()) {
		cout << "Overflow..";
		return;
	}

	cout << "Inserting " << x << "\n";

	last++; // 2 => (3) % 10 => 3 remainding (10 / 3)
	arr[last] = x;
	count++;
}

int Queue::peek() {
	if (isEmpty()) {
		cout << "Underflow" << endl;
		return - 1;
	}
	return arr[front];
}

int Queue::size() {
	return count;
}

bool Queue::isEmpty() {
	return count == 0;
}

bool Queue::isFull() {
	return count == capacity;
}

void Queue::display() {
	for (int i = front; i <= last; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
