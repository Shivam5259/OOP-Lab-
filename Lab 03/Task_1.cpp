#include <iostream>
#include <string>
using namespace std;

class Wallet{
    string name;
    double balance;
    double *transaction;
public:
    Wallet(string name, double balance, double *transaction){
        this->name=name;
        this->balance=balance;
        this->transaction=transaction;
    }
    void addMoney(double amount){
        balance+=amount;
    }
    void spendMoney(double amount){
        if(balance<amount){
            cout<<"Insufficient Amount!"<<endl;
        }
        else{
            balance-=amount;
        }
    }
    void transactionHistory(int n){
        for(int i=0; i<n; i++){
            cout<<"Transaction No. "<<i+1<<":\t"<<transaction[i]<<endl;
        }
    }
};

int main(){
    cout<<"Input for wallet 1:\n";
    string name;
    cout<<"Enter Owner Name: ";
    cin>>name;
    double balance;
    cout<<"Enter Remaining Balance: ";
    cin>>balance;
    int n;
    cout<<"Enter Number of Transactions Earlier: ";
    cin>>n;
    double transaction[n];
    cout<<"Enter Transaction History (Use + for deposit and - for Withdrawl): "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter Transaction No. "<<i+1<<": ";
        cin>>transaction[i];
    }
    Wallet w1(name, balance, transaction);
    int a;
    cout<<"Enter 1. Add Money\n2. Spend Money\n3. Display Transaction History\nEnter any other key to exit: ";
    cin>>a;

    switch (a){
    case 1:
        int amount;
        cout<<"Enter Amount to add: ";
        cin>>amount;
        w1.addMoney(amount);
        break;
    case 2:
        int amount1;
        cout<<"Enter Amount to spend: ";
        cin>>amount1;
        w1.spendMoney(amount1);
        break;

    case 3: 
        w1.transactionHistory(n);
        break;
    
    default:
        break;
    }
    return 0;
}