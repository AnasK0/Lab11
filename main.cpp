#include <iostream>
#include "BinarySearchTree.h"
#include <string>

int main()
{
    BinarySearchTree<std::string> a;
    BinarySearchTree<std::string> b;
    BinarySearchTree<std::string> c;
    a.insertValue("Star Wars");
    a.insertValue("Star Trek");
    a.insertValue("Space Balls");
    a.insertValue("Galaxy Quest");
    a.getAllAscending();

    b.insertValue("Cars");
    b.insertValue("Monsters Inc");
    b.insertValue("The Incredibles");
    b.insertValue("Wall-E");
    b.getAllAscending();

    c.insertValue("Halloween");
    c.insertValue("A Nightmare On Elm Street");
    c.insertValue("Hocus Pocus");
    c.insertValue("Beetlejuice");
    c.getAllAscending();

    return 0;
}

