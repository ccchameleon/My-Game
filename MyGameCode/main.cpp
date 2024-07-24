
#include "lib.h"


void startGame()
{
    string user_play;
    //prompt user to play
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
