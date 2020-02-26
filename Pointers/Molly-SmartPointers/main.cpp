#include <iostream>
#include "BST.h"


enum INPUT
{
    INSERT,
    SEARCH,
    DELETE,
    PRINT,
    QUIT,
    WAIT
};

void processInput(INPUT& input)
{
    char menuChoice;
    std::cout << "\n What do you want to do? \n i - insert \n s - search \n d - delete \n p - print \n q - quit" << std::endl;
    std::cin >> menuChoice;
    if (menuChoice == 'i')
    {
        input = INSERT;
    }
    else if (menuChoice == 's')
    {
        input = SEARCH;
    }
    else if (menuChoice == 'd')
    {
        input = DELETE;
    }
    else if (menuChoice == 'p')
    {
        input = PRINT;
    }
    else if (menuChoice == 'q')
    {
        input = QUIT;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        input = WAIT;
    }
    std::cout << "-----------------------------------------------------------------------------------\n";
}

int main()
{
    int root;
    std::cout << "Enter root value: ";
    std::cin >> root;
    BST searchTree(root);
    std::cout << "Creating a new Binary Search Tree with a root of " << root << std::endl;
    // i know there's a function that does this
    std::cout << "-----------------------------------------------------------------------------------\n";

    INPUT input = WAIT;
    do
    {
        bool success = false;
        processInput(input);
        switch (input)
        {
        case INSERT:
            int insertData;
            std::cout << "Number to insert: ";
            std::cin >> insertData;
            success = searchTree.Insert(insertData);
            if (success)
            {
                std::cout << "\n SUCCESSFUL INSERT \n";
            }
            else
            {
                std::cout << "\n something went wrong \n";
            }
            break;
        case SEARCH:
            int searchTerm;
            std::cout << "Number to find: ";
            std::cin >> searchTerm;
            success = searchTree.Search(searchTerm);
            if (success)
            {
                std::cout << "\n Found " << searchTerm << std::endl;
            }
            else
            {
                std::cout << searchTerm << " is not in the tree \n";
            }
            break;
        case DELETE:
            int deleteTerm;
            std::cout << "Number to delete: ";
            std::cin >> deleteTerm;
            success = searchTree.Delete(deleteTerm);
            if (success)
            {
                std::cout << "\n Deleted " << deleteTerm << std::endl;
            }
            else
            {
                std::cout << deleteTerm << " is not in the tree \n";
            }
            break;
        case PRINT:
            searchTree.Print();
            break;
        
        default:
            break;
        }
    } while (input != QUIT);
    
    std::cout << "\n Goodbye!";

    return 0;
}