#pragma once
#include <iostream>
using namespace std;

template <class T>
class TVector {
private:
	int n;
	T* arr;
public:
	TVector(int _n = 3);
	~TVector();
	TVector(const TVector& v);

	int get_size() const;
	void resize(int _n);

	void push_back(const T& el);

	TVector& operator=(const TVector& v);
	T& operator[](int i);

	friend istream& operator>>(istream& is, TVector<T>& v) {
		for (int i = 0; i < v.n; i++) {
			is >> v.arr[i];
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const TVector<T>& v) {
		os << '(';
		for (int i = 0; i < v.n - 1; i++)
		{
			os << v.arr[i] << ", ";
		}
		os << v.arr[v.n - 1] << ')';
		return os;
	}
};

template <class T>
TVector<T>::TVector(int _n) {
	if (_n > 0) {
		n = _n;
		arr = new T[n];
		/*
		for (int i = 0; i < n; i++) {
			arr[i] = NULL;
		}
		*/
	}
	else {
		cout << "Non-positive value\n";
	}
}

template <class T>
TVector<T>::~TVector()
{
	delete[] arr;
}

template <class T>
TVector<T>::TVector(const TVector& v) {
	n = v.n;
	arr = new T[v.n];
	for (int i = 0; i < n; i++) {
		arr[i] = v.arr[i];
	}
}

template <class T>
int TVector<T>::get_size() const
{
	return n;
}

template <class T>
void TVector<T>::resize(int _n)
{
	if (_n == n) {
		return;
	}

	T* new_arr = new T[_n];
	/*
	for (int i = 0; i < _n; i++) {
		new_arr[i] = NULL;
	}
	*/

	if (_n > n) {
		for (int i = 0; i < n; i++) {
			new_arr[i] = arr[i];
		}
	}
	else {
		for (int i = 0; i < _n; i++) {
			new_arr[i] = arr[i];
		}
	}

	delete[] arr;
	arr = new_arr;
	n = _n;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& v) {
	if (this == &v) {
		return *this;
	}
	if (v.n != n) {
		delete[] arr;
		n = v.n;
		arr = new T[n];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = v.arr[i];
	}
	return *this;
}

template <class T>
T& TVector<T>::operator[](int i) {
	if (i >= 0 && i < n) {
		return arr[i];
	}
	else {
		cout << "Warning index\n";
	}
}

template <class T>
void TVector<T>::push_back(const T& el) {
	int new_n = n + 1;
	T* new_arr = new T[new_n];
	/*
	for (int i = 0; i < new_n; i++) {
		new_arr[i] = NULL;
	}
	*/
	for (int i = 0; i < n; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[n] = el;

	delete[] arr;
	arr = new_arr;
	n = new_n;
}