#include <iostream>
#include <string>

using namespace std;

class Vehicle{
public:
    string brand;
    int speed;

    void display(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};

class Car : public Vehicle{
public:
    int seats;

    void display(){
        Vehicle::display();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car{
public:
    int batteryLife;

    void display(){
        Vehicle::display();
        Car::display();
        cout << "Battery Life: " << batteryLife << endl;
    }
};

int main(){
    ElectricCar e;
    e.brand = "Tesla";
    e.speed = 250;
    e.batteryLife = 12;
    e.seats = 13;
    e.display();
}