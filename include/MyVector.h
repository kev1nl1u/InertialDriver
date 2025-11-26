#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>

template <typename T>

class MyVector
{
private:
	T *vec {nullptr};
	int size {0};
	int capacity {0};
public:
	MyVector(int s); //costruttore di base
	MyVector(std::initializer_list<T> ls); //costruttore con initializer_list per permettere l'inizializzazione tramite {1, 2, ecc.}
	MyVector(const MyVector& copy); //costruttore di copia
	MyVector(MyVector&& move); //costruttore di spostamento
	~MyVector() {delete[] vec; size = 0; capacity = 0;} //distruttore


	int getSize() const; //getter di size
	int getCapacity() const; //getter di capacity
	const T& operator[](int pos) const; //ovverride dell'operatore [] in lettura
	T& operator[] (int pos); //ovverride dell'operatore [] in scrittura
	MyVector& operator=(const MyVector& copy); //assegnamento di copia
	MyVector& operator=(MyVector&& move); //assegnamento di spostamento

	const T& at(int pos) const; //metodo per accedere a un elemento con il controllo del size in lettura
	T& at(int pos); //metodo per accedere a un elemento con il controllo del size in scrittura
	void push_back(T val); //metodo per aggiungere un elemento in fondo al vettore
	T pop_back(); //metodo per rimuovere l'elemento in fondo del vettore
	void reserve(int n); //metodo per cambiare la capacità del vettore
};

template <typename T> std::ostream& operator<< (std::ostream& out, const MyVector<T>& vec); //override di << per permettere una scrittura rapida



#include "../src/MyVector.hpp"
#endif //MyVector_h