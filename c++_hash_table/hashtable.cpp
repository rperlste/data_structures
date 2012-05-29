#include "hashtable.h"

typedef std::string key_type;

HashTable::HashTable()
{
    buckets = new std::list<std::string>[1373];
}

int HashTable::getHash( key_type key )
{
    // Initialzie hash to 0
    int hash_value = 0;

    // Create hash value based on intger values
    for( int i = 0; i < key.length(); i++ ) {
        hash_value += 18*hash_value + key[i];
    }

    // Prime modolo to ensure further randomness for large hashvalues
    return hash_value > 0 ? (hash_value % 15486719) : (-hash_value % 15486719);
}

int HashTable::getBucket( key_type key )
{
    // Load hash value
    int hash_value = getHash( key );

    // Bucket function to ensure further randomness
    return ( (11*hash_value + 8111) % 1373 );
}

void HashTable::add( key_type key )
{
    //If the value is not already int he hash table, push it into the correct bucket
    if( !find( key ) ) {
        buckets[ getBucket( key ) ].push_back( key );
    }
}

void HashTable::remove( key_type key )
{
    int bucket_value = getBucket( key );

    //Check if the bucket location has any values
    if( buckets[ bucket_value ].size() == 0 )
        return;

    // Remove value
    buckets[ bucket_value ].remove( key );

    return;
}

bool HashTable::find( key_type key )
{
    int bucket_value = getBucket( key );
    std::list< std::string >::iterator it;

    //Check if the bucket location has any values
    if( buckets[ bucket_value ].size() > 0 ) {

        // Iterate through list
        for( it = buckets[ bucket_value ].begin(); it != buckets[ bucket_value ].end(); it++ ){
            // Check for key existence
            if( key == *it )
                return true;
        }
    }

    //Key not found
    return false;
}
