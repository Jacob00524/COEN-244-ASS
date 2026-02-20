extern int global_customer_id;

class Customer
{
    public:
        Customer(char *name, char *address, char *tele);
        ~Customer();

        int customer_set_name(char *new_name);
        int customer_set_tele(char *new_tele);
        int customer_set_address(char *new_address);

        void customer_get_name(char *name_out, int buff_size);
        void customer_get_tele(char *tele_out, int buff_size);
        void customer_get_address(char *address_out, int buff_size);
    private:
        int customer_id;
        char *customer_name, *customer_address, *customer_tele;
        int *cars_rented;
        int cars_rented_count;
};