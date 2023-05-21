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
        map<string,string> inventory;

    public:
        string name;    //name of adventurer
        string vials;   //key for vials in map
        string vialContents;    //value for vials in map
        int _response;          //used in decision making
        string gameOver = "Game Over!";


        void setAttribute(int classType) //set attribute based on class
        {
            //1 = knight, 2 = mage, 3 = archer
            if(classType == 1)
            {
                name = "Lucien";
                strength += 10;    //knight class gets 10 strength
                cout << "\nYou chose Lucien the knight!";
                Sleep(750);
                cout<<"\nKnights are the rock to any team, providing short range offense and defense.";
                Sleep(750);
                cout<<"\nKnight classes get 10 points in strength.";
            }
            if(classType == 2)
            {
                name = "Alagant";
                MP += 10;    //mage class gets 10 mp
                cout << "\nYou chose Alagant the Mage!";
                Sleep(750);
                cout<<"\nMages help level the battle field with medium ranged magic and healing.";
                Sleep(750);
                cout<<"\nMage classes get 10 points in magic points.";
            }
            if(classType == 3)
            {
                name = "Reeva";
                arrows += 10;    //archer class gets 10 arrows
                cout << "\nYou chose Reeva the Archer!";
                Sleep(750);
                cout<<"\nArchers provide support to a team with medium to long range attacks.";
                Sleep(750);
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
        void dmgAmount(std::string attr, int amount)
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
                    cout << "You have taken " << amount << " points of damage!"<<endl;
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

    


void story(int charSelect)
{

    switch(charSelect)
    {
        case(1):    //Lucien introduction
        cout << "\n\nYou wake up in a dark and damp place, lying in freezing cold mud, being somewhat covered in it.";
        Sleep(750);
        cout << "\nThe right side of your temple is throbbing in agonizing pain.";
        Sleep(750);
        cout << "\nWhile you hold it with one hand, you use the other to prop yourself up.";
        Sleep(750);
        cout << "\nYou realize you are in some sort of tunnel.";
        Sleep(750);
        cout << "\nWhile struggling to get back on your feet you notice a faint light ahead and ponder if it is worth checking.";
        Sleep(750);
        
        cout << "\n\nWill you move towards the light?\n(1) Yes\n(2) No\n";

                                    //-------------------------CURRENT ISSUE--------------------------//
       
        while(cin >> _response){
        if(_response != 1 && _response != 2)
            cout << "Please select yes or no"<<endl;
        else
        break;
        }
        enum decision{yes=1,no=2};
        
        decision myResponse;
        myResponse = (decision)_response;

        cin.get();
        switch(_response)
        {
            //case for yes response
            case(yes):
            {
                Sleep(750);
                cout << "\nYou get yourself up out of the mud and begin moving toward the light.";Sleep(750);
                cout << "\nStill holding your head, you trudge along a muddy well way while feeling for any wounds on your body.";Sleep(750);
                cout << "\nYou feel along your waist and notice a vial. You grab it and shake it.";Sleep(750);
                cout << "\nAs it sloshes back and forth, you figure you could use it in a time of need, but do not know what it is.";Sleep(750);
                vialContents = "Mystery Liquid";Sleep(750);
                cout << "\n+1 Vial of " << vialContents;
                inventory.emplace(vials,vialContents);
                // cout << "\nInventory: " << inventory.at(vials);    //testing map
                
                
                
                break;
            }
            //case for no response1
            case(no):
            {
                cout << "\nYou turn around and wander in the dark for what feels like ages.";Sleep(750);
                cout << "\nSuddenly you are met with a unidentifiable yet very angry creature.";Sleep(750);
                cout << "\nWould you like to challenge this creature or run away?";Sleep(750);
                cout << "\n(1) Challenge\n(2) Run Away\n";
                while(cin >> _response){
                if(_response != 1 && _response != 2)
                {
                    Sleep(750);
                    cout << "Please select Challenge or Run Away"<<endl;
                }
                else
                break;
                }
                switch(_response)
                {
                    case(yes):
                    Sleep(750);
                    cout << "Without light or any equipment you are useless to fight against this enemy.";Sleep(750);
                    cout << "\nIt rushes you and knocks you off of your feet.";Sleep(750);
                    cout << "\nYou land on your back, but hit your head on the way down.";Sleep(750);
                    cout << "\nYou are knocked unconcious, and the creature proceeds to rip and tear away your limbs.";Sleep(750);
                    cout <<"\nYou have perished."<<endl;Sleep(750);
                    cout << gameOver << endl;
                    break;
                    case(no):
                    cout << "\nYou run as fast as you can in the opposite direction.";Sleep(750);
                    cout << "\nAs you start to run out of breath, you feel safer knowing you are away from";
                    cout << " whatever was about to ruin your day.";Sleep(750);
                    break;
                }
                // cout << "\nGame Over!" << endl;  //game over ending
                 
                break;
            }
            
            default:
                break;
        }
    }
}

};

void startGame()
{
    std::string userplays;   //user will be prompted to start game

    //let's start simple with basic intro to the game
    //and prompting the user to play

    int _class; //user chooses class at beginning of game
    CharacterClass charClass;   //adventurer class 

    Sleep(750);
    cout << "\nType 'exit' to exit the game at any time\n\nWelcome to Evolem!";
    Sleep(750);
    cout << "\npress the enter key to play!" << endl;
    std::getline(std::cin,userplays);
    if(userplays != ""){
        while(userplays != "")
        {
            if(userplays == "exit")
            exit(1);
            cout << "\npress the enter key to play!" << endl;
            std::getline(std::cin,userplays);
        }
    }
    else if(userplays == "exit")
    {
        exit(1);
    }

        Sleep(750);
        cout << "\nYou start your journey somewhere in Lokasten, a region once brimming with life";
        Sleep(750);
        cout << "\nand prosperity. The Mad Queen, Nadoa, has taken the throne after King Jontir's passing.";
        Sleep(750);
        cout << "\nNo one knows exactly what happened, but many believe it was her blind worship";
        Sleep(750);
        cout << "\nto what she calls the \"Great Overseer\" that plunged Lokasten into chaos.";
        Sleep(750);
        cout << "\nHave your wits about you, it is now a dangerous wasteland..." << endl;
        Sleep(750);
        cout << "Please choose a class to begin your journey."<<endl;Sleep(750);
        cout << "\n(1) Lucien the Knight - CURRENT TEST";
        cout <<"\n(2) Alagant the Mage";
        cout << "\n(3) Reeva the Archer" << endl;
  
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
}

int main()
{
    //game driver
    startGame();
    return 0;//finish game
}