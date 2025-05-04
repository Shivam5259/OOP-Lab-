#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("Vehicle.txt");

    if (!file.is_open())
    {
        cout << "Failed Opening File" << endl;
        exit(1);
    }
    else
    {
        string line;
        istringstream ss(line);
        string name, id, type, year, extraData;
        while (getline(file, line))
        {
            ss.clear();
            ss.str(line);

            getline(ss, name, ',');
            getline(ss, id, ',');
            getline(ss, type, ',');
            getline(ss, year, ',');
            getline(ss, extraData);
            cout << "Name: " << name << "\tID: " << id << "\tType: " << type << "\tYear: " << year << "\tExtra Data: " << extraData << endl;
        }
    }
    file.close();
    return 0;
}