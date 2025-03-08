#include <iostream>
#include <string>

using namespace std;

class Employee{

	string Name;
	string destination;
public:
    Employee(string name, string d): Name(name), destination(d){}

	string getName(){
	return Name;
	}
	
	string getDestination(){
	return destination;
	}
};

class Project{
	string title;
	int deadline;
	Employee* employee[10];
	int employeeCount;
public:
	Project(string t, int d):title(t), deadline(d), employeeCount(0){}
	
	void add(Employee &other){
		if(employeeCount==10){
			cout<<"Project Members got exceed can't add anymore!"<<endl;
		}
		employee[employeeCount]=&other;
		employeeCount++;
		cout<<"Employee: "<< other.getName()<<" added successfully"<<endl;
	}
	
	void display(){
		cout<<"Project Title: "<<title<<"\nProject Deadline: "<<deadline<<"\nProject Employees:\n\n";
		for(int i=0; i<employeeCount; i++){
			cout<<"Employee Name: "<<employee[i]->getName()<<"\tEmployee Destination: "<<employee[i]->getDestination()<<endl;
		}
		
	}
	
};

int main(){
	Employee e1("Shivam", "gfsd");
	Project p1("Bank Management", 13);
	p1.add(e1);
	p1.display();



}