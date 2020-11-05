/*
*	File:	main.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <iostream>

#include "heapsort.hpp"
#include "determinants.hpp"

using namespace std;

int main()
{
	bool exited = false;

	while(!exited)
	{
		int option;
		cout << "\nSelect an option:" << endl;
		cout << "\t1. Heapsort.\n\t2. Iterative determinant.\n\t3. Recursive determinant.\n\t4. Exit.\n\t> ";
		cin >> option;

		switch(option)
		{
			case 1:
				HeapSort_();
			break;

			case 2:
				iterativeDeterminant();
			break;

			case 3:
				recursiveDeterminant();
			break;

			case 4:
				exited = true;
				cout << "\nSuccesfully exited!" << endl;
			break;

			default:
				cout << "\nInvalid option. Try again!" << endl;
			break;
		}
	}

	return 0;
}