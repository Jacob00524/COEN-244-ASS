#pragma once
#include <vector>

#include "Car.h"
#include "Customer.h"

class Company
{
    public:
        Company(int max_cars);
        ~Company();

        int add_car(Car *car);
        int get_car(int index, Car** out);
        int set_car(int index, Car* in);
        int get_car_count();

        void add_customer(Customer *new_customer);
        int get_customer_count();
        int get_customer(int index, Customer **customer_out);

    private:
        std::vector<Customer> customers;
        std::vector<Car> cars;
        int max_cars;
};