#include "LuxuryCar.h"

LuxuryCar::LuxuryCar(const LuxuryCar& cpy) : Car(cpy) { }
LuxuryCar& LuxuryCar::operator=(const LuxuryCar& cpy)
{
    if (this == &cpy)
        return *this;
    Car::operator=(cpy);
    return *this;
}