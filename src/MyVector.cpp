#include "../include/MyVector.h"
template <typename T>


MyVector<T>::MyVector(){
	vec = new T[10];
	capacity = 10;
	size = 0;
}
MyVector<T>::MyVector(int s){
	vec = new T[s];
	size = 0;
	capacity = s;
}

MyVector<T>::MyVector(std::initializer_list<T> ls){
	size = ls.size();
	capacity = size;
	vec = new T[size];
	std::copy(ls.begin(), ls.end(), vec);
}

int MyVector<T>::getSize() const {return size;}
int MyVector<T>::getCapacity() const {return capacity;}
const T& MyVector<T>::operator[](int pos) const {return vec[pos];}
T& MyVector<T>::operator[](int pos){return vec[pos];}

T& MyVector<T>::at (int pos){
	if (pos < size && pos >= 0) {return vec[pos];}
	throw std::out_of_range("Index out of bounds");
}

const T& MyVector<T>::at (int pos) const{
	if(pos < size && pos >= 0) {return vec[pos];}
	throw std::out_of_range("Index out of bounds");
}

void MyVector<T>::reserve(int n) {
	if(n < capacity) {return;}
	capacity = n;
	double *newvec = new double[capacity];

	for(int i=0; i < size; i++){
		newvec[i] = vec[i];
	}
	vec = newvec;
	delete[] newvec;
}

void MyVector<T>::push_back(T el){
	vec[size] = el;
	size++;
	if(size==capacity) {reserve(capacity*2);}
}

T MyVector<T>::pop_back(){
	if(size == 0){ return 0; }	
	double el = vec[--size];
	vec[size] = 0;
	return el;
}


std::ostream& operator<< (std::ostream& out, const MyVector<T>& vec){
	out << "[";
	int sz = vec.getSize();
	for (int i = 0; i < sz-1; i++){
		out << vec[i] << ", ";
	}
	out << vec[sz-1] << "]";
	return out;
}
