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

        if(name == "Autonomous Car")
        {
            size_t pos = extraData.find(":");
            
            if(pos == string::npos)
            {
                cout<< "there is no : in Extra" << endl;
                continue;
            }
            b1 = stof(extraData.substr(pos+1, 3));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Extracted Value: " << b1 << endl;
        }

        else if(name == "ElectricVehicle")
        {
            size_t pos = extraData.find(":");
            if(pos == string::npos)
            {
                cout<< "there is no : in Extra" << endl;
                continue;
            }
            b2 = stoi(extraData.substr(pos+1, 4));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Extracted Value: " << b2 << endl;
        }

        else if(name == "Hybrid Truck")
        {
            size_t pos1 = extraData.find(":");
            size_t pos2 = extraData.find("|");

            

            if(pos1 == string::npos || pos2 == string::npos)
            {
                cout<< "there is no : or | in Extra" << endl;
                continue;
            }
            string p1 = extraData.substr(pos1 + 1, 4);
            string p2 = extraData.substr(pos2 + 11, 2);

            int p = stoi(p1);
            int q = stoi(p2);
            

            cout<< "Cargo: " << p << endl;
            cout<< "Bettery: " << q << endl;
        }

        else
        {
            cout<< "Unknown vehicle type: " << name << endl;
        }
        
    }
    file.close();
    return 0;
}