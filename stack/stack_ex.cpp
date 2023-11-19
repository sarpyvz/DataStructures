#include <iostream>
#include <string>
#include "codeStack.h"

using namespace std;

// Destructor, no need to meddle with.
codeStack::~codeStack() {
    for (stackNode *p; !isEmpty(); ) {
        p = top->next;
        delete top;
        top = p;
    }
}

// Fill in this .
void codeStack::pushToStack(const char* s) {
    top->next = new stackNode(s);
    top = top->next;
    return;
}

// Fill in this 
string codeStack::popFromStack() {
	if (top != 0) {
        temp = top;
        top = top->next;
        s = temp->info;
        temp -> next = NULL;
        delete temp;
    	return s;
	}
	// What would you RETURN when there is nothing to delete. No need to meddle with the code below, I'd advise you to check what it does though.
	cout << "Error: Nothing to delete." << endl;
    //throw "Nothing to delete!";
}

// Fill in this .

void codeStack::printStack() {
    while ( top != NULL){
        inf = popFromStack();
        cout << inf;
    }
    

    return;
}

// Fill in for this 

void codeStack::printReverseStack() {
    stackNode temp;
    while ( top!= NULL ){
        temp.pushToStack(top->info);
        popFromStack();
    }
    while ( temp.top != NULL){
        cout << temp.top->info << endl;
        pushToStack(temp.top->info);

    }
    delete temp;

    return;
}

