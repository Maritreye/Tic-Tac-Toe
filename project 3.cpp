#include<bits/stdc++.h>
#include<ctime>
using namespace std;
void Board(char* spaces);

void Player(char* Spaces ,char player);

void Computer(char* Spaces,char computer);

bool Win(char* Spaces,char player,char Computer);

bool Tie(char* Spaces);


int main()
{
char Spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

char player='X';

char computer='O';

bool Running=true;

Board(Spaces);

while (Running)
{
    Player(Spaces,player);

    Board(Spaces);

    if(Win(Spaces, player, computer))
    {
        Running = false;
        break;
    }
    else if(Tie(Spaces))
    {
        Running = false;
        break;
    }

    Computer(Spaces,computer);  

    Board(Spaces);
    
    if(Win(Spaces, player, computer))
    {
        Running = false;
        break;
    }
    else if(Tie(Spaces))
    {
        Running = false;
        break;
    }
}
return 0;
}
void Board(char* Spaces)
{
cout<<"     |     |     "<<endl;
cout<<"  "<<Spaces[0]<<"  |  "<<Spaces[1]<<"  |  "<<Spaces[2]<<"  "<<endl;
cout<<"     |     |     "<<endl;
cout<<"-----------------"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<Spaces[3]<<"  |  "<<Spaces[4]<<"  |  "<<Spaces[5]<<"  "<<endl;
cout<<"     |     |     "<<endl;
cout<<"-----------------"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<Spaces[6]<<"  |  "<<Spaces[7]<<"  |  "<<Spaces[8]<<"  "<<endl;
cout<<"     |     |     "<<endl;


}
void Player(char* Spaces, char player)
{
    int i;
    cin >> i;
    i--;
    while (i >= 0 && i < 9)  
    { 
        if (Spaces[i] == ' ')
        {
            Spaces[i] = player;
            break;
        }
        else
        {
            cout << "Invalid move! Try again: ";
            cin >> i;
            i--;
        }
    }
}


void Computer(char* Spaces,char computer)
{   int i;
    srand(time(0));
    while(true)
    {
        i = rand() % 9;
        if(Spaces[i] == ' ')
        {
            Spaces[i] = computer;
            break;
        }
        }
}
bool Win(char* Spaces,char player,char Computer)
{
     if((Spaces[0] != ' ') && (Spaces[0] == Spaces[1]) && (Spaces[1] == Spaces[2])){
        Spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[3] != ' ') && (Spaces[3] == Spaces[4]) && (Spaces[4] == Spaces[5])){
        Spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[6] != ' ') && (Spaces[6] == Spaces[7]) && (Spaces[7] == Spaces[8])){
        Spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[0] != ' ') && (Spaces[0] == Spaces[3]) && (Spaces[3] == Spaces[6])){
        Spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[1] != ' ') && (Spaces[1] == Spaces[4]) && (Spaces[4] == Spaces[7])){
        Spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[2] != ' ') && (Spaces[2] == Spaces[5]) && (Spaces[5] == Spaces[8])){
        Spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[0] != ' ') && (Spaces[0] == Spaces[4]) && (Spaces[4] == Spaces[8])){
        Spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if((Spaces[2] != ' ') && (Spaces[2] == Spaces[4]) && (Spaces[4] == Spaces[6])){
        Spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else{
        return false;
    
    }
    return true;
}
bool Tie(char* Spaces)
{
    for(int i = 0; i < 9; i++)
{
        if(Spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}
