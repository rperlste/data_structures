#ifndef _hashtable
#define _hashtable

#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable
{


public:

    typedef std::string key_type;

    // Construction
    HashTable();

    // Hash functions
    int getHash( key_type );
    int getBucket( key_type );

    // Modifiers
    void add( key_type );
    void remove( key_type );

    // Accessors
    bool find( key_type );
    int getSize();


private:

    std::list< key_type > *buckets;
};

#endif

