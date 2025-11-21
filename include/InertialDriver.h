/*
 * InertialDriver.h
 * ricevere le misure dal sensore (AKA produttore) e di fornirli a richiesta all’utilizzatore (AKA consumatore)
 */

#include "MyVector.h"
#include "Misura.h"
#include "Lettura.h"

class InertialDriver
{
    private:
        const int BUFFER_DIM = 100; // max misure
        MyVector<Misura> sens[BUFFER_DIM];

    public:
        InertialDriver();
        void push_back();
        Misura pop_front();
        void clear_buffer();
        Lettura get_reading(int index);
        std::ostream& operator<< (std::ostream& out);
};