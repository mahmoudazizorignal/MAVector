#ifndef MAVECTOR_H
#define MAVECTOR_H


#include <iostream>
#include <iterator>
#include <string>
#include <cmath>
#include <initializer_list>
#include <iterator>
/**
 * @brief MAVector Header File
*/
using namespace std;



/**
 * @brief MAVector class
 * @tparam T 
*/
template <class T>
class MAVector {
	private:
		/**
		 * @brief variable that hold the availble elements we can add without allocating new space
		*/
		int capacity;
		/**
		 * @brief variable that hold the number of elements in MAVector
		*/
		int sz;

		/**
		 * @brief dynamically alocating array in the heap that manages the MAVector's elements
		*/
		T* arr;

	public:
		/**
		 * @brief iterator to iterate over elements of MAVector
		*/
		typedef T* iterator;
		/**
		 * @brief default constructor
		*/
		MAVector();
		/**
		 * @brief parameterized constructor
		 * @param n size of MAVector
		*/
		MAVector(int n);
		/**
		 * @brief overloaded parameterized constructor
		 * @param a array of elements to put in MAVector
		 * @param n size of MAVector
		*/
		MAVector(T* a, int n);
		/**
		 * @brief copy constructor
		 * @param other 
		*/
		MAVector(const MAVector& other);
		/**
		 * @brief move constructor
		 * @param other 
		*/
		MAVector(MAVector&& other);
		/**
		 * @brief constructor that take a list of elements
		 * @param lst 
		*/
		MAVector(initializer_list<T> lst);
		/**
		 * @brief destructor
		*/
		~MAVector();
		/**
		 * @brief copy assignment operator
		 * @param other 
		 * @return 
		*/
		MAVector& operator=(const MAVector& other);
		/**
		 * @brief move assignment operator
		 * @param other 
		 * @return 
		*/
		MAVector& operator=(MAVector&& other);
		/**
		 * @brief overloaded [] operator that return a reference to the element in index k
		 * @param k 
		 * @return 
		*/
		T& operator[] (int k);
		/**
		 * @brief overloaded [] operator that return a copy version to the element in index k
		 * @param k 
		 * @return 
		*/
		T operator[] (int k) const;

		/**
		 * @brief function to push element to MAVector
		 * @param Element element to push
		 * @return int
		*/
		int push_back(const T& Element);
		/**
		 * @brief function to return and remove last element in the class
		 * @return the element that has been removed
		*/
		T pop_back();
		
		/**
		 * @brief erase some element by giving its address
		 * @param iterator address of the element
		*/
		void erase(T* iterator);
		/**
		 * @brief erase range of elements
		 * @param it1 the begin of the interval
		 * @param it2 the end of the interval
		*/
		void erase(T* it1, T* it2);

		/**
		 * @brief remove all elements in MAVector
		*/
		void clear();
		/**
		 * @brief insert some element in specific address
		 * @param it1 address to insert element in it
		 * @param Element element to insert
		*/
		void insert(T* it1, const T& Element);

		/**
		 * @brief return the address of the first element in MAVector
		 * @return iterator
		*/
		iterator begin() const;

		/**
		 * @brief return the address of the end of MAVector
		 * @return iterator
		*/
		iterator end() const;

		/**
		 * @brief function to return the size of MAVector
		 * @return int
		*/
		int size() const;

		/**
		 * @brief function to return the capacity of MAVecotr
		 * @return 
		*/
		int Capacity() const;

		/**
		 * @brief function to resize the MAVector with new and bigger allocated space memory
		 * @param s new size of MAVector
		*/
		void resize(int s);

		/**
		 * @brief check if MAVector is empty
		 * @return boolean value
		*/
		bool empty();

		/**
		 * @brief overloaded == operator
		 * @param  
		 * @return boolean value
		*/
		bool operator==(const MAVector<T>&);

		/**
		 * @brief overloaded < operator
		 * @param  
		 * @return boolean value
		*/
		bool operator< (const MAVector<T>&);

		/**
		 * @brief overloaded << operator to print the MAVector's items
		 * @param out 
		 * @param v 
		 * @return 
		*/
		template <typename U>
		friend ostream& operator<< (ostream& out, MAVector<U>& v);
};


#include "MAVector.cpp"
#endif