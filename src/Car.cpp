#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Car.h"

int g_id = 0;

Car::Car(const char *type, int availability)
{
    if (!type)
        return;
    car_id = g_id++;
    car_available = availability;
    car_type = NULL;
    set_type(type);
}

Car::~Car()
{
    car_id = 0;
    car_available = 1;
    if (car_type)
        free(car_type);
}

Car::Car(const Car& cpy)
{
    this->car_id = cpy.car_id;
    this->car_available = cpy.car_available;
    if (cpy.car_type)
        this->car_type = strdup(cpy.car_type);
}

Car& Car::operator=(const Car& cpy)
{
    if (this == &cpy)
        return *this;
    this->car_id = cpy.car_id;
    this->car_available = cpy.car_available;
    if (this->car_type)
        free(this->car_type);
    this->car_type = strdup(cpy.car_type);
    return *this;
}

int Car::get_id()
{
    return car_id;
}

char *Car::get_type()
{
    return car_type;
}

int Car::is_available()
{
    return car_available;
}

void Car::set_id(int id)
{
    car_id = id;
}

void Car::set_type(const char *type)
{
    if (!type)
        return;

    if (!car_type)
        car_type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
    else if (strlen(type) > strlen(car_type))
        car_type = (char*)realloc(car_type, sizeof(char) * (strlen(type) + 1));
    snprintf(car_type, strlen(type) + 1, "%s", type);
}

void Car::set_available(int availability)
{
    car_available = availability;
}

void Car::print_car()
{
    printf("ID: %d\tType: %s\t%s\n", car_id, car_type, car_available ? "available" : "not available");
}
