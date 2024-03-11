#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;
void drawboard(char *spaces);
void playermove(char *spaces, char player);
void computermove(char *spaces, char computer);
bool checkwinner(char *spaces, char player, char computer);
bool checktie(char *spaces);

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
}

int main()
{
char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char player='x';
char computer='o';
bool running =true;

drawboard(spaces);
while(running){
    playermove(spaces, player);
    drawboard(spaces);
    if(checkwinner(spaces, player, computer)){
        running=false;
        break;
    }
    else if(checktie(spaces)){
        running=false;
        break;
    }

    computermove(spaces, computer);
    drawboard(spaces);
      if(checkwinner(spaces, player, computer)){
        running=false;
        break;
    }
    else if(checktie(spaces)){
        running=false;
        break;
    }
}
cout<<"THANKS FOR PLAYING\n";
return 0;
}

void drawboard(char *spaces){
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
cout<<"_____|_____|_____"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
cout<<"_____|_____|_____"<<endl;
cout<<"     |     |     "<<endl;
cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
cout<<"     |     |     "<<endl;
cout<<endl;
}
void playermove(char *spaces, char player){
    int number;
        do{
        cout<<"enter a spot to place a maker(1-9) ";
        cin>>number; 
        number--;
            if (spaces[number]==' '){
                spaces[number]=player;
                break;
            }
        }while(!number>0||!number<8);
        clearScreen();
}
void computermove(char *spaces, char computer){
int number;
    srand(time(0));
    while(true){
        number=rand()%9;
        if (spaces[number]==' '){
            spaces[number]=computer;
            break;
        }
    }
}
bool checkwinner(char *spaces, char player, char computer){
    if(spaces[0]!=' '&&spaces[0]==spaces[1]&&spaces[1]==spaces[2]){
        spaces[0]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[3]!=' '&&spaces[3]==spaces[4]&&spaces[4]==spaces[5]){
        spaces[3]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[6]!=' '&&spaces[6]==spaces[7]&&spaces[7]==spaces[8]){
        spaces[6]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[0]!=' '&&spaces[0]==spaces[3]&&spaces[3]==spaces[6]){
        spaces[0]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[1]!=' '&&spaces[1]==spaces[4]&&spaces[4]==spaces[7]){
        spaces[1]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[2]!=' '&&spaces[2]==spaces[5]&&spaces[5]==spaces[8]){
        spaces[2]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[0]!=' '&&spaces[0]==spaces[4]&&spaces[4]==spaces[8]){
        spaces[0]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else if(spaces[2]!=' '&&spaces[2]==spaces[4]&&spaces[4]==spaces[6]){
        spaces[2]==player ? cout<<"YOU WON\n" : cout<<"YOU LOSE!\n";
    }else{return false;}
return true;
}
bool checktie(char *spaces){
    
    for(int i=0; i<9; i++){
        if (spaces[i]==' '){
            return false;
        }
    }
    cout<<"IT'S A TIE\n";
    return true;
}