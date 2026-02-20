#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Customer.h"

int global_customer_id = 0;

/*
    Impose length limits on strings for saftey
*/
Customer::Customer(char *name, char *address, char *tele)
{
    customer_name = NULL;
    customer_address = NULL;
    customer_tele = NULL;
    cars_rented = NULL;

    customer_id = global_customer_id++;
    cars_rented_count = 0;

    if (name && strlen(name) <= 255)
    {
        customer_name = (char*)calloc(strlen(name) + 1, sizeof(char));
        memcpy(customer_name, name, strlen(name));
    }
    if (address && strlen(address) <= 1024)
    {
        customer_address = (char*)calloc(strlen(address) + 1, sizeof(char));
        memcpy(customer_address, address, strlen(address));
    }
    if (tele && strlen(tele) <= 255)
    {
        customer_tele = (char*)calloc(strlen(tele) + 1, sizeof(char));
        memcpy(customer_tele, tele, strlen(tele));
    }
}

Customer::~Customer()
{
    if (customer_name)
        free(customer_name);
    if (customer_address)
        free(customer_address);
    if (customer_tele)
        free(customer_tele);
    if (cars_rented)
        free(cars_rented);
}

int Customer::customer_set_name(char *new_name)
{
    if (!new_name || strlen(new_name) > 255)
        return 0;
    if (!customer_name)
        customer_name = (char*)calloc(strlen(new_name) + 1, sizeof(char));
    else if (strlen(customer_name) != strlen(new_name))
        customer_name = (char*)realloc(customer_name, sizeof(char) * (strlen(new_name) + 1));
    memcpy(customer_name, new_name, strlen(new_name));
    return 1;
}

int Customer::customer_set_tele(char *new_tele)
{
    if (!new_tele || strlen(new_tele) > 255)
        return 0;
    if (!customer_tele)
        customer_tele = (char*)calloc(strlen(new_tele) + 1, sizeof(char));
    else if (strlen(customer_tele) != strlen(new_tele))
        customer_tele = (char*)realloc(customer_tele, sizeof(char) * (strlen(new_tele) + 1));
    memcpy(customer_tele, new_tele, strlen(new_tele));
    return 1;
}

int Customer::customer_set_address(char *new_address)
{
    if (!new_address || strlen(new_address) > 255)
        return 0;
    if (!customer_address)
        customer_address = (char*)calloc(strlen(new_address) + 1, sizeof(char));
    else if (strlen(customer_address) != strlen(new_address))
        customer_address = (char*)realloc(customer_address, sizeof(char) * (strlen(new_address) + 1));
    memcpy(customer_address, new_address, strlen(new_address));
    return 1;
}

void Customer::customer_get_name(char *name_out, int buff_size)
{
    snprintf(name_out, buff_size, "%s", customer_name);
}

void Customer::customer_get_tele(char *tele_out, int buff_size)
{
    snprintf(tele_out, buff_size, "%s", customer_tele);
}

void Customer::customer_get_address(char *address_out, int buff_size)
{
    snprintf(address_out, buff_size, "%s", customer_address);
}

void Customer::customer_assign_car(int car_id)
{
    if (!cars_rented)
        cars_rented = (int*)malloc(sizeof(int));
    else
        cars_rented = (int*)realloc(cars_rented, sizeof(int) * (cars_rented_count + 1));
    cars_rented[cars_rented_count] = car_id;
    cars_rented_count++;
}

int Customer::customer_has_car(int car_id)
{
    if (!cars_rented)
        return -1;
    for (int i = 0; i < cars_rented_count; i++)
    {
        if (cars_rented[i] == car_id)
            return i;
    }
    return -1;
}

int Customer::customer_remove_car(int car_id)
{
    int car_index = customer_has_car(car_id);
    if (car_index == -1)
        return 0;
    cars_rented_count--;
    for (int i = car_index; i < cars_rented_count - 1; i++)
        cars_rented[i] = cars_rented[i + 1];
    cars_rented = (int*)realloc(cars_rented, sizeof(int) * cars_rented_count);
    return 1;
}

int Customer::customer_get_car_count()
{
    return cars_rented_count;
}

int Customer::customer_get_car_id(int index)
{
    if (!cars_rented || cars_rented_count <= index)
        return -1;
    return cars_rented[index];
}
