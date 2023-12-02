#pragma once

template <class T>
class TemplateLLNode
{
public:
    T info;
    TemplateLLNode<T> *next;
    TemplateLLNode<T>() : next(nullptr) {}
    TemplateLLNode(T value = 0, TemplateLLNode<T> *ptr = nullptr)
        : info(value), next(ptr) {}
};

template <class T>
class TemplateLList
{
public:
    TemplateLList();
    ~TemplateLList();
    TemplateLLNode<T> *getHead() const;
    TemplateLLNode<T> *getTail() const;
    void setHead(TemplateLLNode<T> *node);
    void setTail(TemplateLLNode<T> *node);

    /**
     * Check if the list is empty
     * @return True if the list is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * Add a new node to the head of the list
     * @param value The value to be added to the new node
     */
    void addToHead(const T &value);

    /**
     * Add a new node to the tail of the list
     * @param value The value to be added to the new node
     */
    void addToTail(const T &value);

    /**
     * Delete the node at the head of the list
     * @return The value of the deleted node
     */
    T deleteFromHead();

    /**
     * Delete the node at the tail of the list
     * @return The value of the deleted node
     */
    T deleteFromTail();

    /**
     * Deletes the node with the given value from the linked list, if it exists.
     * If the value is found, the node is deleted and the linked list is modified accordingly.
     * @param value The integer value to be deleted from the linked list.
     */
    void deleteNode(const T &);

    /**
     * This method checks whether the specified value is present in the linked list or not.
     * It iterates through the list and compares the value of each node with the given value.
     * If the value is found, it returns true. Otherwise, it returns false.
     * @param value The integer value to be searched in the list.
     * @return A boolean value indicating whether the value is present in the list (True) or not (False).
     */
    bool isInList(const T &value) const;

    /**
     * Prints all the elements of the linked list. If the list is empty, nothing is printed.
     */
    void printAll() const;

    /**
     * Copy constructor that creates a new list as a deep copy of the provided list.
     * @param list The list to be copied.
     */
    TemplateLList(const TemplateLList<T> &list);

    // LAB WORK STARTS HERE

    void rotate(int k);

private:
    TemplateLLNode<T> *head, *tail;
};

#include "TemplateLList.cpp"
