#pragma once

#ifndef BINARY_NODE_
#define BINARY_NODE_ 
#include <memory>

template <class ItemType>
class BinaryNode
{
    public:
        BinaryNode(ItemType value);     // Constructor to create a node and initialize it with a value
        ~BinaryNode(); // Destructor

        ItemType value;     // Stores the value of the node
        std::shared_ptr<BinaryNode> leftPtr;    // Stores the left pointer to another node
        std::shared_ptr<BinaryNode> rightPtr;   // Stores the right pointer to another node
};
#include "BinaryNode.cpp"
#endif