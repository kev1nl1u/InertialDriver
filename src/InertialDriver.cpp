#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/MyVector.h"

using namespace std;

InertialDriver::InertialDriver(){
    // inizializza il buffer delle misure
    for(int i=0; i<BUFFER_DIM; i++) sens[i] = Misura();
}

void InertialDriver::push_back(const Misura& m){
    // aggiunge una misura al buffer circolare
    sens[index] = m;
    index = (index + 1) % BUFFER_DIM;
}

Misura InertialDriver::pop_front(){
    // rimuove e restituisce la misura più vecchia
    int oldest_index = (index + 1) % BUFFER_DIM;
    Misura m = sens[oldest_index];
    sens[oldest_index] = Misura(); // resetta la misura
    return m;
}

void InertialDriver::clear_buffer(){
    // pulisce il buffer delle misure
    for(int i=0; i<BUFFER_DIM; i++) sens[i] = Misura();
    index = 0;
}

Misura InertialDriver::get_reading(int misura_index) {
    // restituisce una misura dal buffer
    if(misura_index < 0 || misura_index >= BUFFER_DIM)
        throw std::out_of_range("Misura index out of bounds");
    return sens[misura_index];
}

std::ostream& operator<<(std::ostream& out, const InertialDriver& driver) {
    if (driver.index == 0) {
        out << "Buffer vuoto";
        return out;
    }
    int last_index = (driver.index - 1 + InertialDriver::BUFFER_DIM) % InertialDriver::BUFFER_DIM;
    const Misura& m = driver.sens[last_index];
    out << "Ultima misura (17 letture):";
    for(int i=0; i<17; ++i) {
        Lettura l = m.getLettura(i);
        out << " [" << i
            << ": yaw_v=" << l.getYawV()
            << ", yaw_a=" << l.getYawA()
            << ", pitch_v=" << l.getPitchV()
            << ", pitch_a=" << l.getPitchA()
            << ", roll_v=" << l.getRollV()
            << ", roll_a=" << l.getRollA() << "]";
    }
    return out;
}

