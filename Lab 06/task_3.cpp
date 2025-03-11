#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;

    void display(){
        cout<<"Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person{
public:
    string subject;

    void display(){
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Teacher{
public:
    string researchArea;

    void display(){
        cout<<"Research Area: "<< researchArea<<endl;
    }
};

class Professor :public Researcher{
public:
    int publications;

    void display(){
        Person::display();
        Teacher::display();
        Researcher::display();
        cout<<"Number of Publications: "<<publications<<endl;
    }
};

int main(){
    Professor p;
    p.name="Shivam";
    p.age=18;
    p.subject="Object Oriented Programming";
    p.researchArea="Computer Science";
    p.publications=13;
    p.display();
    return 0;
}