class ExoticFruits {
    public:
        void set_price(double new_price);
        void set_discount(double new_discount);
        double get_price();
    private:
        double price;
        double discount;
        double getdiscount( );
};

int main(){
    ExoticFruits  pomegranate, passion_fruit;

    pomegranate.price = 6.39; //i
    passion_fruit.set_price(6.75); //ii

    double pf_price, pf_disc; //iii

    pf_price = passion_fruit.get_price(); //iv
    pf_disc = passion_fruit.get_discount (); //v
    pg_disc = pomegranate.get_discount (); //vi

    if (pomegranate < passion_fruit) //vii
        cout << "Buy pomegranate.\n";
    else
        cout << "Buy passion fruit.\n";

    pomegranate = passion_fruit; //ix
}
