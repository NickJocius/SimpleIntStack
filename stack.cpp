/*********************************
Name: Nick Jocius
Simple Int Stack
File: stack.cpp
Purpose: Simple example of the ADT
Stack using an array of ints.
**********************************/

#include "stack.h"

Stack::Stack()
{
    top = -1;
} // end Stack()

Stack::~Stack() {}

bool Stack::push(int n)
{
    bool outcome = false;
    if (top < MAX - 1)
    {
        stkArray[++top] = n;
        outcome = true;
    }
    return outcome;
} // end push()

int Stack::peek()
{
    if (isEmpty())
    {
        throw std::underflow_error("underflow_error");
    }
    return *(stkArray + top);

} // end peek()

int Stack::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("underflow_error");
    }
    return stkArray[top--];

} // end pop()

bool Stack::isEmpty()
{
    return (top < 0);
} // end isEmpty()