/*
this is the start to making a terminal-based game in C++,
the game will be a medieval style adventure game
where players may choose a class to journey to find and
vanquish an evil king who raises the dead. Explore the lands of
Lokasten and fight the risen dead and other devious enemies to reach the evil king
and cleanse the land of darkness.
*/
#include <iostream>

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

};

void startGame()
{
    string userplays;   //user will be prompted to start game

    //let's start simple with basic intro to the game
    //and prompting the user to play
    cout << "\ntype 'exit' to exit the game at any time\n\nWelcome to Dark Kingdom!\npress the enter key to play!\n" << endl;
    getline(cin,userplays);

    int _class; //user chooses class at beginning of game
    CharacterClass charClass;   //adventurer class 
    while(userplays == "")//user hits enter key
    {
        cout << "Greetings adventurer! Please choose a class to begin your journey."<<endl;
        cout << "(1) Lucien the Knight\n(2) Alagant the Mage\n(3) Reeva the Archer" << endl;
        cin >> _class;
        switch (_class)
        {
            case (1):
            {
                charClass.setAttribute(1);  //knight class
                break;
            }
            case(2):
            {
                charClass.setAttribute(2);  //mage class
                break;
            }
            case(3):
            {
                charClass.setAttribute(3);  //archer class
                break;
            }
        }
        cout << "\n\nWelcome to Lokasten, " << charClass.name << "!\nHave your wits about you, this land is dangerous..." << endl;
        break;
    }
}

int main()
{
    //game driver
    startGame();
    return 0;
}
