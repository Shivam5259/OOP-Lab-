#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    int roll_no;
    double marks[3];
}Students;

int main(){
    int n;
    cout<<"Enter Number of Students: ";
    cin>>n;

    Students *arr=new Students[n];
    int *avg=new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter Student "<<i+1<<" Name: ";
        cin>>(*(arr+i)).name;
        cout<<"Enter Student "<<i+1<<" Roll.No: ";
        cin>>(*(arr+i)).roll_no;
        cout<<"Enter Marks of First Subject of Student "<<i+1<<": ";
        cin>>(*(arr+i)).marks[0];
        cout<<"Enter Marks of Second Subject of Student "<<i+1<<": ";
        cin>>(*(arr+i)).marks[1];
        cout<<"Enter Marks of Third Subject of Student "<<i+1<<": ";
        cin>>(*(arr+i)).marks[2];
        *(avg+i)=(*(arr+i)).marks[0] + (*(arr+i)).marks[1] + (*(arr+i)).marks[2];
    }

    for(int i=0; i<n; i++){
        cout<<"\nAverage of Student "<<i+1<<":\n";
        cout<<"Student Name: "<<(*(arr+i)).name<<endl;
        cout<<"Student Roll Number: "<<(*(arr+i)).roll_no<<endl;
        cout<<"Average in Three Subjects: "<<*(avg+i)/3<<endl;
    }

    delete[] avg;
    delete[] arr;
    return 0;
}