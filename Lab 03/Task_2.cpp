#include <iostream>
#include <string>
using namespace std;

class FitnessTracker{
    string name;
    int dailyStepGoals;
    int stepsTaken;
    double caloriesBurn;
public:
    FitnessTracker(string name, int goal){
        this->name=name;
        dailyStepGoals=goal;
        stepsTaken=0;
        caloriesBurn=0;
    }

    void logStep(int n){
        stepsTaken+=n;
        calculateCalories();
    }

    void calculateCalories(){
        //assume 0.1 calory will burn with eash step
        caloriesBurn=stepsTaken*0.1;
    }

    void progress(){
        cout<<"User Name: "<<name<<endl;
        cout<<"Daily Step Goals: "<<dailyStepGoals<<endl;
        cout<<"Steps Taken: "<<stepsTaken<<endl;
        cout<<"Calories Burned: "<<caloriesBurn<<endl;
        if(dailyStepGoals<=stepsTaken){
            cout<<"You have reached your daily goal!"<<endl;
        }
    }

};

int main(){
    FitnessTracker laiba("Laiba", 10000);
    laiba.logStep(8000);
    laiba.progress();
    laiba.logStep(3000);
    laiba.progress();
    return 0;
}