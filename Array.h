#ifndef  ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class Array
{

	template<typename T>friend ostream &operator<<(ostream &, const Array<T> &);
	template<typename T>friend istream &operator>> (istream &, Array<T> &);
public:
	//Array(int = 10);
	Array(int arraySize) {

		if (arraySize>0)
		{
			size = arraySize;
		}
		else throw invalid_argument("Array size must be greater than 0");

		ptr = new  T[size];
	
	}

	Array(const Array & arrayToCopy):size(arrayToCopy.size) {

		ptr = new int[size];
				for (int i = 0; i < size; i++)
				{
					ptr[i] = arrayToCopy.ptr[i];
				}


	}
	~Array() {


		delete[] ptr;
	}
	int getSize()const
	{

		return size;
	}

	const Array &operator= (const Array & right) {

		if (&right != this)
					{
						if (size!=right.size)
						{
							delete[] ptr;
							size = right.size;
							ptr = new T[size];
						}
						for (int i = 0; i < size; i++)
						{
							ptr[i] = right.ptr[i];
						}
					}
				
					return *this;


	}
	bool operator==(const Array & right)const
	{
		if (size != right.size)
						{
							return false;
						}
					
						for (int i = 0; i < size; i++)
						{
							if (ptr[i]!=right.ptr[i])
							{
								return false;
					
							}
						}
						return true;


	}

	bool operator!=(const Array & right)const
	{
		return !(*this == right);
	}

	T &operator[](int subscript)
	{

		if (subscript<0 || subscript >= size)
						{
							throw out_of_range("Subscript out of range");
						}
					
						return ptr[subscript];

	}

	T operator[](int subscript)const
	{


			if (subscript < 0 || subscript >= size)
				 throw out_of_range("Subscript out of range");
			
				 return ptr[subscript];
}

	
private:
	int size;
	T *ptr;
	

};

#endif // ! ARRAY_H

#pragma once

template<typename T>
inline ostream & operator<<(ostream & output, const Array<T>& a)
{
	int i;
				for ( i = 0; i < a.size; i++)
				{
					output << setw(12) << a.ptr[i];
					if ((i+1)%4==0)
					{
						output << endl;
			
					}
				}
				if (i%4!=0)
				{
			
					output << endl;
				}
				return output;
	
}

template<typename T>
inline istream & operator>>(istream & input, Array<T> & a)
{
	for (int i = 0; i < a.size; i++)
						{
							input >> a.ptr[i];
						}
						return input;
	
}
