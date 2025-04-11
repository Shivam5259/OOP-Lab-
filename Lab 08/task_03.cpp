#include <iostream>
#include <string>
using namespace std;

class Vector2D{
private:
    double x, y;
    friend double dotProduct(Vector2D &v1, Vector2D &v2);
    friend ostream& operator<<(ostream &out, Vector2D v);
public:
    Vector2D(double x=0, double y=0): x(x), y(y) {}

    Vector2D operator+(Vector2D &v){
        return Vector2D(x+v.x, y+v.y);
    }

    Vector2D operator-(Vector2D &v){
        return Vector2D(x-v.x, y-v.y);
    }

    Vector2D operator*(double a){
        return Vector2D(x*a, y*a);
    }

    
};

double dotProduct(Vector2D &v1, Vector2D &v2){
    return ((v1.x*v2.x)+(v1.y*v2.y));
}

ostream& operator<<(ostream &out, Vector2D v){
    return (out<<"("<< v.x<<", "<<v.y<<")");
}

int main(){
    Vector2D v1(3,4), v2(5, 1);
    cout<<"V1: "<<v1<<"\tV2: "<<v2<<endl;
    Vector2D v3=v1+v2;
    cout<<"v1+v2= "<<v3<<endl;
    Vector2D v4=v1-v2;
    cout<<"v1-v2= "<<v4<<endl;
    Vector2D v5=v1*4;
    cout<<"v1*4= "<<v5<<endl;
    cout<<"Dot Product of v1 and v2 is: "<<dotProduct(v1, v2)<<endl;

    return 0;
}