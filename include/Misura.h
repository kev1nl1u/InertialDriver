/*
 * Misura.h
 * Rappresenta una misura composta da 17 letture
 */

#include "Lettura.h"

class Misura{
    private:
        Lettura sensori[17];
    public:
        Misura();
        void setLettura(int index, const Lettura& lettura);
        Lettura getLettura(int index) const;
};