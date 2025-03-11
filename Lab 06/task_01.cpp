#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
    string name;
    double salary;

    Employee(string name, double salary) : name(name), salary(salary){}

    void display(){
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee{
public:
    double bonus;

    Manager(string name, double salary, double bonus) : Employee(name, salary), bonus(bonus){}

    void display(){
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};

int main(){
    Manager manager("Shivam", 50000, 1000);
    manager.display();
}