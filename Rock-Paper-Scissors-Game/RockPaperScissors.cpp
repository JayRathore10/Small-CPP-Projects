#include<iostream>
#include<ctime>
#include<limits>
#include<iomanip>
#include<cstdlib>

using namespace std;

class RockPaperScissors{
    private:
        int playerMove;
        int computerMove;
    
    public:
        RockPaperScissors(int playerMove){
            this->playerMove = playerMove;
        }

        int randomNumber(){
            return (rand()%3 + 1);
        }
        void game(){
            int computerMove = randomNumber();
            cout<<string(110 , '-')<<endl;
            if(computerMove == 1){
                if(playerMove == 1){
                    cout<<" $ Draw $ "<<endl;
                }else if (playerMove == 2){
                    cout<<" $ Player Win $ "<<endl;
                }else if (playerMove == 3){
                    cout<<" $ Computer Win $ "<<endl;
                }
            }else if (computerMove == 2){
                if(playerMove == 1){
                    cout<<" $ Computer Win $ "<<endl;
                }else if (playerMove == 2){
                    cout<<" $ Draw $ "<<endl;
                }else if (playerMove == 3){
                    cout<<" $ Player Win $ "<<endl;
                }
            }else if (computerMove == 3){
                if(playerMove == 1){
                    cout<<" $ Player Win $ "<<endl;
                }else if (playerMove == 2){
                    cout<<" $ Computer Win $ "<<endl;
                }else if (playerMove == 3){
                    cout<<" $ Draw $ "<<endl;
                }
            }
            cout<<string(110 , '-')<<endl;
        }
};

int main(){
    srand(time(0));
    cout<<setw(51)<<"WELCOME TO !!! "<<endl;
    cout<<setw(55)<<" ROCK PAPER SCISSORS GAME "<<endl<<setw(57)<<"-----------------------------"<<endl;
    repeat:
    cout<<setw(7)<<"Enter 1 for Rock"<<endl
        <<setw(7)<<"Enter 2 for Paper"<<endl
        <<setw(7)<<"Enter 3 for Scissors"<<endl
        <<setw(2)<<"-> ";
    int input;
    cin>>input;
    if( cin.fail() ||input < 1 || input > 3){
        cout<<"You enter a invalid input "<<endl<<"Enter Again ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        goto repeat;
    }
    RockPaperScissors game1(input);
    game1.game();
    char c ;
        cout<<"You want to play more "<<endl
            <<"Enter y for yes or n for no"<<endl;
        cin>>c;
        cout<<string(110 , '-')<<endl;
        if(c == 'y'){
            cout<<setw(50)<<"GAME START AGAIN! "<<setw(50)<<endl;
            cout<<string(110 , '-')<<endl;
            goto repeat;
        }else{
            cout<<setw(50)<<"THANK YOU FOR PLAYING"<<setw(50)<<endl;
            cout<<string(110 , '-')<<endl;
            return 0 ;
        }
       
    return 0;
}