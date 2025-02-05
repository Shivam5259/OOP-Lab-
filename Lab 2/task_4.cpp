#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number of Strings: ";
    cin>>n;

    string *s=new string[n];

    for(int i=0; i<n; i++){
        cout<<"Enter String "<<i+1<<": ";
        cin>>*(s+i);
    }

    for(int i=0; i<n-1; i++){
        if(*(s+i)>*(s+i+1)){
            string temp=*(s+i);
            *(s+i)=*(s+i+1);
            *(s+i+1)=temp;
            i=-1;
        }
    }

    cout<<"Sorted Strings: \n";
    for(int i=0; i<n; i++){
        cout<<"String "<<i+1<<": "<<*(s+i)<<endl;
    }

    delete[] s;
    return 0;
}