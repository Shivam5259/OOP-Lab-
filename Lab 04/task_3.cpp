#include <iostream>
#include <string>
using namespace std;

class Car{
    string brand;
    string model;
    double price;
    bool availability;
public:
    Car(): brand("Unknown"), model("Generic"), price(0.0), availability(true){}

    Car(string brand, string model, double price, bool a){
        this->brand=brand;
        this->model=model;
        this->price=price;
        availability=a;
    }

    Car(Car &other){
        brand=other.brand;
        model=other.model;
        price=other.price;
        availability=other.availability;
    }

    void updateData(string brand, string model, double price, bool a){
        this->brand=brand;
        this->model=model;
        this->price=price;
        availability=a;
    }

    void available(){
        if(availability==true){
            cout<<"Car is available for rent!"<<endl;
        }
        else{
            cout<<"Car is not available!";
        }
    }

    void requestRent(){
        if(availability==true){
            availability=0;
            cout<<"Car is successfully Rented!"<<endl;
        }
        else{
            cout<<"Car is already available!"<<endl;
        }
    }

    double discount(int days){
        double discount=0;
        if(days>5){
            discount=0.05;
        }
        else{
            discount=0.1;
        }
        return discount;
    }

    void display(){
        cout<<"Car Brand: "<<brand<<"\nCar Model: "<<model<<"\nCar Rent Price: "<<price<<"\nCar Availabiltiy: "<<availability<<endl;
    }

    ~Car(){
        cout<<"Car is Successfully Removed!"<<endl;
    }
};

int main(){
    Car c;
    c.display();
    Car c1(c);
    c1.display();
    c1.updateData("Toyota", "Gerande", 500.0, false);
    c1.display();
    c.display();
}