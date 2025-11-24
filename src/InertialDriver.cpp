#include <iostream>
#include "InertialDriver.h"
#include "MyVector.h"

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

int InertialDriver::get_reading(int misura_index) {
    // restituisce una lettura specifica da una misura specifica
    if(misura_index < 0 || misura_index >= BUFFER_DIM)
        throw std::out_of_range("Misura index out of bounds");
    return sens[misura_index];
}

std::ostream& InertialDriver::operator<<(std::ostream& out) {
    // stampa l'ultima misura
    int last_index = (index - 1 + BUFFER_DIM) % BUFFER_DIM; // index punta alla cella vuota
    out << "Ultima misura: " << sens[last_index] << std::endl; 
}

