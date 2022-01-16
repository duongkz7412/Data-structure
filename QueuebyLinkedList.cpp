#include<bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* next;
	QNode(int d) {
		data = d;
		next = NULL ;
	}
};

struct Queue {
	QNode* front, * rear;
	Queue() {
		front = rear = NULL;
	}

	void enQueue(int x) {
		//creat a new LL node
		QNode* temp = new QNode(x);
		//if queue empty , then
		//new node is front and rear both
		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		//add the new node at
		// the end of queue and change rear
		rear->next = temp;
		rear = temp;
	}
	//function to remove a key from given queue q
	void deQueue() {
		//if queue is empty, return NULL 
		if (front == NULL)
			return;
		//store previous front and move front one node ahead
		QNode* temp = front;
		front = front->next;
		//if front becomes NULL, then change rear also as NULL
		if (front == NULL)
			rear = NULL;
		delete(temp);
	}

};

//driven program
int main() {
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}