#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    int id;
    string name;
    int* score;

    Student(int Id, string Name, int *arr){
        id = Id;
        name = Name;
        score = new int[5];//Assuming: there are total of 5 subjects
        for (int i = 0; i < 5; i++){
            score[i] = arr[i];
        }
    }

    Student(Student &s){
        id = s.id;
        name = s.name;
        score = new int[5];
        for(int i=0; i<5; i++){
            score[i]=s.score[i];
        }
    }

    void display(){
        cout << "ID: " << id << "\tName: " << name << endl;
        for (int i = 0; i < 5; i++){
            cout << "Score " << i + 1 << ": " << score[i] << "\t";
        }
    }
};

int main(){
    int arr[]={34, 67, 42, 53, 65};
    Student s(12, "Shivam", arr);
    s.display();

    Student s1(s);
    s1.display();
}