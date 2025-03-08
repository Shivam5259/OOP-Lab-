#include <iostream>
#include <cstring>
using namespace std;

class Apartment{
public:
    int id;
    string address;
    string *owner;

    Apartment(int Id, string Address, string &Owner)
    {
        id = Id;
        address = Address;
        owner = new string(Owner);
    }

    Apartment(Apartment &other)
    {
        id = other.id;
        address = other.address;
        owner = new string;
        owner=other.owner;
    }

    void display()
    {
        cout << "Apartment ID: " << id << "\tApartment Address: " << address << "\tOwner: " << *owner << endl;
    }

    ~Apartment(){
        delete owner;
    }
};

int main()
{
    string str = "Shivam";
    Apartment a(12, "fhuiuda", str);
    a.display();

    Apartment b = a;
    b.display();
}