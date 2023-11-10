#include <iostream>

// Node construct and head
struct Node{
        int item;
        Node* next;
    };
Node *head = new Node;

int delete_value(int n,Node*head){
    Node* curr;
    curr = head;
    while( curr != NULL && curr->next != NULL){
        if ( (curr->next)->item == n){
            curr->next = (curr->next)->next;
            break;
        }
        else{
            curr = curr->next;
        }        


    }
    delete curr;
    return 0;
}

int merging(Node* head1, Node* head2 ){
    Node* curr1 = head1;
    Node*  curr2 = head2;
    while ( curr1 != NULL ){
        if ( curr1 -> next == NULL){
            curr1 -> next = head2;
        }
    }
    return 0;
}


int getNthNode(int n, Node* head){
    Node* curr = head;
    int count = 1;
    while ( curr != NULL){
        if (count == n){
            std::cout << "Position: \n" << count << std::endl;
            std::cout << "Value: " << curr->item << std::endl; 
            return 0;  
        }
        curr = curr -> next;
        count++;

    }
    return -1;

}


int main(){
    Node *curr = head;
    head ->next = new Node;
    curr = head->next;
    curr ->next = new Node;
    curr = curr->next;

    delete_value(31,head);



}
