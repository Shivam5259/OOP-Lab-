#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file("sensor_log.txt");

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "Mama said life is like a box of chocolates.\n";
    file << "You never know what you're gonna get.\n";

    size_t pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "The eternal faminine leads us aloft.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "Not all those who wander are lost.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file.close();

    return 0;


}