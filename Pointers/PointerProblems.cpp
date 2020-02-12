#include <iostream>

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}
void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
//Swap two variables in a function called swap. 
//Make two versions of it -> void swap(int&a , int& b); void swap(int* a, int* b);
void PointerQuestion1()
{
	int a = 10;
	int b = 30;

	std::cout << "Before Swapping a = 10 & b = 30 :" << a <<" "<< b << std::endl;
	Swap(&a, &b);
	std::cout << "After Swapping a = 10 & b = 30 by reference: " << a << " " << b << std::endl;

	Swap(a, b);
	std::cout << "After Swapping a = 10 & b = 30 by pointers: " << a <<" "<< b << std::endl;

}

//Write a C++ program to find the max of an integral data set. 
//The program will ask the user to input the number of data values in the set and each value. 
//The program prints on screen a pointer that points to the max value.
void PointerQuestion2()
{

}

int main()
{
	PointerQuestion1();

	return 0;
}