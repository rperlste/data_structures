
/// AVL Tree Implementation ///
#include "avlTree.h"
#include "data_holder.h"

#include <iostream>
#include <algorithm>

    AVL_Tree::AVL_Tree()
    {
        root = NULL;
    }

    AVL_Tree::AVL_Tree( AVL_Node* root )
    {
        this->root = root;
    }

    void AVL_Tree::push( T input )
    {
        // The tree has not bee built yet
        if( root == NULL ) {
            root = new AVL_Node( input );
            return;
        }
        // There already exists a root
        else{
            root = push( root, new AVL_Node(input) );
        }

        if( checkAVL(root) == 0 )
            return;
        else if( checkAVL(root) == 1 )
            root = rotateLeft(root);
        else
            root = rotateRight(root);
    }

    AVL_Node* AVL_Tree::push( AVL_Node* n, AVL_Node* m )
    {
        if( n == NULL ){
            return m;
        }
        // Insert right
        if( m->getKey() > n->getKey() )
        {
            return new AVL_Node( n->getData(), n->getLeftChild(), push( n->getRightChild(), m) );
        }
        // Insert left
        else if( m->getKey() < n->getKey() )
        {
            return new AVL_Node( n->getData(), push( n->getLeftChild(), m), n->getRightChild() );
        }
        else if( m->getKey() == n->getKey() )
        {
            if( m->getData().firstName > n->getData().firstName)
            {
                return new AVL_Node( n->getData(), n->getLeftChild(), push( n->getRightChild(), m) );
            }
            else
            {
                return new AVL_Node( n->getData(), push( n->getLeftChild(), m), n->getRightChild() );
            }
        }
    }
/*
    void AVL_Tree::remove( T input )
    {
        AVL_Node* tempNode = findFirstOccurence( root, input );
        if( tempNode == NULL )
            return;
    }

/*
    void AVL_Tree::pop( T input )
    {
        // Search for value
        AVL_Node* temp = find( input );

        // If found, remove the node
        if( temp == root ) {
            temp.remove();
            delete temp;
        }
        else if( temp != NULL ) {
            temp->remove();
            // rotate
        }
    }
    */

    AVL_Node* AVL_Tree::rotateRight()
    {
        return rotateRight( root );
    }

    AVL_Node* AVL_Tree::rotateRight( AVL_Node* n )
    {
        AVL_Node* q = root;
        AVL_Node* p = q->getLeftChild();
        AVL_Node* c = q->getRightChild();
        AVL_Node* a = p->getLeftChild();
        AVL_Node* b = p->getRightChild();

        q = new AVL_Node(q->getData(), b, c );
        p = new AVL_Node(p->getData(), a, q );

        return p;
    }

    AVL_Node* AVL_Tree::rotateLeft()
    {
        return rotateRight( root );
    }

    AVL_Node* AVL_Tree::rotateLeft( AVL_Node* n )
    {
        AVL_Node* q = root;
        AVL_Node* p = q->getRightChild();
        AVL_Node* c = q->getLeftChild();
        AVL_Node* a = p->getRightChild();
        AVL_Node* b = p->getLeftChild();

        q = new AVL_Node(q->getData(), c, a );
        p = new AVL_Node(p->getData(), q, b );

        return p;
    }

    int AVL_Tree::depth()
    {
        return depth(root);
    }

    int AVL_Tree::depth( AVL_Node* n )
    {
        if( n == NULL )
        {
            return 0;
        }
        else
        {
            return std::max( depth(n->getLeftChild()), depth(n->getRightChild()) ) + 1;
        }
    }

    int AVL_Tree::checkAVL()
    {
        return checkAVL( root );
    }

    int AVL_Tree::checkAVL( AVL_Node* n )
    {

        if( depth(n->getRightChild()) - depth(n->getLeftChild() ) >= 2 )
            return 1;
        else if( depth(n->getLeftChild()) - depth(n->getRightChild() ) >= 2 )
            return -1;
        else
            return 0;
    }

    AVL_Node* AVL_Tree::findFirstOccurence( AVL_Node* source, std::string input )
    {
        bool found = false;

        while( source != NULL ) {
            if( input == source->getKey() )
                return source;
            else if( input > source->getKey() )
                source = source->getRightChild();
            else if( input < source->getKey() )
                source = source->getLeftChild();
        }
        return source;
    }

    void AVL_Tree::findAllOccurences( std::list<AVL_Node*>& nodeList, AVL_Node* source, std::string input )
    {
        AVL_Node* tempNode;

            // Find first occurence
            tempNode = findFirstOccurence( source, input );
            // Verify there is an existing case
            if( tempNode == NULL)
                return;

            nodeList.push_back( tempNode );

            findAllOccurences( nodeList, source->getRightChild(), input );
            findAllOccurences( nodeList, source->getLeftChild(), input );


    }

    void AVL_Tree::listAllNodes(  std::list<AVL_Node*>& l, AVL_Node* n )
    {
        if( n == NULL )
            return;
        listAllNodes( l, n->getLeftChild() );
        l.push_back( n );
        listAllNodes( l, n->getRightChild() );

    }

    AVL_Node* AVL_Tree::getRoot()
    {
        return root;
    }

/// AVL Node Implementation ///

    AVL_Node::AVL_Node()
    {
        parent = NULL;
        left_child = NULL;
        right_child = NULL;
    }

    AVL_Node::AVL_Node( T input )
    {
        data = input;
        key = input.lastName;
        parent = NULL;
        left_child = NULL;
        right_child = NULL;
    }

    AVL_Node::AVL_Node( T input, AVL_Node* p )
    {
        data = input;
        key = input.lastName;
        parent = p;
        left_child = NULL;
        right_child = NULL;
    }

    AVL_Node::AVL_Node( T input, AVL_Node* left, AVL_Node* right )
    {
        data = input;
        key = input.lastName;
        parent = NULL;
        left_child = left;
        right_child = right;
    }

    void AVL_Node::remove()
    {
        delete parent;
        delete left_child;
        delete right_child;
    }

    void AVL_Node::setParent( AVL_Node* p_node )
    {
        delete parent;
        parent = p_node;
    }

    void AVL_Node::setLeftChild( AVL_Node* l_node )
    {
        delete left_child;
        left_child = l_node;
    }

    void AVL_Node::setRightChild( AVL_Node* r_node )
    {
        delete right_child;
        right_child = r_node;
    }

    AVL_Node::T AVL_Node::getData()
    {
        return data;
    }

    std::string AVL_Node::getKey()
    {
        return key;
    }

    AVL_Node* AVL_Node::getParent()
    {
        return parent;
    }

    AVL_Node* AVL_Node::getLeftChild()
    {
        return left_child;
    }

    AVL_Node* AVL_Node::getRightChild()
    {
        return right_child;
    }

