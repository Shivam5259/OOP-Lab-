#include <iostream>
#include <string>
using namespace std;

class Library{
    static const int capacity=100;
    string bookList[capacity];
    string borrowed[capacity];
    string available[capacity];
    int book;
    int borrow;
    int avail;
public:
    Library(): book(0), borrow(0), avail(0){}

    void addBooks(string name){
        bookList[book]=name;
        available[book]=name;
        book++;
    }

    void Borrow(string name){
        int plag=0;
        for(int i=0; i<book; i++){
            if(available[i]==name){
                available[i]="";
                borrowed[borrow]=name;
                borrow++;
                cout<<"Book "<<name<<" Has been successfully Alloted!"<<endl;
                plag=1;
            }
        }
        if(plag==0){
            cout<<"Book: "<<name<<" is not found in the Library!";
        }
    }

    void returnBook(string name){
        for(int i=0; i<book; i++){
            if(available[i]==""){
                available[i]=name;
                for(int j=0; j<borrow; j++){
                    if(borrowed[j]==name){
                        borrowed[j]="";
                    }
                }
            }
        }
        cout<<"Returned Book: "<<name<<" has successfully added to library!"<<endl;
    }
};

int main(){
    Library l1;
    l1.addBooks("Art of Overthinking");
    l1.Borrow("Art of Overthinking");
    l1.returnBook("Art of Overthinking");
    return 0;
}