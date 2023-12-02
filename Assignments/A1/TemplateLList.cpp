#include "TemplateLList.h"
#include <iostream>
#include <random>

template <class T>
TemplateLList<T>::TemplateLList() : head(nullptr), tail(nullptr) {}

template <class T>
TemplateLList<T>::~TemplateLList()
{
    TemplateLLNode<T> *current = head;
    while (current != nullptr)
    {
        TemplateLLNode<T> *next = current->next;
        delete current; // Delete the current node.
        current = next; // Move to the next node.
    }
    head = nullptr; // Optional: head is going out of scope anyway.
    tail = nullptr; // Optional: tail is going out of scope anyway.
}

template <class T>
TemplateLLNode<T> *TemplateLList<T>::getHead() const
{
    return head;
}

template <class T>
TemplateLLNode<T> *TemplateLList<T>::getTail() const
{
    return tail;
}

template <class T>
void TemplateLList<T>::setHead(TemplateLLNode<T> *node)
{
    head = node;
}

template <class T>
void TemplateLList<T>::setTail(TemplateLLNode<T> *node)
{
    tail = node;
}

template <class T>
bool TemplateLList<T>::isEmpty() const
{
    return head == nullptr;
}

template <class T>
void TemplateLList<T>::addToHead(const T &value)
{
    head = new TemplateLLNode<T>(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
}

template <class T>
void TemplateLList<T>::addToTail(const T &value)
{
    if (tail != nullptr)
    {
        tail->next = new TemplateLLNode<T>(value);
        tail = tail->next;
    }
    else
    {
        head = tail = new TemplateLLNode<T>(value);
    }
}

template <class T>
T TemplateLList<T>::deleteFromHead()
{
    if (head == nullptr)
    {
        throw std::runtime_error("List is empty");
    }
    T value = head->info;
    TemplateLLNode<T> *tmp = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
    }
    delete tmp;
    return value;
}

template <class T>
T TemplateLList<T>::deleteFromTail()
{
    if (tail == nullptr)
    {
        throw std::runtime_error("List is empty");
    }
    T value = tail->info;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        TemplateLLNode<T> *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            ;
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
    return value;
}

template <class T>
void TemplateLList<T>::deleteNode(const T &value)
{
    for (TemplateLLNode<T> **current = &head; *current; current = &((*current)->next))
    {
        if ((*current)->info == value)
        {
            TemplateLLNode<T> *tmp = *current;
            *current = (*current)->next;
            if (tmp == tail)
            {
                tail = (current == &head) ? nullptr : *current;
            }
            delete tmp;
            break;
        }
    }
}

template <class T>
bool TemplateLList<T>::isInList(const T &value) const
{
    TemplateLLNode<T> *tmp;
    for (tmp = head; tmp != nullptr && !(tmp->info == value); tmp = tmp->next)
        ;
    return tmp != nullptr;
}

template <class T>
void TemplateLList<T>::printAll() const
{
    for (TemplateLLNode<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
        std::cout << tmp->info << " ";
    std::cout << std::endl;
}

template <class T>
TemplateLList<T>::TemplateLList(const TemplateLList<T> &list)
{
    if (list.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {
        head = new TemplateLLNode<T>(list.head->info);
        TemplateLLNode<T> *tmp1 = head;
        TemplateLLNode<T> *tmp2 = list.head->next;
        while (tmp2 != nullptr)
        {
            tmp1->next = new TemplateLLNode<T>(tmp2->info);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tail = tmp1;
    }
}

template <class T>
void TemplateLList<T>::rotate(int k)
{
    // YOUR SOLUTION SHOULD BE WRITE IN HERE
    TemplateLLNode<T>* prev;
    TemplateLLNode<T>* curr;
    TemplateLLNode<T>* head_go;
    head_go = head;
    int size = 0;
    if (k == 0){
        printAll();
    }
    
    else if ( k > 0 ){
        for (int i = 0; i < k; i++){
            prev = head;
            tail->next = head;
            head = tail;
            for ( ; tail == head; prev = prev->next){
                if ( prev->next == tail){
                    tail = prev;
                }
            }
        }
    }
    
    else if ( k < 0){
        for (curr = head; curr != NULL; curr = curr->next){
            ++size;
        }
        curr = head;
        for ( int j = 0; j < (k*(-1) % size) + size; j++){ 
            head_go = head_go->next;
            head = head->next;
            curr->next = head_go->next;
            head_go -> next = curr;
            break;
        }

    
    }
    tail->next = NULL;
}
