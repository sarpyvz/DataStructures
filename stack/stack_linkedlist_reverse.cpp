#include <iostream>
#include <vector> // You can use a vector to store stack elements
using namespace std;


class StackNode {
public:
    int data;
    StackNode* next;
    StackNode(int data){
        this ->data = data;
        this ->next = NULL;
    }

};

class Stack{
    StackNode*top;
public:
    void push(int data){
        StackNode* curr = new StackNode(data);
        curr -> next = top;
        top = curr;

    }
    StackNode* pop(){
        StackNode* curr;
        top = top->next;
        return top;

    }
    void pop2(){
        StackNode* last = top ;
        top = top -> next;
        last -> next = NULL;
        delete last;
    }

    bool isElement(int data){
        return data == top->data;
    }

    void display(){
       StackNode* s = top;
       while(s != NULL){
         cout<<s->data<<" ";
         s = s->next; 
       }
       cout<<endl;
   }
    


    void reverse(){
        StackNode* new_top;
        StackNode* curr;
        StackNode* temp;
        while ( top != NULL){
            curr = new StackNode(top->data);
            new_top = curr;
            temp = top;
            top = top->next;
            delete temp;
        }

    }    


};

int main(){

    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(9);

    cout<<"Stack-> "<<endl;
    s->display();
    cout<<endl;
    //reverse
    s->reverse();

    cout<<"Reversed Stack "<<endl;
    s->display();

    return 0;
}
