#include <gtest/gtest.h>
#include <iostream>
#include "BinarySearchTree.h"

// Basic insertion test
TEST(BinarySearchTreeTest, insertValue1)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    std::vector<int> v = {3,7,17,21};
    ASSERT_EQ(a.getAllAscending(), v);
}

// Insert incrementally
TEST(BinarySearchTreeTest, insertValue2)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    ASSERT_EQ(a.findValue(63), false);

    a.insertValue(63);

    ASSERT_EQ(a.findValue(63), true);

    a.insertValue(37);
    ASSERT_EQ(a.findValue(37), true);
}

// Insert big chunks
TEST(BinarySearchTreeTest, insertValue3)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    std::vector<int> v = {3,7,17,21};
    ASSERT_EQ(a.getAllAscending(), v);

    a.insertValue(39);
    a.insertValue(15);
    a.insertValue(23);
    a.insertValue(55);

    std::vector<int> v2 = {3,7,15,17,21,23,39,55};
    ASSERT_EQ(a.getAllAscending(), v2);
}

// Find values present in the tree
TEST(BinarySearchTreeTest, findValue1)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    ASSERT_EQ(a.findValue(7), true);
    ASSERT_EQ(a.findValue(3), true);
    ASSERT_EQ(a.findValue(21), true);
    ASSERT_EQ(a.findValue(17), true);
}

// Find values not present in the tree
TEST(BinarySearchTreeTest, findValue2)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    ASSERT_EQ(a.findValue(8), false);
    ASSERT_EQ(a.findValue(4), false);
    ASSERT_EQ(a.findValue(22), false);
    ASSERT_EQ(a.findValue(18), false);
}

// Find values in an empty tree
TEST(BinarySearchTreeTest, findValue3)
{
    BinarySearchTree<int> a;

    ASSERT_EQ(a.findValue(8), false);
    ASSERT_EQ(a.findValue(4), false);
    ASSERT_EQ(a.findValue(22), false);
    ASSERT_EQ(a.findValue(18), false);
}

// Try to remove a non-existent value
TEST(BinarySearchTreeTest, removeValue1)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);

    ASSERT_EQ(a.removeValue(13), false);
}

// Remove a root node with no children
TEST(BinarySearchTreeTest, removeValue2)
{
    BinarySearchTree<int> a;
    a.insertValue(7);

    ASSERT_EQ(a.removeValue(7), true);
}

// Remove a root node with two children
TEST(BinarySearchTreeTest, removeValue3)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);

    ASSERT_EQ(a.removeValue(7), true);
    std::vector<int> v = {3,21};
    ASSERT_EQ(a.getAllAscending(), v);
}

// Remove a root node with one child
TEST(BinarySearchTreeTest, removeValue4)
{
    BinarySearchTree<int> a;
    a.insertValue(7);
    a.insertValue(16);
    a.insertValue(18);
    a.insertValue(4);

    ASSERT_EQ(a.removeValue(16), true);
    std::vector<int> v = {4,7,18};
    ASSERT_EQ(a.getAllAscending(), v);
}

// Get size of an empty tree
TEST(BinarySearchTreeTest, getSize1)
{
    BinarySearchTree<int> a;

    ASSERT_EQ(a.getSize(), 0);
}

// Get size of a filled tree
TEST(BinarySearchTreeTest, getSize2)
{
    BinarySearchTree<int> a;

    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);
    a.insertValue(39);
    a.insertValue(15);
    a.insertValue(23);
    a.insertValue(55);

    ASSERT_EQ(a.getSize(), 8);
}

// Get size of an tree with one node
TEST(BinarySearchTreeTest, getSize3)
{
    BinarySearchTree<int> a;

    a.insertValue(7);

    ASSERT_EQ(a.getSize(), 1);
}

// Get all ascending with only one node
TEST(BinarySearchTreeTest, getAllAscending1)
{
    BinarySearchTree<int> a;

    a.insertValue(7);
    std::vector<int> v = {7};

    ASSERT_EQ(a.getAllAscending(), v);
}

// Get all ascending with multiple nodes
TEST(BinarySearchTreeTest, getAllAscending2)
{
    BinarySearchTree<int> a;

    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);
    a.insertValue(39);
    a.insertValue(15);
    a.insertValue(23);
    a.insertValue(55);
    std::vector<int> v = {3,7,15,17,21,23,39,55};

    ASSERT_EQ(a.getAllAscending(), v);
}

// Get all ascending with no nodes
TEST(BinarySearchTreeTest, getAllAscending3)
{
    BinarySearchTree<int> a;

    std::vector<int> v = {};

    ASSERT_EQ(a.getAllAscending(), v);
}

// Clear a tree with multiple nodes
TEST(BinarySearchTreeTest, clear1)
{
    BinarySearchTree<int> a;

    a.insertValue(7);
    a.insertValue(3);
    a.insertValue(21);
    a.insertValue(17);
    a.insertValue(39);
    a.insertValue(15);
    a.insertValue(23);
    a.insertValue(55);
    a.clear();

    std::vector<int> v = {};

    ASSERT_EQ(a.getAllAscending(), v);
}

// Clear a tree with no nodes
TEST(BinarySearchTreeTest, clear2)
{
    BinarySearchTree<int> a;

    a.clear();

    std::vector<int> v = {};

    ASSERT_EQ(a.getAllAscending(), v);
}

// Clear the root node only
TEST(BinarySearchTreeTest, clear3)
{
    BinarySearchTree<int> a;

    a.insertValue(7);
    a.clear();

    std::vector<int> v = {};

    ASSERT_EQ(a.getAllAscending(), v);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
