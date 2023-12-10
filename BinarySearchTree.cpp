#include "BinarySearchTree.h"
#include "BinaryNode.h"

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}

// Traverse the tree and find where a new node of class ItemType and value of "value" belongs
// Then insert it. Return true if it is "insertable"
template <class ItemType>
bool BinarySearchTree<ItemType>::insertValue(const ItemType value)
{
    std::shared_ptr<BinaryNode<ItemType>> ptr(new BinaryNode<ItemType>(value));

    // If there is no root, then given node becomes the root
    if (!rootPtr)
    {
        this->rootPtr = ptr;
        return true;
    }

    std::shared_ptr<BinaryNode<ItemType>> prevPtr = nullptr;    // keep track of pervious pointer
    std::shared_ptr<BinaryNode<ItemType>> tempPtr = this->rootPtr; // keep track of current pointer

    while (tempPtr)
    {
        // If the value is greater than the current nodes value traverse left
        if (tempPtr->value > value)  
        {
            prevPtr = tempPtr;
            tempPtr = tempPtr->leftPtr;
        }
        // If the value is less than the current nodes value traverse right
        else if (tempPtr-> value < value)
        {
            prevPtr = tempPtr;
            tempPtr = tempPtr->rightPtr;
        }
    }

    // Keep track of previous pointer
    if (prevPtr->value > value)
    {
        prevPtr->leftPtr = ptr;
    }
    else if (prevPtr->value < value)
    {
        prevPtr->rightPtr = ptr;
    }
    
    return true;
}

// Traverse the tree and find a value. Return true if it is present
template <class ItemType>
bool BinarySearchTree<ItemType>::findValue(const ItemType value)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr = rootPtr;
    // traverse the entire tree
    while (tempPtr != nullptr)
    {
        // if a match is found return true
        if (value == tempPtr->value)
        {
            return true;
        }
        // traverse left and right down the tree until we find the value
        else if (value > tempPtr->value)
        {
            tempPtr = tempPtr->rightPtr;
        }
        else
        {
            tempPtr = tempPtr->leftPtr;
        }
    }
    
    return false;   // return false if we don't find a match
}

// Remove an element from the tree
template <class ItemType>
bool BinarySearchTree<ItemType>::removeValue(const ItemType value)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr = rootPtr;
    std::shared_ptr<BinaryNode<ItemType>> prevPtr = nullptr;
    while (tempPtr != nullptr)
    {
        if (value == tempPtr->value)
        {
            // If two children
            if (tempPtr->leftPtr && tempPtr->rightPtr)
            {
                std::shared_ptr<BinaryNode<ItemType>> successorParentPtr = tempPtr;
                std::shared_ptr<BinaryNode<ItemType>> successorPtr = tempPtr->rightPtr;
                // traverse the left tree of the node to delete and find the next highest value
                while (successorPtr->leftPtr)
                {
                    successorParentPtr = successorPtr;
                    successorPtr = successorPtr->leftPtr;
                }

                tempPtr->value = successorPtr->value;

                if (successorPtr == tempPtr->rightPtr)
                {
                    tempPtr->rightPtr = successorPtr->rightPtr;
                }
                else
                {
                    successorParentPtr->leftPtr = successorPtr->rightPtr;
                }

                return true;
            }
            
            // If only one child on the left side
            if (tempPtr->leftPtr)
            {
                std::shared_ptr<BinaryNode<ItemType>> leftPtr = tempPtr->leftPtr;
                *tempPtr = *leftPtr;

                return true;
            }

            // If only one child on the right side
            if (tempPtr->rightPtr)
            {
                std::shared_ptr<BinaryNode<ItemType>> rightPtr = tempPtr->rightPtr;
                *tempPtr = *rightPtr;
                
                return true;
            }

            // If not a right or left node we can just delete the node
            if (prevPtr == nullptr)
            {
                rootPtr = nullptr;
                return true;
            }
            
            // Test the parent node of the leaf node to delete
            // Figure out if you have to null the left or right pointer of the parent
            if (prevPtr->leftPtr == tempPtr)
            {
                prevPtr->leftPtr = nullptr;
            }
            else
            {
                prevPtr->rightPtr = nullptr;
            }

            return true;
        }
        else if (value > tempPtr->value)
        {
            prevPtr = tempPtr;
            tempPtr = tempPtr->rightPtr;
        }
        else
        {
            prevPtr = tempPtr;
            tempPtr = tempPtr->leftPtr;
        }
    }
    
    return false;
}

// Return the size of the tree as in the number of nodes
template <class ItemType>
int BinarySearchTree<ItemType>::getSize()
{
    int size = this->getAllAscending().size();
    return size;
}

// Perform inorder traversal
template <class ItemType>
std::vector<ItemType> BinarySearchTree<ItemType>::getAllAscending()
{
    // Use a vector like a stack
    std::vector<std::shared_ptr<BinaryNode<ItemType>>> stack;
    // Store the inorder values
    std::vector<ItemType> values;
    if (!rootPtr)
    {
        return values;
    }

    std::shared_ptr<BinaryNode<ItemType>> tempPtr = this->rootPtr;

    // while the temporary node pointer is not null or the size of the stack is not 0
    while (tempPtr != nullptr || stack.size() != 0)
    {
        while (tempPtr != nullptr)
        {
            stack.push_back(tempPtr);
            tempPtr = tempPtr->leftPtr;
        }

        tempPtr = stack[stack.size() - 1];
        stack.pop_back();

        values.push_back(tempPtr->value);

        tempPtr = tempPtr->rightPtr;
    }

    // Print out the vector at the end
    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << "\t";
    }

    std::cout << std::endl;

    return values;    
}

// Clear the Binary Search Tree of element
template <class ItemType>
bool BinarySearchTree<ItemType>::clear()
{
    if (rootPtr == nullptr)
    {
        std::cout << "Nothing to clear" << std::endl;
        return true;
    }

    rootPtr->leftPtr = nullptr;
    rootPtr->rightPtr = nullptr;
    rootPtr = nullptr;

    return true;
}
