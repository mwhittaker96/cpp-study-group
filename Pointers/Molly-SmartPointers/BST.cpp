#include "BST.h"
#include <memory>
#include <iostream>

static bool SearchNode(Node* currentNode, int searchTerm)
{
    if (currentNode == nullptr)
    {
        return false;
    }
    
    int nodeVal = currentNode->GetData();
    if (nodeVal == searchTerm)
    {
        return true;
    }
    else
    {
        Node* node = searchTerm < nodeVal ? currentNode->GetLeft() : currentNode->GetRight();
        return SearchNode(node, searchTerm);
    }
}

static bool InsertNode(Node* currentNode, int newData)
{
    // Really we should throw an error here
    if (currentNode == nullptr)
    {
        return false;
    }
    
    int nodeVal = currentNode->GetData();
    // Eventually we'd want to increment the count in a node but rn they don't have a count
    if (nodeVal == newData)
    {
        return true;
    }
    else
    {
        if (newData < nodeVal)
        {
            if (currentNode->GetLeft() == nullptr)
            {
                currentNode->SetLeft(newData);
                return true;
            }
            else
            {
                return InsertNode(currentNode->GetLeft(), newData);
            }
        }
        else
        {
            if (currentNode->GetRight() == nullptr)
            {
                currentNode->SetRight(newData);
                return true;
            }
            else
            {
                return InsertNode(currentNode->GetRight(), newData);
            }
        }
    }
}

static void PrintNode(Node* currentNode, int numSpaces)
{
    if (currentNode == nullptr)
    {
        return;
    }

    numSpaces += 10;
    PrintNode(currentNode->GetRight(), numSpaces);

    // space out the levels of the tree
    std::cout<<std::endl;  
    for (int i = 10; i < numSpaces; i++)  
        std::cout << " ";  
    std::cout << currentNode->GetData() << std::endl;;  
  
    // Process left child  
    PrintNode(currentNode->GetLeft(), numSpaces);
}

BST::BST(int rootData)
{
    m_root = std::make_unique<Node>(rootData);
}

bool BST::Search(int data)
{
    return SearchNode(m_root.get(), data);
}

bool BST::Insert(int newData)
{
    return InsertNode(m_root.get(), newData);
}

void BST::Print()
{
    PrintNode(m_root.get(), 0);
}

bool BST::Delete(int deleteTerm)
{

}