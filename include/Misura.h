/*
 * Misura.h
 * Rappresenta una misura composta da 17 letture
 */

#ifndef MISURA_H
#define MISURA_H

#include "Lettura.h"
#include <iostream>

class Misura{
    private:
        Lettura sensori[17];
    public:
        Misura();
        void setLettura(int index, const Lettura& lettura);
        Lettura getLettura(int index) const;
        friend std::ostream& operator<<(std::ostream& out, const Misura& m);
        friend bool operator== (const Misura& a, const Misura& b);
};



#include "../src/Misura.hpp"
#endif