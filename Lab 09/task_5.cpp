#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string& trackingNumber, double weight): trackingNumber(trackingNumber), weight(weight) {}

    virtual void estimateDeliveryTime()= 0;
    virtual void showDetails()= 0;

    virtual ~Shipment(){}
};

class AirFreight : public Shipment {
public:
    AirFreight(string trackingNumber, double weight): Shipment(trackingNumber, weight){}

    void estimateDeliveryTime(){
        cout << "Air Freight: Estimated delivery in 1-2 days.\n";
    }

    void showDetails(){
        cout << "Air Freight Shipment\nTracking Number: " << trackingNumber<< "\nWeight: " << weight << "\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string trackingNumber, double weight): Shipment(trackingNumber, weight){}

    void estimateDeliveryTime(){
        cout << "Ground Shipment: Estimated delivery in 4-7 days.\n";
    }

    void showDetails(){
        cout << "Ground Shipment\nTracking Number: " << trackingNumber<< "\nWeight: " << weight << "\n";
    }
};

int main() {
    Shipment* s1 = new AirFreight("AIR123", 10);
    Shipment* s2 = new GroundShipment("GRD456", 25);

    s1->showDetails();
    s2->estimateDeliveryTime();

    s2->showDetails();
    s2->estimateDeliveryTime();

    delete s1;
    delete s2;

    return 0;
}
