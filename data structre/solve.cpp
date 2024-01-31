#include <iostream>

using namespace std;

class Array
{
private:
	int size;
	int* ptr;
	int length;

public:
	Array(int arrsize)
	{
		ptr = new int[arrsize];
		size = arrsize;
		length = 0;
	}

	// Rest of the code...

	void morge(Array other)
	{
		int newsize = size + other.size;
		size = newsize;
		int* old = ptr;
		ptr = new int[newsize];
		for (int i = 0; i < length; i++)
		{
			ptr[i] = old[i];
		}
		for (int i = length; i < (length + other.length); i++)
		{
			ptr[i] = other.ptr[i - length];
		}
		length += other.length;
		delete[] old;
	}
};

int main()
{
	int arrsize = 0;
	cout << "Hello! This is Array ADT demo." << endl;
	cout << "Enter the size of the array: ";
	cin >> arrsize;

	Array myarray(arrsize);
	myarray.fillarray();

	Array other(3);
	other.fillarray();

	myarray.morge(other);
	myarray.display();

	return 0;
}