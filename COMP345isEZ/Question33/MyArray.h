#pragma once
class MyArray {
private:
	int size=0;
	int* theArray;
public:
	//default constructor
	MyArray();

	//parameterize constructor
	MyArray(int[], int);

	//copy constructor
	MyArray(const MyArray &a);

	//assignment operator
	MyArray& operator =(const MyArray v1);

	/*an isInArray non-inline member function that gets an integer value as a parameter and
	returns true if the value received as parameter is in theArray, and false if it is not.*/
	bool isInArray(int a);

	//a getArray inline member function returning theArray.
	inline int* getArray() {
		return theArray;
	}

	//a getSize inline member function returning the size of the stored array.
	inline int getSize() {
		return size;
	}

	//a destructor
	~MyArray();

};

