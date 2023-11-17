#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* back;  // Pointer to the back of the queue

public:
    Queue() : front(nullptr), back(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (back == nullptr) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        std::cout << val << " enqueued to the queue.\n";
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        }

        std::cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }

    // Function to get the front element of the queue
    int getfront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element.\n";
            return -1; // Return a default value or throw an exception
        }
        return front->data;
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


double average(Queue queue){
    int sum;
    int size;
    while ( !queue.isEmpty()){
        sum += queue.getfront();
        queue.dequeue();
        size++;
    }
    return sum / size;


}

