#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Product{
public:
    int id;
    string name;
    int quantity;

    Product(int id, string name, int q): id(id), name(name), quantity(q){}

    void display(){
        cout<<"Product ID: "<<id<<endl;
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product Quatity in Stock: "<<quantity<<endl;
    }
};

class Warehouse{
public:
    Product** products;
    int productCount;

    Warehouse(): products(nullptr), productCount(0){}

    void storeProduct(Product &p){
        Product** temp=new Product*[productCount+1];

        for(int i=0; i<productCount; i++){
            temp[i]=products[i];
        }

        temp[productCount]=&p;

        delete[] products;
        products=temp;
        productCount++;

        cout<<"Product: "<<p.name<<" added to inventry!"<<endl;

        for(int i=0; i<productCount; i++){
            for(int j=i+1; j<productCount; j++){
                if(products[i]->name > products[j]->name){
                    Product* temp=products[i];
                    products[i]=products[j];
                    products[j]=temp;
                }
            }
        }
    }

    void search(int id){
        for(int i=0; i<productCount; i++){
            if(products[i]->id==id){
                cout<<"Product Found!"<<endl;
                products[i]->display();
                return;
            }
        }
        cout<<"Product Not Found!"<<endl;
        return;
    }

    void display(){
        for(int i=0; i<productCount; i++){
            cout<<"Product "<<i+1<<": "<<endl;
            products[i]->display();
        }
    }

    ~Warehouse(){
        for(int i=0; i<productCount; i++){
            products[i]=nullptr;
        }
        products=nullptr;
    
    }

};

int main(){
    Product p1(12, "Water Bottles", 23);
    Warehouse w;
    w.storeProduct(p1);
    // w.display();
    Product p2(14, "Cold Drinks", 45);
    w.storeProduct(p2);
    // w.display();
    Product p3(14, "Burger", 45);
    w.storeProduct(p3);
    w.display();
    return 0;
}