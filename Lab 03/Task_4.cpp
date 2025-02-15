#include <iostream>
using namespace std;

class Car{
    string Brand;
    string Model;
    double Consumption;
    double Level;
public:
    Car(string brand, string model, double consuption, double level): Brand(brand), Model(model), Consumption(consuption), Level(level){}

    void drive(double km){
        Consumption+=(km*0.1);
        if(Consumption>Level){
            cout<<"Not Enough Fuel to Drive!"<<endl;
        }
        else{
            Level-=Consumption;
        }
    }

    void refuel(double liters){
        Level+=liters;
        cout<<liters<<" of fuel has been added to tank!"<<endl;
    }

    void check(){
        cout<<"You have total "<<Level<<" liters of fuel remaining!"<<endl;
        if(Level<10){
            cout<<"You have low fuel!"<<endl;
        }
    }
};

int main(){
    Car c("Toyota", "Gerande", 0, 30);
    c.drive(19);
    c.check();
    c.refuel(29);
    return 0;
}