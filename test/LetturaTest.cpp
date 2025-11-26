/* TEST Lettura.h */

#include "../include/Lettura.h"
#include <iostream>

using namespace std;

int test(){
    int err = 0;
    Lettura l1; // default --> tutto a 0
    if(l1.getYawV() != 0){
        cout << "YawV (" << l1.getYawV() << ") non è 0" << endl;
        err++;
    }
    if(l1.getYawA() != 0){
        cout << "YawA (" << l1.getYawA() << ") non è 0" << endl;
        err++;
    }
    if(l1.getPitchV() != 0){
        cout << "PitchV (" << l1.getPitchV() << ") non è 0" << endl;
        err++;
    }
    if(l1.getPitchA() != 0){
        cout << "PitchA (" << l1.getPitchA() << ") non è 0" << endl;
        err++;
    }
    if(l1.getRollV() != 0){
        cout << "RollV (" << l1.getRollV() << ") non è 0" << endl;
        err++;
    }
    if(l1.getRollA() != 0){
        cout << "RollA (" << l1.getRollA() << ") non è 0" << endl;
        err++;
    }
    
    Lettura l2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    if(l2.getYawV() != 1.0){
        cout << "YawV (" << l2.getYawV() << ") non è 1.0" << endl;
        err++;
    }
    if(l2.getYawA() != 2.0){
        cout << "YawA (" << l2.getYawA() << ") non è 2.0" << endl;
        err++;
    }
    if(l2.getPitchV() != 3.0){
        cout << "PitchV (" << l2.getPitchV() << ") non è 3.0" << endl;
        err++;
    }
    if(l2.getPitchA() != 4.0){
        cout << "PitchA (" << l2.getPitchA() << ") non è 4.0" << endl;
        err++;
    }
    if(l2.getRollV() != 5.0){
        cout << "RollV (" << l2.getRollV() << ") non è 5.0" << endl;
        err++;
    }
    if(l2.getRollA() != 6.00){   
        cout << "RollA (" << l2.getRollA() << ") non è 6.0" << endl;
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