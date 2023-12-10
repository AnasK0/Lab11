#include "BinaryNode.h"

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(ItemType value)
{
    this->value = value;
    this->leftPtr = nullptr;
    this->rightPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::~BinaryNode()
{
}