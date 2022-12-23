#include <iostream>
#include "A3_Task1_s13s14_20210376_20210244.h"
/**
 * @brief Main File
*/
using namespace std;

/**
 * @brief Main function of the program
 * @return int
*/
int main() {
	MAVector<int> v = { 1, 2, 3, 4, 5, 6 };
	MAVector<int>::iterator it = v.begin();

	it++; // Supports ++ operator
	it = it + 2;  // Supports + operator
	cout << *it << endl; // Supports * operator
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

