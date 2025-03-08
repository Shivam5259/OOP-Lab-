#include <iostream>
#include <string>
using namespace std;

class Level{
public:
    string levelName;
    int difficulty;

    Level(string name, int diff): levelName(name), difficulty(diff){}
    Level(){}

    void display(){
        cout<<"Level: "<<levelName<<", Difficulty: "<<difficulty<<endl;
    }

};

class Game{
public:
    string title;
    string genre;
    Level* levels;
    int levelCount;

    Game(string title, string genre, Level* lvl, int count): title(title), genre(genre){
        levelCount=count;
        levels = new Level[levelCount];
        for(int i=0; i<levelCount; i++){
            levels[i]=lvl[i];
        }
        // levels=lvl;
    }

    void display(){
        cout<<"Game Title: "<<title<<endl;
        cout<<"Game Genre: "<<genre<<endl;
        cout<<"Levels: "<<endl;
        for(int i=0; i<levelCount; i++){
            levels[i].display();
        }
    }

};

int main(){
    Level levelData[]={ Level("Erangle", 3), Level("Livik", 5)};
    Game game("Pubg", "Assult", levelData, 2);

    game.display();
    game.display();
    return 0;
}