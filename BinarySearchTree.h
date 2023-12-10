#pragma once

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include <vector>

template <class ItemType>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool insertValue(const ItemType value); // insert a new node
        bool findValue(const ItemType value);   // return true or false if the value exists in the search tree
        bool removeValue(const ItemType value); // return true or false if the node can be removed
        int getSize();  // return number of elements in the binary search tree
        std::vector<ItemType> getAllAscending();    // perform an inorder traversal and return a vector of the inorder node values
        bool clear();   // clear the binary search tree

        private:
            std::shared_ptr<BinaryNode<ItemType>> rootPtr;
};
#include "BinarySearchTree.cpp"
#endif