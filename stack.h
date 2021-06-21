/*********************************
Name: Nick Jocius
Simple Int Stack
File: stack.h
Purpose: Simple example of the ADT
Stack using an array of ints.
**********************************/

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define MAX 10
#include <iostream>
#include <stdexcept>

class Stack
{

public:
    // Constructors
    Stack();

    // Destructor
    ~Stack();

    // setters

    // Class methods
    bool push(int);
    int pop();
    int peek();
    bool isEmpty();

protected:
    int top;
    int stkArray[MAX];

}; // end Stack

#endif //STACK_STACK_H