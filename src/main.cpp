#include <stdio.h>

#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Company.h"
#include "Customer.h"

int main()
{
    Company company(1000);

    StandardCar standard_car(0);
    LuxuryCar luxury_car(0);
    char test_name[256], test_address[1024], test_tele[256];

    Car *test_car;

    Customer cussy((char*)"Bob Bussy", (char*)"1455 De Maisonneuve Blvd", (char*)"+67 069 420 1984");

    company.add_car(&standard_car);
    company.add_car(&luxury_car);

    company.get_car(1, &test_car);

    printf("Lux 1: %p\n", luxury_car.get_type());
    printf("Lux 2: %p\n", test_car->get_type());

    printf("Lux Type: %s!\n", luxury_car.get_type());
    printf("Stand Type: %s!\n", standard_car.get_type());
    
    cussy.customer_get_name(test_name, sizeof(test_name));
    cussy.customer_get_address(test_address, sizeof(test_address));
    cussy.customer_get_tele(test_tele, sizeof(test_tele));

    printf("Name: %s\n\tAddress: %s\n\tTele: %s\n", test_name, test_address, test_tele);

    return 0;
}
