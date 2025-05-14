#include <iostream>
#include <exception>

using namespace std;

class InvalidTemperatureException : public exception {};


template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    try {
        double f = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << f << "\n";
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }

}
