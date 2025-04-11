#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Complex{
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i): real(r), imaginary(i) {}

    Complex operator+(Complex &c){
        return Complex(real+c.real, imaginary+c.imaginary);
    }

    Complex operator-(Complex &c){
        return Complex(real-c.real, imaginary-c.imaginary);
    }

    Complex operator*(Complex &c){
        return Complex((real*c.real)-(imaginary*c.imaginary), (imaginary*c.real)+(real*c.imaginary));
    }

    Complex operator/(Complex &c){
        double a=(c.real*c.real)+(c.imaginary*c.imaginary);
        return Complex(((real*c.real)+(imaginary*c.imaginary))/a, ((imaginary*c.real)-(real*c.imaginary))/a);
    }

    friend ostream& operator<<(ostream& out, Complex &c){
        out<< c.real <<" + "<< c.imaginary <<"i";
        return out;
    }
    
    friend double magnitude(Complex &c){
        return (sqrt(pow(c.real, 2)+pow(c.imaginary, 2)));
    }
};

int main(){
    Complex c1(2,3), c2(7,4);
    cout<<"C1: "<<c1<<"\tC2: "<<c2<<endl;
    Complex c3=c1+c2;
    cout<<c3<<endl;
    Complex c4=c1-c2;
    cout<<c4<<endl;
    Complex c5=c1*c2;
    cout<<c5<<endl;
    Complex c6=c1/c2;
    cout<<c6<<endl;
    cout<<"Magnitude of c1: "<<magnitude(c1)<<endl;
    return 0;
}