
#ifndef _avltree
#define _avltree

#include <iostream>
#include <algorithm>

#include "data_holder.h"
#include <list>

class AVL_Node
{
public:

    typedef data_holder T;

    AVL_Node();
    // Construction for root
    AVL_Node( T );
    // Construction for any child
    AVL_Node( T, AVL_Node* );
    AVL_Node( T, AVL_Node*, AVL_Node* );
    AVL_Node( AVL_Node& );

    //Modifiers
    void remove();
    void setParent( AVL_Node* );
    void setLeftChild( AVL_Node* );
    void setRightChild( AVL_Node* );
    void setKey( std::string );
    void setData( T );

    //Accesorss
    T getData();
    std::string getKey();
    AVL_Node* getParent();
    AVL_Node* getLeftChild();
    AVL_Node* getRightChild();


private:

    T data;
    std::string key;
    AVL_Node* parent;
    AVL_Node* left_child;
    AVL_Node* right_child;

};

class AVL_Tree
{
public:

    typedef data_holder T;

    // Construction
    AVL_Tree();
    AVL_Tree( AVL_Node* );

    // Modifiers
    void push( T );
    AVL_Node* push( AVL_Node*, AVL_Node* );

    void remove( T );
    //void pop( T );
    AVL_Node* rotateRight();
    AVL_Node* rotateRight( AVL_Node* );
    AVL_Node* rotateLeft();
    AVL_Node* rotateLeft( AVL_Node* );

    // Accesors
    AVL_Node* getRoot();
    int checkAVL();
    int checkAVL( AVL_Node* );
    int depth();
    int depth( AVL_Node* );
    AVL_Node* findFirstOccurence( AVL_Node*, std::string );
    void findAllOccurences( std::list<AVL_Node*>&, AVL_Node*, std::string );
    void listAllNodes( std::list<AVL_Node*>&, AVL_Node* );

private:

    AVL_Node* root;

};


#endif
