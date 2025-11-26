/*
 * InertialDriver.h
 * ricevere le misure dal sensore (AKA produttore) e di fornirli a richiesta all’utilizzatore (AKA consumatore)
 */

#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "Misura.h"
#include "Lettura.h"
#include <ostream>

class InertialDriver
{
    private:
        static const int BUFFER_DIM = 10; // max misure
        int index = 0; // indice punta alla prossima posizione da scrivere
    Misura sens[BUFFER_DIM];

    public:
        InertialDriver();
        void push_back(const Misura& m);
        Misura pop_front();
        void clear_buffer();
    Misura get_reading(int index);
        friend std::ostream& operator<<(std::ostream& out, const InertialDriver& drv);
};

#endif