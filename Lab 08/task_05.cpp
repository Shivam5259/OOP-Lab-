#include <iostream>
#include <string>
using namespace std;

class MatrixHelper;

class Matrix2x2{
private:
    double a, b, c, d;
    friend double determinant(Matrix2x2&);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream &out, Matrix2x2 &m);

public:
    Matrix2x2(double a, double b, double c, double d): a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(Matrix2x2 m){
        return Matrix2x2(a+m.a, b+m.b, c+m.c, d+m.d);
    }

    Matrix2x2 operator-(Matrix2x2 m){
        return Matrix2x2(a-m.a, b-m.b, c-m.c, d-m.d);
    }

    Matrix2x2 operator*(Matrix2x2 m){
        return Matrix2x2(a*m.a, b*m.b, c*m.c, d*m.d);
    }
};

double determinant(Matrix2x2& m){
    return (m.a*m.c-m.b*m.d);
}

ostream& operator<<(ostream &out, Matrix2x2 &m){
    return (out<<"|"<<m.a<<"|"<<m.b<<"|\n|"<<m.c<<"|"<<m.d<<"|");
}

class MatrixHelper{
public:
    void update_a(Matrix2x2 &m, double a){
        cout<<m.a<<" has been successfully uodated to "<<a<<endl;
        m.a=a;
    }

    void update_b(Matrix2x2 &m, double b){
        cout<<m.b<<" has been successfully uodated to "<<b<<endl;
        m.b=b;
    }
    void update_c(Matrix2x2 &m, double c){
        cout<<m.c<<" has been successfully uodated to "<<c<<endl;
        m.c=c;
    }
    void update_d(Matrix2x2 &m, double d){
        cout<<m.d<<" has been successfully uodated to "<<d<<endl;
        m.d=d;
    }
};

int main(){
    Matrix2x2 m1(1,2,3,4), m2(5,6,7,8);
    cout<<"M1: \n"<<m1<<endl;
    Matrix2x2 m3=m1+m2;
    cout<<"\nm1+m2= \n"<<m3<<endl;
    Matrix2x2 m4=m1-m2;
    cout<<"\nm1-m2= \n"<<m4<<endl;
    Matrix2x2 m5=m1*m2;
    cout<<"\nm1*m2= \n"<<m5<<endl;
    cout<<"Determinant of M1: "<<determinant(m1)<<endl;
    MatrixHelper m;
    m.update_a(m1, 12);
    m.update_b(m1, 34);
    m.update_c(m1, 89);
    m.update_d(m1, 54);
    cout<<"\nUpdated M1: \n"<<m1<<endl;

    return 0;

}