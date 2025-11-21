#include "Misura.h"

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