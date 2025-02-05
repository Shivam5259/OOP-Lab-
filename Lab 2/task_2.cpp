#include <iostream>
#include <iomanip>
using namespace std;

void input(int **arr, int m, int n);
void display(int **arr, int m, int n);
void add(int **matrix1, int **matrix2, int m, int n);
void subtract(int **matrix1, int **matrix2, int m, int n);
void deallocate(int **arr, int m);

int main(){
    int m, n;
    cout<<"Enter the Rows And Columns of Matrices: ";
    cin>>m>>n;
    int **matrix1;
    matrix1=new int*[m];
    
    for (int i = 0; i < m; i++){
        *(matrix1+i)=new int[n];
    }

    int **matrix2;
    matrix2=new int*[m];
    
    for (int i = 0; i < m; i++){
        *(matrix2+i)=new int[n];
    }
    
    cout<<"Enter the elements of matrix 1: \n";
    input(matrix1, m, n);

    cout<<"Enter the elements of matrix 2: \n";
    input(matrix2, m, n);

    cout<<"\n\nDisplaying Matrix 1: \n";
    display(matrix1, m, n);
    cout<<"\n\nDisplaying Matrix 2: \n";
    display(matrix2, m, n);

    add(matrix1, matrix2, m, n);
    subtract(matrix1, matrix2, m, n);

    deallocate(matrix1, m);
    deallocate(matrix2, m);

    return 0;
}

void input(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter element "<<j+1<<" of "<<i+1<<" row: ";
            cin>>*(*(arr+i)+j);
        }
    }
}

void display(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"|"<<setw(2)<<*(*(arr+i)+j);
        }
        cout<<"|\n";
    }
}

void add(int **matrix1, int **matrix2, int m, int n){
    int **add=new int*[m];

    for(int i=0; i<m; i++){
        *(add+i)=new int[n];
        for(int j=0; j<n; j++){
            *(*(add+i)+j)=*(*(matrix1+i)+j) + *(*(matrix2+i)+j);
        }
    }

    cout<<"\n\nDisplaying The Addition of these two Matrices: \n";
    display(add, m, n);
    deallocate(add, m);
}

void subtract(int **matrix1, int **matrix2, int m, int n){
    int **subtract=new int*[m];

    for(int i=0; i<m; i++){
        *(subtract+i)=new int[n];
        for(int j=0; j<n; j++){
            *(*(subtract+i)+j)=*(*(matrix2+i)+j) - *(*(matrix2+i)+j);
        }
    }

    cout<<"\n\nDisplaying The Subtraction of Matrix 2 from Matrix 1: \n";
    display(subtract, m, n);
    deallocate(subtract, m);
}

void deallocate(int **arr, int m){
    for(int i=0; i<m; i++){
        delete[] arr[i];
    }
    delete[] arr;
}