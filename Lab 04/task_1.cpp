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

    void updateData(string brand, string model, double price, bool a){
        this->brand=brand;
        this->model=model;
        this->price=price;
        availability=a;
    }
    void availability(){
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
};

int main(){

}