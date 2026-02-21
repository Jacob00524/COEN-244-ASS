#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Company.h"
#include "Customer.h"

/*

    TODO:
    Add car specific functions????? There are no virtual functions yet
    Create UI for managing the company, customers, and cars

    UI probably needs:
        1. A way to add/remove cars to the company
        2. A way to add/remove customers
        3. A way to assign and remove rented cars from customers
        4. A way to see all current cars
        5. A way to see all current customers

*/

Company COEN_CARS(1000);
int running = 1;

void clear_screen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);
}

int wait_on_input(char *out, int max_buffer)
{
    int count;
    if (!fgets(out, max_buffer, stdin))
        return -1;
    if (out[strlen(out) - 1] == '\n')
        out[strlen(out) - 1] = 0;
    return 1;
}

int see_customers_loop()
{
    return 0;
}

int see_car_inventory_loop()
{
    char resp[10];

    clear_screen();
    printf("COEN-CARS car inventory...\n");
    Car *c;
    for (int i = 0; i < COEN_CARS.get_car_count(); i++)
    {
        COEN_CARS.get_car(i, &c);
        c->print_car();
    }
    printf("Press enter to continue.\n");
    wait_on_input(resp, sizeof(resp));

    return 0;
}

int add_car_inventory_loop()
{
    char response[10];

    clear_screen();
    printf("Add a new car to inventory.\n");

    printf("Is Standard (Y or N)? ");
    if (!wait_on_input(response, sizeof(response)))
        return 0;
    if (response[0] == 'Y' || response[0] == 'y')
    {
        StandardCar car(0);
        COEN_CARS.add_car(&car);
    }else
    {
        LuxuryCar car(0);
        COEN_CARS.add_car(&car);
    }
    clear_screen();
    printf("Added car. Continue in 3 seconds.\n");
    sleep(3);
    clear_screen();
    return 1;
}

int add_customer_loop()
{
    int loop = 1;
    char response[10], customer_name[256], customer_address[1024], customer_tele[256];

    Customer c;

    while (loop)
    {
        clear_screen();
        printf("Add a car customer.\n");

        printf("Customer Name (Can be blank):");
        if (!wait_on_input(customer_name, sizeof(customer_name)))
            goto REDO;

        printf("Customer Address (Can be blank):");
        if (!wait_on_input(customer_address, sizeof(customer_name)))
            goto REDO;

        printf("Customer Telephone (Can be blank):");
        if (!wait_on_input(customer_tele, sizeof(customer_tele)))
            goto REDO;

        if (customer_name[0])
            c.customer_set_name(customer_name);
        if (customer_address[0])
            c.customer_set_address(customer_address);
        if (customer_tele[0])
            c.customer_set_tele(customer_tele);

        clear_screen();
        printf("Adding the following customer.\n");
        c.customer_print();
        printf("Enter Y to continue, N to cancel.\n");
        if (!wait_on_input(response, sizeof(response)))
            return 0;
        if (response[0] == 'Y')
            return 1;
        else
            return 0;

        return 1;

REDO:
        clear_screen();
        printf("Error, retrying.\n");
        printf("Restart in 3 seconds.\n");
        sleep(3);
    }

    return 0;
}

int main_menu_loop()
{
    char chosen_str[10];
    int chosen_option;

    clear_screen();
    printf("COEN-CARS management system.\n\tDeveloped by Jacob and Jacob\n");
    printf("Type the number associated with the option and press `ENTER`.\n");
    printf("1. See current customers\n");
    printf("2. See current car inventory\n");
    printf("3. Add car to inventory\n");
    printf("4. Add new customer\n");
    printf("5. Exit\n");
    printf("Option: ");
    wait_on_input(chosen_str, sizeof(chosen_str));
    chosen_option = (int)strtol(chosen_str, NULL, 10);

    if (chosen_option > 5 || chosen_option < 1)
    {
        clear_screen();
        printf("Unknown option %s. Type a number from 1 to 5 (inclusive).\n", chosen_str);
        printf("Restart in 3 seconds.\n");
        sleep(3);
        main_menu_loop();
    }

    clear_screen();
    return chosen_option;
}

int main()
{
    /* test_main */
    while(running)
    {
        int chosen_menu = main_menu_loop();
        if (chosen_menu == 5)
        {
            running = 0;
            goto loop_end;
        }

        switch (chosen_menu)
        {
            case 1:
                see_customers_loop();
                break;
            case 2:
                see_car_inventory_loop();
                break;
            case 3:
                add_car_inventory_loop();
                break;
            case 4:
                add_customer_loop();
                break;
            default:
                running = 0;
                goto loop_end;
                break;
        } 
        /* Loop cleanup if any */
        loop_end:
    }
    /* Cleanup */
    return 0;
}

/*
    Just for testing the various functions and features
    Can be removed later.
*/
int test_main()
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
