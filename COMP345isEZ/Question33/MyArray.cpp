#include "MyArray.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
MyArray::MyArray()
{
	theArray = new int[size];
}
//parameterize constructor
MyArray::MyArray(int arr[], int x)
{
	theArray = new int[x];
	for (int i = 0; i < x; i++) {
		if (isInArray(arr[i]) == false) {
			theArray[size] = arr[i];
			size++;
		}
	}
	
}
//copy constructor
MyArray::MyArray(const MyArray &a)
{

	size = a.size;
	theArray = a.theArray;
	
}
//assignment operator
MyArray& MyArray::operator=(const MyArray v1)
{
	cout << "assignment operator" << endl;
	theArray = v1.theArray;
	size = v1.size;
	return *this;
}
/*an isInArray non-inline member function that gets an integer value as a parameter and
returns true if the value received as parameter is in theArray, and false if it is not.*/
bool MyArray::isInArray(int a)
{
	if (size == 0) {
		return false;
	}
	for (int i = 0; i < getSize(); i++) {		
		if (a == getArray()[i])
			return true;
	}
	return false;
}

//destructor
MyArray::~MyArray()
{
	cout << "destructing" << endl;
}

int main() {
	cout << "Creating statically allocated array..." << endl;
	int sampleArray[4] = { 1, 2 ,2, 4 };
	cout << "Using constructor..." << endl;
	MyArray anArray(sampleArray, 4);
	cout << "Using copy constructor..." << endl;
	MyArray *copiedArray = new MyArray(anArray);
	cout << "Printing content of MyArray..." << endl;
	for (int i = 0; i < copiedArray->getSize(); i++)
		cout << copiedArray->getArray()[i] << endl;
	delete copiedArray;
	int i;  cin >> i;
}