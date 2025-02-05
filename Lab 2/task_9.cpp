#include <iostream>
#include <string>
using namespace std;

typedef struct{
    int id;
    string name;
    int quatity;
    double price;
}Products;

int main(){
    double value=0;
    int n;
    cout<<"Enter number of Products: ";
    cin>>n;

    Products *p=new Products[n];

    for(int i=0; i<n; i++){
        cout<<"\nEnter Details For Product "<<i+1<<": \n";

        cout<<"Enter Product ID:  ";
        cin>>(*(p+i)).id;
        cout<<"Enter Product Name: ";
        cin>>(*(p+i)).name;
        cout<<"Enter Quantity of Product: ";
        cin>>(*(p+i)).quatity;
        cout<<"Enter Product Price: ";
        cin>>(*(p+i)).price;
        value += ( (*(p+i)).quatity * (*(p+i)).price );

    }

    cout<<"\nThe Total Value of Inventory is: "<<value<<endl;

    delete[] p;
    return 0;
}