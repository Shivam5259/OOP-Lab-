#include <iostream>
#include <iomanip>
using namespace std;

void display(int **arr, int m, int n);
void deallocate(int **arr, int m);

int main(){
    int m, n;
    cout<<"Enter Dimension of matrices (Rows Columns): ";
    cin>>m>>n;

    int **matrix1=new int*[m];
    int **matrix2=new int*[m];

    cout<<"Input Entries for Matrix 1: \n";
    for(int i=0; i<m; i++){
        *(matrix1+i)=new int[n];
        for(int j=0; j<n; j++){
            cout<<"Enter Elemeny "<<j+1<<" of "<<i+1<<"th Row: ";
            cin>>*(*(matrix1+i)+j);
        }
    }

    cout<<"\nInput Entries for Matrix 2: \n";
    for(int i=0; i<m; i++){
        *(matrix2+i)=new int[n];
        for(int j=0; j<n; j++){
            cout<<"Enter Elemeny "<<j+1<<" of "<<i+1<<"th Row: ";
            cin>>*(*(matrix2+i)+j);
        }
    }

    cout<<"\n\nDisplaying Matrix 1:\n";
    display(matrix1, m, n);
    cout<<"\nDisplaying Matrix 2:\n";
    display(matrix2, m, n);

    int **result=new int*[m];
    for(int i=0; i<m; i++){
        *(result+i)=new int[n];
        for(int j=0; j<n; j++){
            int sum=0;
            for(int k=0; k<n; k++){
                sum+=*(*(matrix1+i)+k) * *(*(matrix2+k)+j);
            }
            *(*(result+i)+j)=sum;
        }
    }

    cout<<"\nDisplaying The Product of two Matrices:\n";
    display(result, m, n);

    deallocate(matrix1, m);
    deallocate(matrix2, m);
    deallocate(result, m);

    return 0;
}

void display(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"|"<<setw(2)<<*(*(arr+i)+j);
        }
        cout<<"|\n";
    }
}

void deallocate(int **arr, int m){
    for(int i=0; i<m; i++){
        delete[] arr[i];
    }
    delete[] arr;
}