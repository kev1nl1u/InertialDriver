#include "../include/MyVector.h"
template <typename T> MyVector<T> a (MyVector<T> b);
int main()  {
    
	MyVector<double> vec = MyVector<double>(5);
	
	std::cout << vec.getSize() << std::endl; //test del getter
	
	//test di overloading di []
	vec[0] = 100;
	std::cout << "vec[0]=" << vec[0] << std::endl;
	vec[2] = 20;
	std::cout << "vec[2]=" << vec[2] << std::endl;
	
	//test di reserve
	std::cout << "capacity =" << vec.getCapacity() << std::endl;
	vec.reserve(20);
	std::cout << "capacity =" << vec.getCapacity() << std::endl;
	
	//test di push_back e pop_back
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	std::cout << "vec[0]=" << vec.at(0) << std::endl;
	std::cout << "vec[2]=" << vec.at(2) << std::endl;
	std::cout << "vec.pop_back()=" << vec.pop_back() << std::endl;
	
	//testing del costruttore con initializer list
	MyVector<int> vec2 = {1, 2, 3, 4};
	std::cout << vec2 << std::endl;
	
	//test del costruttore di copia
	MyVector<int> vec3 = vec2;
	std::cout << "Costruttore di copia" << vec3 << std::endl;
	
	//test del costruttore di spostamento
	MyVector<int> vec4 = a(vec3);
	std::cout << "Costruttore di spostamento" << vec4 << std::endl;
	
	//test di assegnamento di copia
	MyVector<int> vec5 = MyVector<int>(4);
	vec5 = vec4;
	std::cout << "Assegnamento di copia" << vec5 << std::endl;
	
	//test di assegnamento di spostamento
	MyVector<int> vec6 = std::move(vec5);
	std::cout << "Assegnamento di spostamento" << vec6 << std::endl;

	return 0;
}

template <typename T> MyVector<T> a (MyVector<T> b){return b;}