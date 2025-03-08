#include <iostream>
#include <string>
using namespace std;

class Doctor{
public:
    string name;
    string specialization;
    double experience;


    Doctor(string Name, string s, double e):name(Name), specialization(s), experience(e){}
    Doctor(){}

    void display(){
        cout<<"Doctor Name: "<<name<<endl;
        cout<<"Doctor Experience: "<<experience<<" Years"<<endl;
        cout<<"Doctor Specialization: "<<specialization<<endl;
    }
    
};

class Hospital{
    Doctor** doctor;
    int doctorCount;
    string name;

public:
    Hospital(string name): name(name), doctor(nullptr), doctorCount(0){}

    void addDoctor(Doctor &other){
        Doctor** temp = new Doctor*[doctorCount+1];

        for(int i=0; i<doctorCount; i++){
            temp[i]=doctor[i];
        }

        temp[doctorCount]=&other;

        delete[] doctor;
        doctor=temp;
        doctorCount++;

        cout<<"Doctor: "<<other.name<<" Added Successfully to the hospital!"<<endl;

    }
    
    void display(){
        cout<<"Hospital Name: "<<name<<endl;
        if(doctorCount==0){
            cout<<"No Doctors Assigned to this Hospital!"<<endl;
            return;
        }

        for(int i=0; i<doctorCount; i++){
            cout<<"\nDoctor "<<i+1<<": "<<endl;
            doctor[i]->display();
        }

    }

    ~Hospital(){
        for(int i=0; i<doctorCount; i++){
            doctor[i]=nullptr;
        }
        doctor=nullptr;
    }
};

int main(){
    Doctor d1("Shivam", "Neurologist", 1.5);
    Hospital h1("The Modern");
    h1.addDoctor(d1);
    h1.display();

    return 0;
}