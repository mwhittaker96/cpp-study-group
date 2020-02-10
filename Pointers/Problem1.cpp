// Swap two variables in a function called swap. Make two versions
// void swap (int& a int& b)
// void swap (int* a, int*b)

#include <iostream>

void swap(int& a, int& b)
{
    std::cout << "Swapping reference variables" << std::endl;
    printf("Start - A: %i, B: %i \n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("End - A: %i, B: %i \n", a, b);
}

void swap(int* a, int* b)
{
    // Here I'm choosing to swap the values of a and b rather than swapping the memory addresses
    
    // check that the pointers are not null!
    if (a && b)
    {
        std::cout << "Swapping pointer variables" << std::endl;
        printf("Start - A: %i, B: %i \n", *a, *b);
        int temp = *a;

        *a = *b;
        *b = temp;
        printf("End - A: %i, B: %i \n", *a, *b); 
    }
}

int main()
{
    // declare two ints on the stack
    int a = 1;
    int b = 43;
    // Swap a and b by reference
    swap(a, b);

    // Declare c and d on the heap
    int* c = new int(22);
    int* d = new int(400);
    // Swap c and d as pointers
    swap(c, d);

    // Pointers are just memory addresses
    swap(&a, &b);

    // and references are just aliases for existing variables
    swap(*c, *d);

    // Free our dynamically allocated memory
    delete c;
    delete d;

    return 0;
}