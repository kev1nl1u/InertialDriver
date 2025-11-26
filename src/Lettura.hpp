#include "../include/Lettura.h"

Lettura::Lettura()
    : yaw_v(0), yaw_a(0), pitch_v(0), pitch_a(0), roll_v(0), roll_a(0) {}
Lettura::Lettura(double yv, double ya, double pv, double pa, double rv, double ra)
    : yaw_v(yv), yaw_a(ya), pitch_v(pv), pitch_a(pa), roll_v(rv), roll_a(ra) {}

double Lettura::getYawV() const { return yaw_v; }
double Lettura::getYawA() const { return yaw_a; }
double Lettura::getPitchV() const { return pitch_v; }
double Lettura::getPitchA() const { return pitch_a; }
double Lettura::getRollV() const { return roll_v; }
double Lettura::getRollA() const { return roll_a; }

bool operator== (const Lettura& a, const Lettura& b){
    if(a.pitch_a == b.pitch_a && a.pitch_v == b.pitch_v
       && a.roll_a == b.roll_a && a.roll_v == b.roll_v
       && a.yaw_a == b.yaw_a && a.yaw_v == b.yaw_v) {return true;}
    
    return false;
}