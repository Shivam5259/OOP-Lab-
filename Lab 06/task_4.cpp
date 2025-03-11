#include <iostream>
#include <string>
using namespace std;

class Account{
public:
    int accNo;
    float balance;

    void display(){
        cout<<"Account Number: "<<accNo<<", Balance: "<<balance<<endl;
    }
};

class SavingAcc : public Account{
public:
    float interest;

    void display(){
        Account::display();
        cout<<"Interest Rate: "<<interest<<endl;
    }

};

class Checking_Acc : public Account{
public:
    float overDraftLimit;

    void display(){
        Account::display();
        cout<<"Over Draft Limit: "<<overDraftLimit<<endl;
    }
};

int main(){
    SavingAcc s;
    s.accNo=2334;
    s.balance=6127.39;
    s.interest=3.4;
    Checking_Acc c;
    c.accNo=s.accNo;
    c.balance=s.balance;
    c.overDraftLimit=4.6;
    s.display();
    c.display();
    return 0;
}