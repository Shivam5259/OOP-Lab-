#include <iostream>
#include <string>

using namespace std;

class Patient{
protected:
    string name;
    string id;

public:
    Patient(string s1, string s2) : name(s1), id(s2) {}

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;

    virtual ~Patient(){}
};

class InPatient : public Patient{
public:
    InPatient(string s1, string s2) : Patient(s1, s2) {}

    void displayTreatment(){
        cout << "InPatient:\nName: "<<name<<"\tId: "<<id<< endl; 
    }
    void calculateCost(){
        cout << "Calculating Inpatient cost!" << endl;
    }
};

class OutPatient : public Patient{
public:
    OutPatient(string s1, string s2) : Patient(s1, s2) {}

    void displayTreatment(){
        cout << "OutPatient:\nName: "<<name<<"\tId: "<<id<< endl; 
        
    }
    void calculateCost(){
        cout << "Calculating OutPatient cost!" << endl;
        
    }
};

int main(){
    Patient *p1 = new InPatient("Shivam", "123");
    Patient *p2 = new OutPatient("Jeevan", "435");
    p1->displayTreatment();
    p2->displayTreatment();
    p1->calculateCost();
    p2->calculateCost();

    delete p1;
    delete p2;
}