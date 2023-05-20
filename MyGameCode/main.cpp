/*
this is the start to making a terminal-based game in C++,
the game will be a medieval style adventure game
where players may choose a class to journey to find and
vanquish an evil king who raises the dead. Explore the lands of
Lokasten and fight the risen dead and other devious enemies to reach the evil king
and cleanse the land of darkness.
*/
#include <iostream>
#include <windows.h>    //for sleep util
#include <map>

using namespace std;


class CharacterClass{
    private:
        int health = 10; //health points for all classes
        int strength = 0;  //buffness for knights
        int MP = 0;   //magic points for mages
        int arrows = 0; //arrows for archers

    public:
        std::string name;    //name of adventurer

        void setAttribute(int classType) //set attribute based on class
        {
            //1 = knight, 2 = mage, 3 = archer
            if(classType == 1)
            {
                name = "Lucien";
                strength += 10;    //knight class gets 10 strength
                cout << "\nYou chose Lucien the knight!";
                Sleep(100);
                cout<<"\nKnights are the rock to any team, providing short range offense and defense.";
                Sleep(100);
                cout<<"\nKnight classes get 10 points in strength.";
            }
            if(classType == 2)
            {
                name = "Alagant";
                MP += 10;    //mage class gets 10 mp
                cout << "\nYou chose Alagant the Mage!";
                Sleep(100);
                cout<<"\nMages help level the battle field with medium ranged magic and healing.";
                Sleep(100);
                cout<<"\nMage classes get 10 points in magic points.";
            }
            if(classType == 3)
            {
                name = "Reeva";
                arrows += 10;    //archer class gets 10 arrows
                cout << "\nYou chose Reeva the Archer!";
                Sleep(100);
                cout<<"\nArchers provide support to a team with medium to long range attacks.";
                Sleep(100);
                cout<<"\nArcher classes begin with 10 arrows.";
            }
        }

        //recover attribute
        void recoverAmount(std::string attr, int amount)
        {
            if(attr == "health")
            {
                if( (health += amount) > 10)    //attributes will cap at 10
                {
                    cout << "cannot gain any more HP!" << std::endl;
                }else if((health += amount) <= 10)
                {
                    health += amount;
                }
            }else if(attr == "strength")
            {
                if( (strength += amount) > 10)
                {
                    cout << "cannot gain any more VR!" << std::endl;
                }else if((strength += amount) <= 10)
                {
                    strength += amount;
                }
            }else if(attr == "MP")
            {
                if( (MP += amount) > 10)
                {
                    cout << "cannot gain any more MP!" << std::endl;
                }else if((MP += amount) <= 10)
                {
                    MP += amount;
                }
            } else if(attr == "arrows")
            {
                if( (arrows += amount) > 10)
                {
                    cout << "cannot gain any more arrows!" << std::endl;
                }else if((arrows += amount) <= 10)
                {
                    arrows += amount;
                }
            }
        };

        //damage attribute
        void dmgAmount(std::string attr, int amount)
        {       
            if(attr == "health")
            {
                if( (health -= amount) <= 0)
                {
                    health -= amount;
                    cout << "you have perished!" << std::endl;
                }
                else
                {
                    health -= amount;
                    cout << "You have taken " << amount << " points of damage!"<<std::endl;
                }
            }else if(attr == "strength")
            {
                if( (strength -= amount) <= 0)
                {
                    cout << "you are defenseless!" << std::endl;
                }
            }else if(attr == "MP")
            {
                if( (MP -= amount) <= 0)
                {
                    cout << "you have no magic points left!" << std::endl;
                }
            } else if(attr == "arrows")
            {
                if( (arrows -= amount) <= 0)
                {
                    cout << "you have no arrows left!" << std::endl;
                }
            }
        };

    


void story(int charSelect)
{

    switch(charSelect)
    {
        case(1):    //Lucien introduction
        cout << "\n\nYou wake up in a dark and damp place, lying in freezing cold mud, being somewhat covered in it.";
        Sleep(100);
        cout << "\nThe right side of your temple is throbbing in agonizing pain.";
        Sleep(100);
        cout << "\nWhile you hold it with one hand, you use the other to prop yourself up.";
        Sleep(100);
        cout << "\nYou realize you are in some sort of tunnel.";
        Sleep(100);
        cout << "\nGetting back on your feet you notice a faint light ahead and ponder if it is worth checking.";
        Sleep(100);
        
        cout << "\nWill you move towards the light?\n1. Yes\n2. No\n";

                                    //-------------------------CURRENT ISSUE--------------------------//
        char userResponse;
        while(cin >> userResponse){
        if(userResponse != '1' && userResponse != '2')
            cout << "Please select yes or no"<<endl;
        else
        break;
        }
        enum decision{yes,no};
        
        decision myResponse;
        myResponse = (decision)userResponse;

        switch(userResponse)
        {
            //case for yes response
            case(0):
            {
            Sleep(100);
            cout << "\nYou get yourself up out of the mud and begin moving toward the light.";
            cout << "\nStill holding your head, you trudge along a muddy path and feel for any wounds on your body.";
                break;
            }
            //case for no response1
            case(1):
            {
                cout << "You turn around and wander in the dark for what feels like ages.";
                cout << "\nSuddenly you are met with a unidentifiable yet very angry creature.";
                cout << "\nIt grabs you by the face and sucks the soul out of your body!";
                Sleep(100);
                cout << "\nGame Over!" << endl;
                 
                break;
            }
            
            default:
                return;
        }
    }
}

};

int startGame()
{
    std::string userplays;   //user will be prompted to start game

    //let's start simple with basic intro to the game
    //and prompting the user to play
    Sleep(100);
    cout << "\ntype 'exit' to exit the game at any time\n\nWelcome to Dark Kingdom!";
    Sleep(100);
    cout << "\npress the enter key to play!\n" << std::endl;
    std::getline(std::cin,userplays);

    int _class; //user chooses class at beginning of game
    CharacterClass charClass;   //adventurer class 
        Sleep(100);
        cout << "\n\nWelcome to Lokasten, " << charClass.name;
        Sleep(100);
        cout << "!\nHave your wits about you, this land is dangerous..." << endl;
        Sleep(100);
    while(userplays == "")//user hits enter key
    {
        cout << "Greetings adventurer! Please choose a class to begin your journey."<<std::endl;
        cout << "(1) Lucien the Knight - CURRENT RUNNING\n(2) Alagant the Mage\n(3) Reeva the Archer" << std::endl;
        std::cin >> _class;
        switch (_class)
        {
            case (1):
            {
                charClass.setAttribute(1);  //knight class
                charClass.story(1);                      //will be used in future implementation for different introduction per character
                break;
            }
            case(2):
            {
                charClass.setAttribute(2);  //mage class
                charClass.story(2);                      //will be used in future implementation for different introduction per character
                break;
            }
            case(3):
            {
                charClass.setAttribute(3);  //archer class
                charClass.story(3);                      //will be used in future implementation for different introduction per character
                break;
            }
        default:
            break;
        }
    return -1;  //finish game
    }
}

int main()
{
    //game driver
    startGame();
    return 0;
}