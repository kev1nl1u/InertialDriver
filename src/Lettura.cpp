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