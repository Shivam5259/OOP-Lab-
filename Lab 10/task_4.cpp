#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    ifstream file("vehicle.txt");
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string line;
    stringstream ss;
    string type,id,name,year,extraData;
    float b1;
    int b2;

    while(getline(file, line))
    {
        ss.clear();
        ss.str(line); 

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, type, ',');
        getline(ss, year, ',');
        getline(ss, extraData); 

        if(type == "Autonomous Car")
        {
            size_t pos = extraData.find(":");
            if(pos == string::npos)
            {
                cout<< "there is no : in Extra" << endl;
                return 1;
            }
            b1 = stof(extraData.substr(pos+1, 3));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Extracted Value: " << b1 << endl;
        }

        if(type == "ElectricVehicle")
        {
            size_t pos = extraData.find(":");
            if(pos == string::npos)
            {
                cout<< "there is no : in Extra" << endl;
                return 1;
            }
            b2 = stoi(extraData.substr(pos+1, 4));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Extracted Value: " << b2 << endl;
        }
    }
    file.close();
    return 0;
}