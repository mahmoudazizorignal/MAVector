#include "MAVector.h"



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

template <class T> MAVector<T>& MAVector<T>::operator=(const MAVector<T>& other)
{
	sz = other.sz;
	capacity = other.capacity;

	delete[] arr;
	arr = new T[capacity];
	for (int i = 0; i < sz; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

template <class T> MAVector<T>& MAVector<T>::operator=(MAVector<T>&& other) 
{
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

template <class T> T& MAVector<T>::operator[] (int k) 
{
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
		exit(-1);
	}
}

template <class T> T MAVector<T>::operator[] (int k) const 
{
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
		exit(-1);
	}
}

template <class T> int MAVector<T>::push_back(const T& Element) 
{
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

template <class T> T MAVector<T>::pop_back() 
{
	T Element = arr[sz - 1];
	arr[sz - 1] = T();
	sz--;

	return Element;
}

template <class T> void MAVector<T>::erase(T* iterator) 
{
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

template <class T> void MAVector<T>::erase(T* it1, T* it2) 
{
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
		exit(-1);
	}
}

template <class T> void MAVector<T>::clear() 
{
	for (int i = 0; i < sz; i++) {
		arr[i] = T();
	}
	sz = 0;
}

template <class T> void MAVector<T>::insert(T* it1, const T& Element) 
{
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
			int tmp = it1 - begin();
			delete[] arr;
			arr = newArr;
			newArr = NULL;
			sz++;
			it1 = begin() + tmp;
		}
	}
	catch (char ch) {
		cout << "Error Out Of Bounds\n";
		exit(-1);
	}
}

template <class T> T* MAVector<T>::begin() const 
{
	return arr;
}

template <class T> T* MAVector<T>::end() const 
{
	return arr + sz;
}

template <class T> int MAVector<T>::size() const 
{
	return sz;
}

template <class T> int MAVector<T>::Capacity() const 
{
	return capacity;
}

template <class T> bool MAVector<T>::empty() 
{
	return (sz == 0);
}


template <class T> void MAVector<T>::resize(int s) 
{

	capacity = max(s, 10);
	T* newarr = new T[capacity];

	for (int i = 0; i < sz; i++) {
		newarr[i] = arr[i];
	}

	delete[] arr;
	arr = newarr;
	newarr = nullptr;
	sz = s;
}

template<class T> bool MAVector<T>::operator==(const MAVector<T>& v2) 
{
	if (sz != v2.sz) return false;
	else {
		for (int i = 0; i < sz; i++) {
			if (arr[i] != v2.arr[i]) return false;
		}
	}

	return true;

}

template<class T> bool MAVector<T>::operator<(const MAVector<T>& v2) 
{

	if (v2.sz > sz) return true;
	else if (sz > v2.sz) return false;

	else {
		for (int i = 0; i < sz; i++) {
			if (arr[i] < v2.arr[i]) return true;
		}
	}

	return false;

}
template<typename U> ostream& operator<< (ostream& out, MAVector<U>& v)
{
	for (int i = 0; i < v.sz; i++) {
		out << v.arr[i] << " ";
	}

	return out;
}