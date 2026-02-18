#include <stdlib.h>
#include <stdio.h>

#include "Company.h"

Company::Company(int max_cars)
{
    this->max_cars = max_cars;
}

Company::~Company()
{

}

int Company::add_car(Car *car)
{
    if (cars.size() >= max_cars)
        return 0;
    cars.push_back(*car);
    return 1;
}

int Company::get_car(int index, Car** out)
{
    if (index >= cars.size())
        return 0;
    *out = &cars.at(index);
    return 1;
}

int Company::set_car(int index, Car* in)
{
    if (index >= cars.size())
        return 0;
    cars[index] = *in;
    return 1;
}

int Company::get_car_count()
{
    return cars.size();
}
