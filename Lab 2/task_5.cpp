#include <iostream>
#include <iomanip>
using namespace std;

void display(int **arr, int m, int n);
void transverse(int **arr, int m, int n);
void deallocate(int **arr, int m);

int main(){
    int rows, cols;
    cout<<"Enter Rows and Columns: ";
    cin>>rows>>cols;

    int **arr=new int*[rows];
    
    for(int i=0; i<rows; i++){
        *(arr+i)=new int[cols];
        for(int j=0; j<cols; j++){
            cout<<"Enter element: "<<j+1<<" of "<<i+1<<" row: ";
            cin>>*(*(arr+i)+j);
        }
    }

    display(arr, rows, cols);
    transverse(arr, rows, cols);
    cout<<"The Transverse of given Array is: \n";
    display(arr, rows, cols); 

    int sum;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            sum+=*(*(arr+i)+j);
        }
    }

    deallocate(arr, rows);
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

void transverse(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=i+1; j<n; j++){
            int temp=*(*(arr+i)+j);
            *(*(arr+i)+j)=*(*(arr+j)+i);
            *(*(arr+j)+i)=temp;
        }
    }
}

void deallocate(int **arr, int m){
    for(int i=0; i<m; i++){
        delete[] arr[i];
    }
    delete[] arr;
}