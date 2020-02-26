#pragma once
#include "Node.h"
// Binary search tree for ints 
class BST
{
public:
    BST(int rootData);
    
    bool Insert(int newData);
    bool Delete(int deleteTerm);
    bool Search(int searchTerm);
    void Print();
private:
    std::unique_ptr<Node> m_root = nullptr;
};
