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

    Car *test_car, *test_car_2;

    Customer cussy((char*)"Bob Bussy", (char*)"1455 De Maisonneuve Blvd", (char*)"+67 069 420 1984"), *test_customer;

    /* Test cars */
    company.add_car(&standard_car);
    company.add_car(&luxury_car);

    company.get_car(1, &test_car);

    printf("Lux 1: %p\n", luxury_car.get_type());
    printf("Lux 2: %p\n", test_car->get_type());

    printf("Lux Type: %s!\n", luxury_car.get_type());
    printf("Stand Type: %s!\n", standard_car.get_type());
    
    /* Test customers */
    cussy.customer_get_name(test_name, sizeof(test_name));
    cussy.customer_get_address(test_address, sizeof(test_address));
    cussy.customer_get_tele(test_tele, sizeof(test_tele));
    cussy.customer_assign_car(test_car->get_id());

    printf("Name: %s\n\tAddress: %s\n\tTele: %s\n\tRented Cars: %d\n", test_name, test_address, test_tele, cussy.customer_get_car_count());
    company.get_car(cussy.customer_get_car_id(0), &test_car_2);

    printf("\tCar Type[0]: %s!\n", test_car_2->get_type());
    printf("\tCar ID[0]: %d!\n", test_car_2->get_id());

    /* Test company customers */
    company.add_customer(&cussy);
    printf("Company customers count: %d\n", company.get_customer_count());
    
    company.get_customer(0, &test_customer);
    test_customer->customer_get_name(test_name, sizeof(test_name));
    test_customer->customer_get_address(test_address, sizeof(test_address));
    test_customer->customer_get_tele(test_tele, sizeof(test_tele));
    test_customer->customer_assign_car(test_car->get_id());
    printf("Name: %s\n\tAddress: %s\n\tTele: %s\n\tRented Cars: %d\n", test_name, test_address, test_tele, test_customer->customer_get_car_count());

    return 0;
}
