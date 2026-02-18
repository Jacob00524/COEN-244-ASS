#include <stdio.h>

#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Company.h"

int main()
{
    Company company(1000);

    StandardCar standard_car(0);
    LuxuryCar luxury_car(0);

    Car *test_car;

    company.add_car(&standard_car);
    company.add_car(&luxury_car);

    company.get_car(1, &test_car);

    printf("Lux 1: %p\n", luxury_car.get_type());
    printf("Lux 2: %p\n", test_car->get_type());

    printf("Lux Type: %s!\n", luxury_car.get_type());
    printf("Stand Type: %s!\n", standard_car.get_type());

    return 0;
}
