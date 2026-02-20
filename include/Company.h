#include <vector>

#include "Car.h"

class Company
{
    public:
        Company(int max_cars);
        ~Company();

        int add_car(Car *car);
        int get_car(int index, Car** out);
        int set_car(int index, Car* in);
        int get_car_count();

    private:
        std::vector<Car> cars;
        int max_cars;
};