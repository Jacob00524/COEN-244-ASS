#pragma once

extern int global_customer_id;

class Customer
{
    public:
        Customer(char *name, char *address, char *tele);
        Customer();
        Customer(const Customer& cpy);
        Customer& operator=(const Customer& cpy);
        ~Customer();

        int customer_set_name(char *new_name);
        int customer_set_tele(char *new_tele);
        int customer_set_address(char *new_address);

        void customer_get_name(char *name_out, int buff_size);
        void customer_get_tele(char *tele_out, int buff_size);
        void customer_get_address(char *address_out, int buff_size);

        void customer_assign_car(int car_id);
        int customer_has_car(int car_id); /* returns -1 for non-existant, and index into cars_rented if it exists */
        int customer_remove_car(int car_id); /* returns 1 if successful, 0 if unsuccessfull */
        int customer_get_car_count();
        int customer_get_car_id(int index);

        void customer_print();
    private:
        int customer_id;
        char *customer_name, *customer_address, *customer_tele;
        int *cars_rented;
        int cars_rented_count;
};