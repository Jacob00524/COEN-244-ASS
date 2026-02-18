#include "Car.h"

class LuxuryCar : public Car
{
    public: 
        LuxuryCar(int is_available) : Car("Luxury", is_available) {};
        ~LuxuryCar() = default;
        LuxuryCar(const LuxuryCar& cpy);
        LuxuryCar& operator=(const LuxuryCar& cpy);
};