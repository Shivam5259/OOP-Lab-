#include <iostream>
#include <string>
using namespace std;

class Car{
    string brand;
    string model;
    double price;
    bool availability;
    double totalRevenue;
public:
    Car(): brand("Unknown"), model("Generic"), price(0.0), availability(true), totalRevenue(0){}

    Car(string brand, string model, double price, bool a){
        this->brand=brand;
        this->model=model;
        this->price=price;
        availability=a;
        totalRevenue=0;
    }

    Car(Car &other){
        brand=other.brand;
        model=other.model;
        price=other.price;
        availability=other.availability;
        totalRevenue=other.totalRevenue;
    }

    void updateData(string brand, string model, double price, bool a, double revenue){
        this->brand=brand;
        this->model=model;
        this->price=price;
        availability=a;
        this->totalRevenue=revenue;
    }

    bool available(){
        if(availability==true){
            return true;
        }
        else{
            return false;
        }
    }

    void requestRent(int days){
        if(available()){
            availability=false;
            cout<<"Car is successfully Rented!"<<endl;
            double cost=days*price;
            cost*=discount(days);
            this->totalRevenue+=cost;

        }
        else{
            cout<<"Car is already on Rent!"<<endl;
        }
    }

    double discount(int days){
        double discount=0;
        if(days>10){
            discount=1-0.1;
        }
        else if (days>5){
            discount=1-0.05;
        }
        return discount;
    }

    void display(){
        cout<<"Car Brand: "<<brand<<"\nCar Model: "<<model<<"\nCar Rent Price: "<<price<<"\nCar Availabiltiy: "<<availability<<endl;
        cout<<"The Car has total Rervenue of: "<<this->totalRevenue<<endl;
    }

    ~Car(){
        cout<<"Car is Successfully Removed!"<<endl;
    }
};

int main(){
    Car c("Toyota", "Gerande", 500.0, true);
    c.requestRent(20);
    c.display();
}