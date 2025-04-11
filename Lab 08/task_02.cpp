#include <iostream>
#include <string>
using namespace std;

class Manager;

class Account{
private: 
    string acc_no;
    double balance;

    friend class Manager;
public:
    Account(string a, double b): acc_no(a), balance(b) {}
    
    friend void transferFunds(Account &a1, Account &a2, double amount);
};

void transferFunds(Account &a1, Account &a2, double amount){
    if(a1.balance>=amount){
        a2.balance+=amount;
        a1.balance-=amount;
        cout<<amount<<" has been successfully transfered from account 1 to account 2!"<<endl;
    }
    else{
        cout<<"Account 1 don't have sufficient funds to transfer!"<<endl;
    }
}

class Manager{
public:

    void display(Account &a){
        cout<<"Account Number: "<<a.acc_no<<"\tBalance: "<<a.balance<<endl;
    }

    void withdraw(Account &a, double amount){
        if(a.balance>=amount){
            a.balance-=amount;
            cout<<amount<<" has been successfully withdrawl from your account and your new balance is: "<<a.balance<<endl;
        }
        else{
            cout<<"The account has insufficient amount please enter correct amount!"<<endl;
        }
    }

    void deposit(Account &a, double amount){
        a.balance+=amount;
        cout<<amount<<" has bee successfully deposit and your new balance is: "<<a.balance<<endl;
    }
};

int main(){
    Account a("124234", 400);
    Account a2("3618", 300);
    Manager m;
    m.deposit(a, 400);
    m.withdraw(a, 390);
    m.display(a);
    transferFunds(a, a2, 100);
    return 0;
}