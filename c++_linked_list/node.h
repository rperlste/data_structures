/**************************************************************************************************

Author:         Robert Perlstein
Date:           11-28-11
Description:    This program demonstrates the use of user-defined manipulators for the i/o stream.
                A manipulator that format numbers into the traditional American way of printing
                large numbers that have commas seperating thousands. E.G. 1,000,000.
                A second manipulator that turns any base 10 unsigned integer into base 3.

**************************************************************************************************/

// node( const T& val, node* n=0 ):data_field(val),link_field(n) {}
// PRE:     None
// POST:    Creates a node object, initialized to input values

// const T& Data() const { return data_field; }
// PRE:     node has data
// POST:    returns data of type T

// const node* Link() const { return link_field; }
// PRE:     node has link
// POST:    returns const node pointer to next node in list

// void SetData( const T& val ) { data_field = val; }
// PRE:     None
// POST:    Sets data to input type T

// void SetLink( node* n ) { link_field = n; }
// PRE:     None
// POST:    Set link to a node pointer address

// node* Link() { return link_field; }
// PRE:     None
// POST:    Return non-const pointer to node


#ifndef _node
#define _node

#include <iostream>

//template < typename T >
class node
{

public:

    typedef int T;

    // Construction
    node( const T& val, node* n=0 ):data_field(val),link_field(n) {}

    // Accessors
    const T& Data() const { return data_field; }
    const node* Link() const { return link_field; }

    // Modifiers
    void SetData( const T& val ) { data_field = val; }
    void SetLink( node* n ) { link_field = n; }
    node* Link() { return link_field; }

private:

    T data_field;
    node* link_field;

};

#endif

