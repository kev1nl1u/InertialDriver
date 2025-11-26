/*
 * InertialDriver.h
 * ricevere le misure dal sensore (AKA produttore) e di fornirli a richiesta all’utilizzatore (AKA consumatore)
 */

#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "Misura.h"
#include "Lettura.h"
#include "MyVector.h"
#include <ostream>

class InertialDriver
{
    private:
        static const int BUFFER_DIM = 10; // max misure
        int head = 0; // indice punta alla testa del vettore
        int tail = 0; // indice punta alla coda del vettore
        MyVector<Misura> sens; //Vettore di Misura sens

    public:
        InertialDriver();
        void push_back(const Misura& m);
        Misura pop_front();
        void clear_buffer();
        Misura get_reading(int index);
        friend std::ostream& operator<<(std::ostream& out, const InertialDriver& drv);
};


#include "../src/InertialDriver.hpp"
#endif