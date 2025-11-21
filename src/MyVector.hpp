#include "../include/MyVector.h"
//costruttore di base
template <typename T> MyVector<T>::MyVector(int s){
	vec = new T[s];
	size = 0;
	capacity = s;
}

//costruttore con initializer list
template <typename T> MyVector<T>::MyVector(std::initializer_list<T> ls) :  size{static_cast<int>(ls.size())}, capacity{static_cast<int>(ls.size())}, vec{new T[static_cast<int>(ls.size())]}{
	std::copy(ls.begin(), ls.end(), vec);
}

//costruttore di copia
template <typename T> MyVector<T>::MyVector(const MyVector& copy) : size{copy.getSize()}, capacity{copy.getCapacity()}, vec{new T[copy.getSize()]}
{
	std::copy(copy.vec, copy.vec+copy.getSize(), vec);
}

//costruttore di spostamento
template <typename T> MyVector<T>::MyVector(MyVector&& move) : size{move.getSize()}, capacity{move.getCapacity()}{
	vec = move.vec;
	move.vec = nullptr;
	move.size = 0;
	move.capacity = 0;
}

//getter del size
template <typename T> int MyVector<T>::getSize() const {return size;}

//getter di capacity
template <typename T> int MyVector<T>::getCapacity() const {return capacity;}

//overloading gell'operatore [] sia in lettura che in scrittura
template <typename T> const T& MyVector<T>::operator[](int pos) const {return vec[pos];}
template <typename T> T& MyVector<T>::operator[](int pos){return vec[pos];}

//overloading dell'operatore = per permettere la copia di due vector ----- assegnamento di copia
template <typename T> MyVector<T>& MyVector<T>::operator=(const MyVector& copy){
	T* temp = new T[copy.getSize()];
	std::copy(copy.vec, copy.vec+copy.getSize(), temp);
	delete[] vec;
	vec = temp;
	size = copy.getSize();
	capacity = copy.getCapacity();
	return *this;
}

//overloading dell'operatore = per permettere lo spostamento di due vector ----- assegnamento di spostamento
template <typename T> MyVector<T>& MyVector<T>::operator=(MyVector&& move){
	delete[] vec;
	vec = move.vec;
	size = move.size;
	capacity = move.capacity;
	move.size = 0;
	move.capacity = 0;
	move.vec = nullptr;
	return *this;
}

//metodo che ritorna l'elemento a posizione pos del vettore sia in lettura che in scrittura
template <typename T> T& MyVector<T>::at (int pos){
	if (pos < size && pos >= 0) {return vec[pos];}
	throw std::out_of_range("Index out of bounds");
}
template <typename T> const T& MyVector<T>::at (int pos) const{
	if(pos < size && pos >= 0) {return vec[pos];}
	throw std::out_of_range("Index out of bounds");
}
//metodo che cambia la capacità allocando un array di dimensioni maggiore e copiando gli elementi (possibile utilizzo di std::copy invece che del ciclo for)
template <typename T> void MyVector<T>::reserve(int n) {
	if(n < capacity) {return;}
	capacity = n;
	double *newvec = new double[capacity];

	for(int i=0; i < size; i++){
		newvec[i] = vec[i];
	}
	vec = newvec;
	delete[] newvec;
}

//metodo che aggiunge un elemento alla coda del vettore
template <typename T> void MyVector<T>::push_back(T el){
	vec[size] = el;
	size++;
	if(size==capacity) {reserve(capacity*2);}
}
//metodo che rimuove l'ultimo elemento dal vettore
template <typename T> T MyVector<T>::pop_back(){
	if(size == 0){ return 0; }	
	double el = vec[--size];
	vec[size] = 0;
	return el;
}

//overloading dell'operatore << per permettere la lettura rapida di un vettore
template <typename T> std::ostream& operator<< (std::ostream& out, const MyVector<T>& vec){
	out << "[";
	int sz = vec.getSize();
	for (int i = 0; i < sz-1; i++){
		out << vec[i] << ", ";
	}
	out << vec[sz-1] << "]";
	return out;
}
