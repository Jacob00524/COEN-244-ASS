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

/*
    THIS HAS TO BE REDONE!
    Do not simply copy contents of new_customer into customers
    The memory address of the strings should be different. Memory should be "owned" by the customers array 
*/
void Company::add_customer(Customer *new_customer)
{
    Customer c(NULL, NULL, NULL);
    customers.push_back(c);
    customers.at(customers.size() - 1) = *new_customer;
}

int Company::get_customer_count()
{
    return customers.size();
}

int Company::get_customer(int index, Customer **customer_out)
{
    if (index >= customers.size())
        return 0;
    *customer_out = &customers.at(index);
    return 1;
}

std::vector<Customer> get_customers_full()
{
    return customers;
}