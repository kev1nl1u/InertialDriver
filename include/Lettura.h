/*
 * Lettura.h
 * Lettura di un sensore inerziale che fornisce 6 valori di tipo double
 */

class Lettura{
    private:
        double yaw_v;
        double yaw_a;
        double pitch_v;
        double pitch_a;
        double roll_v;
        double roll_a;
    public:
        Lettura();
        Lettura(double yv, double ya, double pv, double pa, double rv, double ra);
        double getYawV() const;
        double getYawA() const;
        double getPitchV() const;
        double getPitchA() const;
        double getRollV() const;
        double getRollA() const;
};