#include "../include/InertialDriver.h"
#include <iostream>

using namespace std;

Misura genera(int add){
    Misura misura;
    for (int i = 0; i < 17; i++)
    {
        add += i;
        misura.setLettura(i, Lettura(add+0.5, add+1+0.5, add+2+0.5, add+3+0.5, add+4+0.5, add+5+0.5));
    }
    
    return misura;
}

int main(){
    int err = 0;

    InertialDriver driver = InertialDriver();

    // print buffer vuoto 
    cout << driver << endl;

    try{
        driver.pop_front(); // pop da buffer vuoto
        cout << "FAILED pop front from empty buffer" << endl;
        err++;
    } catch(...){
        cout << "success pop OFR Exception from empty buffer" << endl;
    }

    Misura m0 = genera(0);
    Misura m1 = genera(10);
    Misura m2 = genera(20);
    Misura m3 = genera(30);
    Misura m4 = genera(40);
    Misura m5 = genera(50);
    Misura m6 = genera(60);
    Misura m7 = genera(70);
    Misura m8 = genera(80);
    Misura m9 = genera(90);
    
    driver.push_back(m0);
    cout << endl << endl;
    cout << "[16] YawA: " << m0.getLettura(16).getYawA() << endl; // YawA dell'ultima misura (YawA dell'elemento 16 al cout driver dev'essere uguale)
    cout << driver << endl; // print ultima misura m0
    cout << endl << endl;

    Misura d = driver.pop_front();
    if(d == m0) cout << "success pop front m0" << endl;
    else{
        err++;
        cout << "FAILED pop front m0" << endl;
        cout << "expected: " << m0 << endl << endl << "got: " << d << endl << endl << endl;
    }

    // prova pop ancora --> head == tail --> out of range
    try{
        driver.pop_front(); // pop da buffer vuoto
        cout << "FAILED pop front from empty buffer" << endl;
        err++;
    } catch(...){
        cout << "success pop OFR Exception from empty buffer" << endl;
    }

    /*
     * pulisci buffer per azzerare head e tail,
     * altrimenti head rimane a 1 dopo il pop front sopra e i prossimi test sarebbero da cambiare (aumentare index di 1)
     * TRACE: dopo il pop front sopra, head = 1, tail = 1
    */
    driver.clear_buffer();

    driver.push_back(m0);
    driver.push_back(m1);
    driver.push_back(m2);
    driver.push_back(m3);
    driver.push_back(m4);
    driver.push_back(m5);
    driver.push_back(m6);
    driver.push_back(m7);
    driver.push_back(m8);
    driver.push_back(m9); // pieno
    
    cout << endl << endl;
    cout << "[5] PitchV: " << m9.getLettura(5).getPitchV() << endl; // PitchV dell'ultima misura (PitchV dell'elemento 5 al cout driver dev'essere uguale)
    cout << driver << endl;
    cout << endl << endl;

    Misura a = driver.pop_front();
    if(a == m0) cout << "success pop front m0" << endl;
    else{
        err++;
        cout << "FAILED pop front m0" << endl;
    }
    if(driver.get_reading(2) == m2) cout << "success read m2 at 2" << endl;
    else{
        err++;
        cout << "FAILED read m2 at 2" << endl;
    }
    if(driver.get_reading(9) == m9) cout << "success read m9 at 9" << endl;
    else{
        err++;
        cout << "FAILED read m9 at 9" << endl;
    }

    Misura m10 = genera(100);
    Misura m11 = genera(110);
    driver.push_back(m10); // sovrascrive m0 con m10
    driver.push_back(m11); // sovrascrive m1 con m11

    cout << endl << endl;
    cout << "[0] YawV: " << m11.getLettura(0).getYawV() << endl; // YawV dell'ultima misura (YawV dell'elemento 0 al cout driver dev'essere uguale)
    cout << driver << endl;
    cout << endl << endl;

    Misura b = driver.pop_front();
    if(b == m2) cout << "success popfront m2" << endl;
    else{
        err++;
        cout << "FAILED popfront m2" << endl;
    }
    if(driver.get_reading(0) == m10) cout << "success read m10 at 0 (overriden)" << endl;
    else{
        err++;
        cout << "FAILED read m10 at 0 (overriden)" << endl;
    }

    driver.clear_buffer();
    if(driver.get_reading(0) == Misura()) cout << "success clear buffer" << endl;
    else{
        err++;
        cout << "FAILED clear buffer" << endl;
    }

    /***************************/
    /* Reinizializza il buffer */
    /***************************/
    driver.clear_buffer();
    driver.push_back(m0);
    // test pop_front con 1 solo elemento - test tail e head reset
    Misura c = driver.pop_front();
    if(c == m0) cout << "success popfront m0 single element" << endl;
    else{
        err++;
        cout << "FAILED popfront m0 single element" << endl;
    }

    if (err == 0) cout << "All tests passed!" << endl;
    else cerr << err << " tests failed!" << endl;
    

    return 0;
}