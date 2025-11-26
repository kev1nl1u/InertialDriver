#include "../include/Misura.h"
#include "../include/Lettura.h"
#include <stdexcept>
#include <string>
#include <iostream>

Misura::Misura() {
    // inizializza le letture a 0
    for (int i = 0; i < 17; i++) sensori[i] = Lettura();
}
void Misura::setLettura(int index, const Lettura& lettura) {
    if (index >= 0 && index < 17) sensori[index] = lettura; // copia lettura in sensori[index]
    else throw std::out_of_range("Index" + std::to_string(index) + " out of bounds");
}
Lettura Misura::getLettura(int index) const {
    if (index >= 0 && index < 17) return sensori[index];
    throw std::out_of_range("Index" + std::to_string(index) + " out of bounds");
}


std::ostream& operator<<(std::ostream& out, const Misura& m) {
    for(int i=0; i<17; ++i) {
        Lettura l = m.sensori[i];
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


bool operator== (const Misura& a, const Misura& b){
    for (int i = 0; i < 17; i++)
    {
        if(!(a.sensori[i] == b.sensori[i])) {return false;}
    }
    return true;    
}