/**************************************************************************************************

Author:         Robert Perlstein
Date:           11-28-11
Description:    This program demonstrates the use of user-defined manipulators for the i/o stream.
                A manipulator that format numbers into the traditional American way of printing
                large numbers that have commas seperating thousands. E.G. 1,000,000.
                A second manipulator that turns any base 10 unsigned integer into base 3.

**************************************************************************************************/

#include <iostream>
#include "list.h"

typedef int T;

//template < typename T >
list::list()
{
    head = 0;
    length= 0;
}

//template < typename T >
unsigned list::GetSize() const
{
    return length;
}

//template < typename T >
const T& list::GetFront() const
{
    return head->Data();
}

//template < typename T >
void list::PushFront( const T& val )
{
    head = new node( val, head );
    ++length;
}

//template < typename T >
void list::PopFront()
{
    if( length > 0 ) {
        node* temp = head;
        head = head->Link();
        delete temp;
        --length;
    }
}
