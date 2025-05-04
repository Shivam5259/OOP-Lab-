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
    int res;

    while(getline(file, line))
    {
        ss.clear();
        ss.str(line); 

        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, type, ',');
        getline(ss, year, ',');
        getline(ss, extraData); 

        if(!(res = stoi(year)))
        {
            cout << "Error converting year to integer!" << endl;
            return 1;
        }

        cout << "Name: " << name << "\tID: " << id << "\tType: " << type << "\tYear: " << res << "\tExtra Data: " << extraData << endl;
    }
    file.close();
    return 0;
}