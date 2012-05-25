/**************************************************************************************************

Author:         Robert Perlstein
Date:           11-28-11
Description:    This program demonstrates the use of user-defined manipulators for the i/o stream.
                A manipulator that format numbers into the traditional American way of printing
                large numbers that have commas seperating thousands. E.G. 1,000,000.
                A second manipulator that turns any base 10 unsigned integer into base 3.

**************************************************************************************************/

// list();
// PRE:     None
// POST:    Initialized an empty list with no nodes

// const T& GetFront() const;
// PRE:     list has a node
// POST:    returns the data of the head node

// unsigned GetSize() const;
// PRE:     None
// POST:    returns the size of the list

// void PushFront( const T& );
// PRE:     None
// POST:    Adds a node with data T, sets head to new node

// void PopFront();
// PRE:     The list has a size > 0
// POST:    Deletes the head node and sets head to the linkfield (if one exists)


#ifndef _list
#define _list

#include <iostream>

#include "node.h"

class list
{

public:
    typedef int T;

    // Construction
    list();

    // Accessors
    const T& GetFront() const;
    unsigned GetSize() const;

    // Modifiers
    void PushFront( const T& );
    void PopFront();

private:

    node* head;
    unsigned length;

};

//#include "list.cpp.h"

#endif
