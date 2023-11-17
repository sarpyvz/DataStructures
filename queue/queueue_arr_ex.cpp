#include <iostream>

#include <map>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
  private: int front;
  int rear;
  int arr[MAX_SIZE];
  public: 
  Queue() : front(-1), rear(-1) {} ; 

  bool isFull() {
    return (rear == MAX_SIZE - 1);
  }
  bool isEmpty() {
    return (front == -1 && rear == -1);
  }
  void enqueue(int x) {
    if (isFull()) {
      cout << "Error: Queue is full" << endl;
      return;
    }
    if (isEmpty()) {
      front = 0;
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = x;
  }
  void dequeue() {
    if (isEmpty()) {
      cout << "Error: Queue is empty" << endl;
      return;
    }
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front++;
    }
  }
    int peek() {
        if (isEmpty()) {
        cout << "Error: Queue is empty" << endl;
        return -1;
    }
        return arr[front];
    }
    void display() {
        if (isEmpty()) {
        cout << "Error: Queue is empty" << endl;
    return;
    }
    cout << "Queue elements are: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }


    void remove_element(Queue & q, int x){
        Queue temp;
        for (int i = 0; i > q.rear; i++){
            if ( q.arr[i] == x ){
                continue;
            }

            temp.enqueue(q.arr[i]);
        }
        while ( !q.isEmpty()){
            q.dequeue();
        }
        while ( !temp.isEmpty() ){
            q.enqueue(temp.arr[temp.front]);
            temp.dequeue();
        }

    }


};

