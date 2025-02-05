#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int x, y, z;
    cout<<"Enter Dimensions for 3D array (Layers Rows Columns): ";
    cin>>x>>y>>z;

    int ***arr=new int**[x];

    for(int i=0; i<x; i++){
        *(arr+i)=new int*[y];
        for(int j=0; j<y; j++){
            *(*(arr+i)+j)=new int[z];
            for(int k=0; k<z; k++){
                cout<<"Element ["<<i<<"]["<<j<<"]["<<k<<"]: ";
                cin>>*(*(*(arr+i)+j)+k);
            }
        }
    }

    for(int i=0; i<x; i++){
        cout<<"\nLayer "<<i+1<<":\n";
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                cout<<"|"<<setw(2)<<*(*(*(arr+i)+j)+k);
            }
            cout<<"|\n";
        }
    }
    return 0;
}