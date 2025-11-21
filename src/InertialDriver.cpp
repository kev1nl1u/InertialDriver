#include <iostream>
#include "InertialDriver.h"
#include "MyVector.h"

using namespace std;

InertialDriver::InertialDriver(){
    // inizializza il buffer delle misure
    for(int i=0; i<BUFFER_DIM; i++) sens[i] = Misura();
}