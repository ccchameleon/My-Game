/*
this is the start to making a terminal-based game in C++,
the game will be a medieval style adventure game
where players may choose a class to journey to find and
vanquish an evil king who raises the dead. Explore the lands of
Lokasten and fight the risen dead and other devious enemies to reach the evil king
and cleanse the land of darkness.
*/
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <hash_map>

using namespace std;

class CharacterClass{
    private:
        int health = 10; //health points for all classes
        int strength = 0;  //buffness for knights
        int MP = 0;   //magic points for mages
        int arrows = 0; //arrows for archers

    public:
        string name;    //name of adventurer

        void setAttribute(int classType) //set attribute based on class
        {
            //1 = knight, 2 = mage, 3 = archer
            if(classType == 1)
            {
                name = "Lucien";
                strength += 10;    //knight class gets 10 strength
                cout << "\nYou chose Lucien the knight!"
                <<"\nKnights are the rock to any team, providing short range offense and defense."
                <<"\nKnight classes get 10 points in strength.";
            }
            if(classType == 2)
            {
                name = "Alagant";
                MP += 10;    //mage class gets 10 mp
                cout << "\nYou chose Alagant the Mage!"
                <<"\nMages help level the battle field with medium ranged magic and healing."
                <<"\nMage classes get 10 points in magic points.";
            }
            if(classType == 3)
            {
                name = "Reeva";
                arrows += 10;    //archer class gets 10 arrows
                cout << "\nYou chose Reeva the Archer!"
                <<"\nArchers provide support to a team with medium to long range attacks."
                <<"\nArcher classes begin with 10 arrows.";
            }
        }

        //recover attribute
        void recoverAmount(string attr, int amount)
        {
            if(attr == "health")
            {
                if( (health += amount) > 10)    //attributes will cap at 10
                {
                    cout << "cannot gain any more HP!" << endl;
                }else if((health += amount) <= 10)
                {
                    health += amount;
                }
            }else if(attr == "strength")
            {
                if( (strength += amount) > 10)
                {
                    cout << "cannot gain any more VR!" << endl;
                }else if((strength += amount) <= 10)
                {
                    strength += amount;
                }
            }else if(attr == "MP")
            {
                if( (MP += amount) > 10)
                {
                    cout << "cannot gain any more MP!" << endl;
                }else if((MP += amount) <= 10)
                {
                    MP += amount;
                }
            } else if(attr == "arrows")
            {
                if( (arrows += amount) > 10)
                {
                    cout << "cannot gain any more arrows!" << endl;
                }else if((arrows += amount) <= 10)
                {
                    arrows += amount;
                }
            }
        };

        //damage attribute
        void dmgAmount(string attr, int amount)


        {       
            if(attr == "health")
            {
                if( (health -= amount) <= 0)
                {
                    health -= amount;
                    cout << "you have perished!" << endl;
                }
                else
                {
                    health -= amount;
                    cout << "You have taken " << amount << " damage!"<<endl;
                }
            }else if(attr == "strength")
            {
                if( (strength -= amount) <= 0)
                {
                    cout << "you are defenseless!" << endl;
                }
            }else if(attr == "MP")
            {
                if( (MP -= amount) <= 0)
                {
                    cout << "you have no magic points left!" << endl;
                }
            } else if(attr == "arrows")
            {
                if( (arrows -= amount) <= 0)
                {
                    cout << "you have no arrows left!" << endl;
                }
            }
        };

    void classIntro(int classType){
        switch (classType)
        {
            case 1:
            cout << "\n\n\n\n\n"
             "\"Awaken, Lucien.\"\nYou feel the sound of hundreds of voices wake you to life.\n Beginning to move, you slowly open your eyes and survey the area surrounding your body with your muddled hands.\n You are completely soaked save for your face. Looking around with newfound life, you notice you are partially floating in a dim land.\n You struggle off your back using your hands and feet to prop yourself up.\n Realizing that you are in a marshland, you wonder \"How did I end up here?\"" 
             << "\n You brush off the thought as you gain your balance.\n\nYou look to just beyond your shoulder and see dead bodies littered in the swampy waters.\n Just in front of you, you see a gleaming light shining off what looks like the hilt of a blade.\n Will you take it?"<< endl;
             takeAction(1);
             cout <<"\n\n\n\n\n";
             break;
             default:
                cout << "\nNot a valid selection\n" << endl;
                // startGame();
        } 
    };

    void takeAction(int classType){
        string _userinput;
        switch (classType){
            case 1:
            cout <<"\t1  Yes"<<"\n\t2  No"<<endl;
            getline(cin,_userinput);
            while(_userinput != ""){
                if(_userinput == "1"){
                    cout << "You grab the blade." << endl;
                }
            default:
            return;
            }
        }
    };

};




void startGame()
{
    string user_play;   //user will be prompted to start game

    //let's start simple with basic intro to the game
    //and prompting the user to play
    cout << "\ntype 'exit' to exit the game at any time\n\nWelcome to Dark Kingdom!\nPress the enter key to play!\n" << endl;
    getline(cin,user_play);

    int _class; //user chooses class at beginning of game
    CharacterClass charClass;   //adventurer class 
    if(user_play == "")//user hits enter key
    {
        cout << "Greetings adventurer! Please choose a class to begin your journey."<<endl;
        cout << "(1) Lucien the Knight\n(2) Alagant the Mage\n(3) Reeva the Archer" << endl;
        cin >> _class;
        switch (_class)
        {
            case (1):
            {
                charClass.setAttribute(1);  //knight class
                charClass.classIntro(1);
                break;
            }
            case(2):
            {
                charClass.setAttribute(2);  //mage class
                charClass.classIntro(2);
                break;
            }
            case(3):
            {
                charClass.setAttribute(3);  //archer class
                break;
            }
            default:
            startGame();
        }
        // classIntro;
        return;
    }else{
        startGame();
    }
}

int main()
{
    //game driver
    startGame();
    return 0;
}
