#include <iostream>
using namespace std;

class Device{
public:
    int deviceId;
    bool status;

    void display(){
        cout<<"Deice ID: "<<deviceId<<", Status: "<<status<<endl;
    }
};

class SmartPhone : public Device{
public:
    float screenSize;

    void display(){
        Device::display();
        cout<<"Screen Size: "<<screenSize<<endl;
    }
};

class SmartWatch : public Device{
public:
    bool heartRateMonitor;

    void display(){
        Device::display();
        cout<<"Heart Rate Monitor: "<<heartRateMonitor<<endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch{
public:
    int stepCounter;

    void display(){
        SmartPhone::display();
        cout<<"Heart Rate Monitor: "<<heartRateMonitor<<endl;
        cout<<"Step Counts: "<<stepCounter<<endl;
    }
};

int main(){
    SmartWearable s;
    s.SmartPhone::deviceId=12;
    s.SmartPhone::status=1;
    s.heartRateMonitor=1;
    s.screenSize=4.5;
    s.display();
    
    return 0;
}