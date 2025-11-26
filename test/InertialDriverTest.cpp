#include "../include/InertialDriver.h"
#include <iostream>

using namespace std;

Misura genera(int add){
    Misura misura;
    for (int i = 0; i < 17; i++)
    {
        add += i;
        misura.setLettura(i, Lettura(add+0.5, add+1+0.5, add+2+0.5, add+3+0.5, add+4+0.5, add+5+0.5));
    }
    
    return misura;
}

int main(){
    int err = 0;
    Misura m0 = genera(0);
    Misura m1 = genera(10);
    Misura m2 = genera(20);
    Misura m3 = genera(30);
    Misura m4 = genera(40);
    Misura m5 = genera(50);
    Misura m6 = genera(60);
    Misura m7 = genera(70);
    Misura m8 = genera(80);
    Misura m9 = genera(90);
    //cout << m <<endl;
    InertialDriver driver = InertialDriver();
    driver.push_back(m0);
    driver.push_back(m1);
    driver.push_back(m2);
    driver.push_back(m3);
    driver.push_back(m4);
    driver.push_back(m5);
    driver.push_back(m6);
    driver.push_back(m7);
    driver.push_back(m8);
    driver.push_back(m9); // pieno

    Misura a = driver.pop_front();
    if(a == m0) cout << "success pop front m0" << endl;
    if(driver.get_reading(2) == m2) cout << "success read m2 at 2" << endl;
    if(driver.get_reading(9) == m9) cout << "success read m9 at 9" << endl;

    Misura m10 = genera(100);
    Misura m11 = genera(110);
    driver.push_back(m10); // sovrascrive m0 con m10
    driver.push_back(m11); // sovrascrive m1 con m11

    Misura b = driver.pop_front();
    if(b == m2) cout << "success popfront m2" << endl;
    if(driver.get_reading(0) == m10) cout << "success read m10 at 0 (overriden)" << endl;
    

    return 0;
}