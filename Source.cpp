#include <iostream>
#include <fstream>
#include "Array.h"
#include<string>
using namespace std;
int main() {
	fstream input("file.txt", ios::in);
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	Array<int>A(size);
	cout << "\nTesting Getsize function: ";
	cout << A.getSize()<<endl;
	cout << "Enter elements of the Array: \n";
	for (int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	cout << "Testing operator []: ";
	for (int i = 0; i < size; i++)
	{
		cout << A[i]<<" ";
	}
	
	

	cout << "\nTesting CopyConstructor B(A): ";
	Array<int>B(A);
	for (int i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	
	cout << "\nTesting operator= (C=B) : ";
	Array<int>C = B;
	for (int i = 0; i < size; i++)
	{
		cout << C[i] << " ";
	}
	cout << "\nTesting operator== (AA==A): ";
Array<int>AA(2);
cout << (AA == A) ? 1 : 0;

cout << "\nTesting operator!= (AA!=A): ";
cout << (AA != A) ? 1 : 0;

cout << "\nTesting overloaded operator<< (Array A): ";
cout << A;


cout << "\nTesting overloaded operator>> (Array<double> A3): ";
cout << "\nEnter the size of the Array A3: ";
cin >> size;  Array<double>A3(size);
cout << "Enter elements of the Array A3: ";
cin >> A3;
cout << A3;

cout << "Testing Array S of string: " << "\nEnter size of the Array<string>S: ";
cin >> size;
Array<string>S(size);

cout << "\nEnter elements of the Array<string>S: ";
cin >> S;
cout << S;
	
cout << endl;
	system("pause");
	return 0;
}