#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    ifstream file("Vehicle.txt");

    if(!file.is_open()){
        cout<<"Failed Opening File"<<endl;
        exit(1);
    }
    else{
        string line;
        while(getline(file, line)){
            cout<<line<<endl;
        }
    }
    file.close();
    return 0;
}