#include <iostream>
#include "../include/InertialDriver.h"

using namespace std;

// inizializza il buffer delle misure
InertialDriver::InertialDriver() : sens(BUFFER_DIM) {
    head = 0; // punta a prossima cella da inserire
    tail = 0; // punta alla cella più vecchia
}

// aggiunge una misura al buffer circolare
void InertialDriver::push_back(const Misura& m){
    sens.at(head) = m; // inserisce la misura
    head = (head + 1) % BUFFER_DIM; // head punta alla prossima cella da inserire
    // [DEBUG]
    //cout << "added m, increased head = " << head << ", tail = " << tail << ", head == tail ? " << (head == tail) << endl;
    if(head == tail) tail = (tail + 1) % BUFFER_DIM;  // se il buffer è pieno, sposta tail
    // [DEBUG] stampa head (ultimo inserito) e tail (più vecchio)
    //cout << "checked head == tail, head = " << head << ", tail = " << tail << endl;
}

// rimuove e restituisce la misura più vecchia
Misura InertialDriver::pop_front(){
    if(tail == head) throw std::out_of_range("Buffer vuoto"); // buffer vuoto
    int index = tail < head ? tail : tail-1; // calcola l'indice della misura più vecchia
    tail = (tail + 1) % BUFFER_DIM; // sposta tail alla prossima misura (dato che tail è stato resettato)
    return sens.at(index);
}

// pulisce il buffer delle misure
void InertialDriver::clear_buffer(){
    sens = MyVector<Misura>(BUFFER_DIM); // reinizializza il vettore
    head = 0;
    tail = 0;
}

// restituisce una misura dal buffer
Misura InertialDriver::get_reading(int misura_index) {
    return sens.at(misura_index);
}

ostream& operator<<(std::ostream& out, const InertialDriver& driver) {
    if (driver.tail == driver.head) {
        out << "Buffer vuoto";
        return out;
    }
    int index_recente = (driver.head - 1 + InertialDriver::BUFFER_DIM) % InertialDriver::BUFFER_DIM;
    const Misura& m = driver.sens.at(index_recente);
    out << "Ultima misura (17 letture):" << m;
    return out;
}

