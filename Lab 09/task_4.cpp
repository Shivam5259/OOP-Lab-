#include <iostream>
#include <string>
using namespace std;

class WeatherSensor{
public:
    virtual void readData()= 0;
    virtual void displayReport()= 0;

    virtual ~WeatherSensor(){}
};

class Thermometer : public WeatherSensor {
public:
    void readData(){
        cout<<"Read Thermometer Data!\n";
    }

    void displayReport(){
        cout<<"Displaying Thermometer Report!"<<endl;
    }
};

class Barometer : public WeatherSensor {
public:
    void readData(){
        cout<<"Read Barometer Data!\n";
    }

    void displayReport(){
        cout<<"Displaying Barometer Report!"<<endl;
    }
};

int main() {
    WeatherSensor* sensors[2];
    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();

    for (int i = 0; i < 2; ++i) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 2; ++i) {
        delete sensors[i];
    }

    return 0;
}
