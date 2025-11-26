#include <iostream>
#include "../include/Misura.h"
#include "../include/Lettura.h"

using namespace std;

int test(){
    int err = 0;
    Misura m1; // default --> tutte le letture a 0
    for(int i=0; i<17; i++){
        Lettura l = m1.getLettura(i);
        if(l.getYawV() != 0 || l.getYawA() != 0 || l.getPitchV() != 0 ||
           l.getPitchA() != 0 || l.getRollV() != 0 || l.getRollA() != 0){
            cout << "Lettura in posizione " << i << " non è tutta a 0" << endl;
            err++;
        }
    }
    Lettura l2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    m1.setLettura(5, l2); // setta la lettura in posizione 5 a l2;
    if(m1.getLettura(5).getYawV() != 1.0 ||
       m1.getLettura(5).getYawA() != 2.0 ||
       m1.getLettura(5).getPitchV() != 3.0 ||
       m1.getLettura(5).getPitchA() != 4.0 ||
       m1.getLettura(5).getRollV() != 5.0 ||
       m1.getLettura(5).getRollA() != 6.0){
        cout << "Lettura in posizione 5 non corrisponde a l2" << endl;
        err++;
    }

    return err;
}

int main() {
    int err = test();
    if(err == 0) cout << "Tutti i test sono passati!" << endl;
    else  cerr << err << " test sono falliti." << endl;
    return 0;
}