#include <iostream>
#include <string>
using namespace std;

class AlarmSystem{
public: 
	string securityLevel;
	
	AlarmSystem(string level){
		securityLevel=level;
	} 
	
	void display(){ 
		cout << "Alarm Security Level: " << securityLevel << "\n"; 
	} 
};

class SmartHome{
	AlarmSystem alarm;
	string homeName;

public:
	SmartHome(string name, string level): homeName(name), alarm(level){}
	
	void display(){ 
		alarm.display(); 
	} 
};

int main(){ 	
SmartHome home("Villa 06","High"); 
home.display();

return 0;

}