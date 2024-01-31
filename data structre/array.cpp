#include <iostream>

using namespace std;
class Array
{
private:
	int size;
	int length;
	int* ptr;
public:
	Array(int arrsize)
	{
		ptr = new int[arrsize];
		size = arrsize;
		length = 0;
	}
	void fillarray()
	{
		int manyitem = 0;
		cout << "how many items you went enter ?" << endl;
		cin >> manyitem;
		if (manyitem <= size)
		{
			for (int i = 0; i < manyitem; i++)
			{
				cout << "inter item number : " << i << endl;
				cin >> ptr[i];
				length++;
			}
		}
		else
		{
			cout << "you can't exceed the arrey size." << endl;
			return;
		}

	}
	void display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << "the item number " << i << " is : " << ptr[i] << endl;
		}
	}
	int getsize()
	{
		return size;
	}
	int getlegth()
	{
		return length;
	}
	bool search(int key)
	{
		
		for (int i = 0; i < length; i++)
		{
			if (key == ptr[i])
			{
				return true;
			}
		}
		return false;
	}
	void append(int newitem)
	{
		if (length == size)
		{
			cout << "the array is fill.\n";
		}
		else
		{
			ptr[length] = newitem;
			length++;
		}
	}
	void insert(int index, int newitem)
	{
		if (length == size)
		{
			cout << "the array is fill you con't enter any item.\n";
		}
		else
		{
			if (index >= size && index < 0)
			{
				cout << "the index is not found.\n";
			}
			else
			{
				for (int i = length; i > index; i--)
				{
					ptr[i] = ptr[i - 1];
				}
				ptr[index] = newitem;
				length++;
			}
		}
	}
	void Delete(int index)
	{
		if (index >= size && index < 0)
		{
			cout << "the index is not found.\n";
		}
		else
		{
			for (int i = index; i < length - 1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			length--;
		}
	}
	void enlarge(int newsize)
	{
		if (newsize <= size)
		{
			cout << "the new size is last than old size.\n";
		}
		else
		{
			int* old = ptr;
			size = newsize;
			ptr = new int[newsize];
			for (int i = 0; i < length; i++)
			{
				ptr[i] = old[i];
			}
			delete[]old;
		}
	}
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