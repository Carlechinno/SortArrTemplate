#pragma once

#include <iostream>
using namespace std;


template <class T>
class SortArr
{
private:
	T* arr;
	int size;
	void SortArray();


public:
	static int _amount;
	static int _lengthSum;
	SortArr();
	SortArr(T* arr, int size);
	SortArr(SortArr& other);
	~SortArr();
	void operator=(SortArr& other);
	bool operator==(SortArr& other);
	bool operator+=(T t);
	friend ostream& operator<<(ostream& os, const SortArr& other) {
		os << "{ ";
		for (int i = 0; i < other.size; i++) {
			os << other.arr[i] << " | ";
		}
		os << " }";
		os << endl;
		return os;
	}
	void print_Static(); 
	void print();
	int isSorted(T* arr, int size);
};

template<class T>
SortArr<T>::SortArr() {
	this->arr = nullptr;
	this->size = 0;
	this->_amount++;
	this->_lengthSum += this->size;
}

template<class T>
SortArr<T>::SortArr(T* arr, int size) {
	if (isSorted(arr, size) == 0) {
		this->size = 1;
		this->arr = new T[this->size];
		this->arr[0] = arr[0];
	}
	else {
		this->size = size;
		this->arr = new T[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}

	}
	this->_amount++;
	this->_lengthSum += this->size;

}

template<class T>
SortArr<T>::SortArr(SortArr& other) {
	this->size = other.size;

	this->arr = new T[other.size];
	for (int i = 0; i < other.size; i++) {
		this->arr[i] = other.arr[i];
	}
	this->_amount++;
	this->_lengthSum += this->size;

}



template<class T>
void SortArr<T>::operator=(SortArr& other) {
	this->size = other.size;

	this->arr = new T[other.size];
	for (int i = 0; i < other.size; i++) {
		this->arr[i] = other.arr[i];
	}
}

template<class T>
bool SortArr<T>::operator==(SortArr& other) {
	if (this->size != other.size) {
		return false;
	}
	int flag = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == other.arr[i]) {
			flag++;
		}
	}
	if (flag == this->size) {
		return true;
	}
	return false;
}

template<class T>
bool SortArr<T>::operator+=(T t) {
	int i;
	for (i = 0; i < this->size; i++) {
		if (this->arr[i] == t) {
			return false;
		}
	}
	T* temp = new T[this->size + 1];
	for (i = 0; i < this->size; i++) {
		temp[i] = this->arr[i];
	}
	temp[i] = t;
	delete[] this->arr;

	this->size += 1;
	this->arr = new T[this->size];
	for (i = 0; i < this->size; i++) {
		this->arr[i] = temp[i];
	}
	this->SortArray();

	delete[] temp;//deleting the temporary array we used//
	this->_lengthSum++;

	return true;
}

template<class T>
void SortArr<T>::SortArray() {
	for (int i = 0; i < this->size; i++) {
		for (int j = i + 1; j < this->size; j++) {
			if (this->arr[i] > this->arr[j]) {
				T temp = this->arr[i];
				this->arr[i] = this->arr[j];
				this->arr[j] = temp;
			}
		}
	}
}


template<class T>
int SortArr<T>::isSorted(T* arr, int size) {
	if (size == 1 || size == 0) {
		return 1;
	}
	if (arr[size - 1] <= arr[size - 2]) {
		return 0;
	}
	return isSorted(arr, size - 1);
}

template<class T>
SortArr<T>::~SortArr() {
	delete[] this->arr;
}

template<class T>
void SortArr<T>::print_Static() {
	cout << "There are--> " << this->_amount << " objects from this type" << endl;
	cout << "The sum of sizes of all the arrays from this type is--> " << this->_lengthSum << endl;
}


template<class T>
void SortArr<T>::print() {
	for (int i = 0; i < this->size; i++) {
		cout << this->arr[i] << " ";
	}
	cout << endl;
}
