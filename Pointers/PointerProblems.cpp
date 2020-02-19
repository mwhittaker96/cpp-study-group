#include <iostream>
using namespace std;
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

int* FindMax(int arr[], int num)
{
	int* max = arr;
	for (int i = 0; i < num; ++i)
	{
		if (arr[i] > *max)
		{
			*max = arr[i];
		}
	}
	return max;
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
	int size;
	int *dataSet = nullptr;
	int *max = nullptr;
	
	cout << "Enter size of the data set: ";
	cin >> size;
	if (size)
	{
		dataSet = (int*)malloc(size * sizeof(int));
		cout << endl;

		for (int i = 0; i < size; ++i)
		{
			cout << "Enter value " << i + 1 << " : ";
			cin >> dataSet[i];
			cout << endl;
		}
		max = FindMax(dataSet, size);
	}
	else
	{
		cout << "Size invalid \n";
	}

	cout << "Max value of this data set is : " << *max;
	free(dataSet);
}

int main()
{
	//PointerQuestion1();
	PointerQuestion2();
	return 0;
}