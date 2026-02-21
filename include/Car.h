#pragma once

/*
    TODO: Prevent copies of car / print warning
*/

extern int g_id;

class Car
{
    public:
        Car(const char *type, int availability);
        Car(const Car& cpy);
        Car& operator=(const Car& cpy);
        ~Car();

        int get_id();
        char *get_type();
        int is_available();

        void print_car();

        void set_id(int id);
        void set_type(const char *type);
        void set_available(int availability);

    private:
        int car_id, car_available;
        char *car_type;
};