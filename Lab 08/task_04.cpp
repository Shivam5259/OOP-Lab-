#include <iostream>
#include <string>
using namespace std;

class InventoryManager;

class Car{
private:
    string model;
    double price;

    friend class InventoryManager;
    friend void compare(Car& , Car&);

public:
    Car(string s, double p): model(s), price(p) {}
};

class InventoryManager{
public:
    void updaterice(Car &c, double price){
        c.price=price;
        cout<<"Car: "<<c.model<<"'s price has been updated to "<<price<<endl;
    }

    void display(Car &c){
        cout<<"Car Model: "<<c.model<<"\tCar Price: "<<c.price<<endl;
    }
};

void compare(Car &c1, Car &c2){
    if(c1.price>c2.price){
        cout<<c1.model<<" is expensive than "<<c2.model<<endl;
    }
    else if(c1.price<c2.price){
        cout<<c2.model<<" is expensive than "<<c1.model<<endl;
    }
    else{
        cout<<"Both cars are equally price!"<<endl;
    }
}

int main(){
    Car c1("Gerande", 6400000), c2("Fortuner", 25000000);
    InventoryManager m;
    m.display(c1);
    m.updaterice(c1, 7000000);
    compare(c1, c2);
    return 0;
}