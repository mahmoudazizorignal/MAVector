#ifndef A3_TASK1_S13S14_20210376_20210244_H
#define A3_TASK1_S13S14_20210376_20210244_H


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
};


template <class T> MAVector<T>::MAVector() : sz(0), capacity(10) {
	arr = new T[capacity];
}
template <class T> MAVector<T>::MAVector(int n)
	: sz(n), capacity(max(10, n))
{
	arr = new T[capacity];
}
template <class T> MAVector<T>::MAVector(T* a, int n)
	: sz(n), capacity(max(10, n))
{
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = a[i];
	}
}
template <class T> MAVector<T>::MAVector(const MAVector& other)
	: sz(other.sz), capacity(other.capacity)
{
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = other.arr[i];
	}
}
template <class T> MAVector<T>::MAVector(MAVector&& other)
	: sz(other.sz), capacity(other.capacity)
{
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = other.arr[i];
	}
	delete[] other.arr;
}
template <class T> MAVector<T>::~MAVector() {
	delete[] arr;
}

template <class T> MAVector<T>::MAVector(initializer_list<T> lst)
	: sz(lst.size()), capacity(lst.size())
{
	arr = new T[sz];
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		arr[it - lst.begin()] = *it;
	}
}

template <class T>
MAVector<T>& MAVector<T>::operator=(const MAVector<T>& other) {
	sz = other.sz;
	capacity = other.capacity;

	delete[] arr;
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
MAVector<T>& MAVector<T>::operator=(MAVector<T>&& other) {
	sz = other.sz;
	capacity = other.capacity;

	delete[] arr;
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = other.arr[i];
	}
	delete[] other.arr;
	return *this;
}

template <class T>
T& MAVector<T>::operator[] (int k) {
	try {
		if (k < 0 || k >= sz) {
			throw k;
		}
		else {
			return arr[k];
		}
	}
	catch (int k) {
		cout << "Error Out Of Bound!" << endl;
		MAVector::~MAVector();
		exit(-1);
	}
}

template <class T>
T MAVector<T>::operator[] (int k) const {
	try {
		if (k < 0 || k >= sz) {
			throw k;
		}
		else {
			return arr[k];
		}
	}
	catch (int k) {
		cout << "Error Out Of Bound!" << endl;
		MAVector::~MAVector();
		exit(-1);
	}
}

template <class T>
int MAVector<T>::push_back(const T& Element) {
	if (sz == capacity) {
		capacity *= 2;

		T* newArr = new T[capacity];
		for (int i = 0; i < sz; i++) {
			newArr[i] = arr[i];
		}
		newArr[sz++] = Element;

		delete[] arr;
		arr = newArr;
		newArr = NULL;
	}
	else {
		arr[sz++] = Element;
	}
	return sz;
}

template <class T>
T MAVector<T>::pop_back() {
	T Element = arr[sz - 1];
	arr[sz - 1] = T();
	sz--;

	return Element;
}

template <class T>
void MAVector<T>::erase(T* iterator) {
	try {
		if (iterator - arr < 0 || iterator - arr >= sz) {
			throw 'e';
		}
		else {
			T* newArr = new T[capacity - 1];
			for (auto it = begin(); it < iterator; it++) {
				newArr[it - arr] = *it;
			}
			for (auto it = iterator + 1; it < end(); it++)
			{
				newArr[it - arr - 1] = *it;
			}

			delete[] arr;
			arr = newArr;
			sz--;
			capacity--;

			newArr = NULL;
		}
	}
	catch (char ch) {
		cout << "Error Out Of Bounds\n";
		exit(-1);
	}
}

template <class T>
void MAVector<T>::erase(T* it1, T* it2) {
	try {
		if (it1 - arr < 0 || it1 - arr >= sz) throw 'e';
		else if (it2 - arr < 0 || it2 - arr > sz) throw 'e';
		else if (it2 - arr < it1 - arr) throw 'e';
		else {
			T* newArr = new T[capacity - (it2 - it1)];
			for (auto it = begin(); it < it1; it++) {
				newArr[it - begin()] = arr[it - begin()];
			}
			for (auto it = it2; it < end(); it++) {
				newArr[it - begin() - (it2 - it1)] = arr[it - begin()];
			}

			delete[] arr;
			arr = newArr;
			sz -= (it2 - it1);
			capacity -= (it2 - it1);
			newArr = NULL;
		}
	}
	catch (char ch) {
		cout << "Error Out Of Bounds\n";
	}
}

template <class T>
void MAVector<T>::clear() {
	for (int i = 0; i < sz; i++) {
		arr[i] = T();
	}
	sz = 0;
}

template <class T>
void MAVector<T>::insert(T* it1, const T& Element) {
	try {
		if (it1 - arr > sz || it1 - arr < 0) throw 'e';
		else if (it1 - arr == sz) push_back(Element);
		else {
			if (sz == capacity) capacity *= 2;

			T* newArr = new T[capacity];
			for (auto it = begin(); it < it1; it++) {
				newArr[it - begin()] = arr[it - begin()];
			}
			newArr[it1 - begin()] = Element;
			for (auto it = it1; it < end(); it++) {
				newArr[it - begin() + 1] = arr[it - begin()];
			}

			delete[] arr;
			arr = newArr;
			newArr = NULL;
			sz++;
		}
	}
	catch (char ch) {
		cout << "Error Out Of Bounds\n";
		exit(-1);
	}
}

template <class T>
T* MAVector<T>::begin() const {
	return arr;
}

template <class T>
T* MAVector<T>::end() const {
	return arr + sz;
}

template <class T>
int MAVector<T>::size() const {
	return sz;
}

template <class T>
int MAVector<T>::Capacity() const {
	return capacity;
}


#endif