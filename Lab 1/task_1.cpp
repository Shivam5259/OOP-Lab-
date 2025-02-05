/* Name: Shivam
 * Roll No: 24k-0957
*/

#include <iostream>
#include <string>
using namespace std;

void attendenceChecker(string event1[], string event2[]);
void reverseOrder(string event1[], string event2[]);
void chart(string event1[], string event2[]);

int main(){
    int n=5;
    string event1[n], event2[n];

    for(int i=0; i<n; i++){
        cout << "Enter the name of " << i+1 << " Partcipant for first event: ";
        cin >> event1[i];
    }

    for(int i=0; i<n; i++){
        cout << "Enter the name of " << i+1 << " Partcipant for second event: ";
        cin >> event2[i];
    }

    cout << "The Participants of first Event are: " << endl;
    for(int i=0; i<n; i++){
        cout << i+1 <<". " << event1[i] << endl;
    }

    cout << endl << "The Participants of second Event are: " << endl;
    for(int i=0; i<n; i++){
        cout << i+1 <<". " << event2[i] << endl;
    }

    attendenceChecker(event1, event2);

    cout<<endl<<"The total donation collected from both events are: "<< 2*n<< "$"<<endl;

    reverseOrder(event1, event2);
    chart(event1, event2);
}

void attendenceChecker(string event1[], string event2[]){
    int flag=0;
    string name;
    cout<<"Enter the name of participant to check: ";
    cin>>name;

    for(int i=0; i<5; i++){
        if(event1[i] == name || event2[i]==name){
            flag=1;
        }
    }
    if(flag==1){
        cout << "Participant is registered!" << endl;
    }
    else{
        cout << "Participant is not registered!" << endl;
    }
}

void reverseOrder(string event1[], string event2[]){
    cout<<endl<< "The Participants of first Event in reverse order are: "<<endl;
    for(int i=4; i>=0; i++){
        cout << i+1 <<". " << event1[i] << endl;
    }

    cout<<endl<<"The Participants of second Event in reverse order are: "<<endl;
    for(int i=4; i>=0; i++){
        cout << i+1 <<". " << event2[i] << endl;
    }
}

void chart(string event1[], string event2[]){
    cout<<endl<<"The Bar Chart for first event is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<"* ";
    }
    cout<<endl<<"The Bar Chart for second event is: "<<endl;
    for(int i=0; i<5; i++){
        cout<<"* ";
    }
}