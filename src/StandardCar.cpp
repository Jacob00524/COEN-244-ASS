#include "StandardCar.h"

StandardCar::StandardCar(const StandardCar& cpy) : Car(cpy) { }
StandardCar& StandardCar::operator=(const StandardCar& cpy)
{
    if (this == &cpy)
        return *this;
    Car::operator=(cpy);
    return *this;
}