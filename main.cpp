/*********************************
Name: Nick Jocius
Simple Int Stack
File: main.cpp
Purpose: Simple example of the ADT
Stack using an array of ints.
**********************************/

#include "main.h"

int main(int argc, char **argv)
{

    Stack st1;
    bool pushed;
    int peeked;
    int popped;
    int ctr = 0;
    bool full;
    int rndmOp;
    int rndmN;

    /***************Empty Stack Tests***************/
    std::cout << "***************** Empty Stack tests ********************" << std::endl;
    // test isEmpty on empty stack
    full = st1.isEmpty();
    std::cout << full << std::endl;
    // test pop on empty stack/underflow
    try
    {
        st1.pop();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // test peek on empty stack/underflow
    try
    {
        st1.peek();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    /**************Overflow Tests***************/
    std::cout << "***************** Overflow tests ********************" << std::endl;
    // push beyond 50% limits of array
    for (int i = 1; i <= ((MAX * .5) + MAX); i++)
    {

        pushed = st1.push(i);
        if (pushed)
        {
            std::cout << "pushed" << std::endl;
        }
        else
        {
            std::cout << "overflow" << std::endl;
        }
    }

    /************Underflow Tests*************/
    std::cout << "***************** Underflow tests ********************" << std::endl;
    // peek and pop all from stack and display until empty
    while (!st1.isEmpty())
    {
        try
        {
            peeked = st1.peek();
            std::cout << peeked << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            popped = st1.pop();
            std::cout << popped << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

    } // end while

    //push negative ints 50% beyond full
    for (int i = 0; i >= ((MAX * -.5) - MAX); i--)
    {
        st1.push(i);
    }

    // pop beyond 50% beyond empty
    while (ctr != ((MAX * -.5) - MAX))
    {
        try
        {
            popped = st1.pop();
            std::cout << popped << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        ctr--;
    }

    std::cout << "***************** Random tests ********************" << std::endl;

    // random operations
    srand(time(NULL));
    for (int i = 0; i < ((MAX * .5) * 20); i++)
    {
        rndmOp = rand() % 4;
        switch (rndmOp)
        {
        case 0:
            rndmN = rand() % 1000;
            pushed = st1.push(rndmN);
            if (pushed)
            {
                std::cout << "pushed" << std::endl;
            }
            else
            {
                std::cout << "overflow" << std::endl;
            }
            break;
        case 1:
            try
            {
                popped = st1.pop();
                std::cout << "popped: " << popped << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            break;

        case 2:
            try
            {
                peeked = st1.peek();
                std::cout << "peek: " << peeked << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;

        case 3:
            full = st1.isEmpty();
            if (!full)
            {
                std::cout << "Not empty" << std::endl;
            }
            else
            {
                std::cout << "Empty" << std::endl;
            }
            break;

        default:
            break;
        }
    }

    return 0;

} // end main()