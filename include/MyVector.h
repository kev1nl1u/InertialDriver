#include <iostream>
#include <initializer_list>
#include <string>

template <typename T>

class MyVector
{
private:
	T *vec {nullptr};
	int size {0};
	int capacity {0};
public:
	MyVector();
	MyVector(int s);
	MyVector(std::initializer_list<double> ls);
	~MyVector() {delete[] vec;}


	int getSize() const;
	int getCapacity() const;
	const T& operator[](int pos) const;
	T& operator[] (int pos);

	const T& at(int pos) const;
	T& at(int pos);
	void push_back(T val);
	T pop_back();
	void reserve(int n);
};

std::ostream& operator<< (std::ostream& out, const MyVector& vec);
