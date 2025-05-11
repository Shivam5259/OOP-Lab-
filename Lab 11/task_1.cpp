#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

class DimensionMismatchException: public exception{
public:
    const char* what()const noexcept{
        return "Dimension Mismatch Exception!";
    }
};

template <typename T>

class Matrix{
    T** data;
    int rows, cols;

public:
    Matrix(int r, int c): rows(r), cols(c) {
        data= new T*[rows];
        for(int i=0; i<rows; i++){
            *(data+i)=new T[cols];
            for (int j=0; j<cols; j++){
                *(*(data+i)+j)=0;
            }
        }
    }

    void takeInput(){
        cout<<"Taking User Input: \n";
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<"Enter Value for Row: "<<i+1<<" and Column: "<<j+1<<": ";
                cin>>*(*(data+i)+j);
            }
        }
    }

    ~Matrix(){
        for(int i=0; i<rows; i++){
            delete[] *(data+i);
        }
        delete[] data;
    }

    Matrix<T> operator+(Matrix<T>& other){
        if(rows != other.rows || cols !=other.cols){
            throw DimensionMismatchException();
        }

        Matrix<T> result(rows, cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result.data[i][j]=data[i][j]+other.data[i][j];
            }
        }
        return result;
    }

    void print(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j){
                cout <<"|"<< data[i][j];
            }                
            cout << "|\n";
        }
    }
};

int main(){
    try{
        Matrix<int> A(2,2);
        // A.takeInput();
        Matrix<int> B(3,3);
        A.print();
        B.print();
        Matrix<int> C=A+B;

    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }

}