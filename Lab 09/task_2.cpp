#include <iostream>
#include <cstring>

using namespace std;

class MenuItem{
protected:
    string dishName;
    double price;

public:
    MenuItem(string s, double d): dishName(s), price(d){}

    virtual void showDetails()=0;
    virtual void prepare()=0;

    virtual ~MenuItem(){}
};

class Appetizer: public MenuItem{
public:
    Appetizer(string s, double p): MenuItem(s, p){}

    void showDetails(){
        cout<<"Appetizer:\nDish Name: "<<dishName<<"\tPrice: "<<price<<endl;
    }
    void prepare(){
        cout<<"Preparing for appetizer!"<<endl;
    }
};

class MainCourse: public MenuItem{
    public:
    MainCourse(string s, double p): MenuItem(s, p){}

    void showDetails(){
        cout<<"Main Course:\nDish Name: "<<dishName<<"\tPrice: "<<price<<endl;
    }
    void prepare(){
        cout<<"Preparing for Main Course!"<<endl;
    }
};

int main(){
    MenuItem *m1=new Appetizer("Soup", 250);
    MenuItem *m2=new MainCourse("Biryani", 450);

    m1->prepare();
    m2->prepare();
    m1->showDetails();
    m2->showDetails();
}   