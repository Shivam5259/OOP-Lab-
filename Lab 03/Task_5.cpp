#include <iostream>
#include <string>
using namespace std;

class MusicPlayer{
    static const int songs=100;
    string playList[songs];
    string currentSong;
    int n;
public:
    MusicPlayer(): n(0){}
    void addsong(string name){
        playList[n]=name;
        n++;
        cout<<"Song Successfully Added to PlayList!"<<endl;
    }

    void removeSong(string name){
        int plag=0;
        for(int i=0; i<n; i++){
            if(playList[i]==name){
                playList[i]="";
                cout<<"Song Successfully Removed!"<<endl;
                plag=1;
            }
        }
        if(plag==0){
            cout<<"Song Not found in playlist!"<<endl;
        }
    }

    void play(string name){
        int plag=0;
        for(int i=0; i<n; i++){
            if(playList[i]==name){
                currentSong=name;
                cout<<"Song Found\nEnter to play!"<<endl;
                plag=1;
            }
        }
        if(plag==0){
            cout<<"Song Not found in playlist!";
        }
    }

    void display(){
        cout<<"Displaying PlayList: \n";
        for(int i=0; i<n; i++){
            cout<<"Song "<<i+1<<": "<<playList[i]<<endl;
        }
    }
};

int main(){
    MusicPlayer music;
    music.addsong("Obvious");
    music.play("Obvious");
    music.display();
    music.removeSong("Obvious");
    return 0;
}