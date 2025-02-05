#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    int hour;
    int rate;
}Employee;

int main(){
    int n;
    cout<<"Enter Number OF Employees: ";
    cin>>n;

    Employee *e=new Employee[n];

    for(int i=0; i<n; i++){
        cout<<"Enter Name of Employee No."<<i+1<<": ";
        cin>>(*(e+i)).name;
        cout<<"Enter Hours Worked of Employee No."<<i+1<<": ";
        cin>>(*(e+i)).hour;
        cout<<"Enter Hours Rate: ";
        cin>>(*(e+i)).rate;
    }

    cout<<"\n\nCalculating Salary of Employees: \n";
    for(int i=0; i<n; i++){
        cout<<"\nEmployee Name: "<<(*(e+i)).name<<endl;
        cout<<"Salary: "<<(*(e+i)).hour * (*(e+i)).rate<<endl;
    }

    delete[] e;
    return 0;
}