#include "Car.h"

class StandardCar : public Car
{
    public:
        StandardCar(int is_available) : Car("Standard", is_available) {};
        ~StandardCar() = default;
        StandardCar(const StandardCar& cpy);
        StandardCar& operator=(const StandardCar& cpy);
};