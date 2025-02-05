#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string title;
    string author;
    int year;
}books;

void input(books* book, int n);
void display(books* book, int n);

int main(){
    int n;
    cout<<"Enter the number of books: ";
    cin>>n;

    books* book=new books[n];
    input(book, n);
    display(book, n);

    delete[] book;
    return 0;
}

void input(books* book, int n){
    for(int i=0; i<n; i++){
        cout<<"Enter title for book "<<i+1<<": ";
        cin>>(*(book+i)).title;
        cout<<"Enter author name of book "<<i+1<<": ";
        cin>>(*(book+i)).author;
        cout<<"Enter published year of book "<<i+1<<": ";
        cin>>(*(book+i)).year;
    }
}

void display(books* book, int n){
    int year, flag=0;
    cout<<"Enter the specific year: ";
    cin>>year;

    for(int i=0; i<n; i++){
        if(year < (*(book+i)).year){
            flag=1;
            cout<<"The Book "<<i+1<<" with title "<<(*(book+i)).title
            <<" wrote by "<<(*(book+i)).author<<" and published in year: "<<(*(book+i)).year<<endl;
        }
    }
    if(flag==0){
        cout<<"None of the books are published after "<<year<<"!"<<endl;
    }
}