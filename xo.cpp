#include <iostream>
using namespace std ;

void showscreen(char screen[]){
cout  <<" "<< screen[0] <<" | " <<screen[1] << " | " <<screen[2] ;
cout << "\n =========\n" ;
cout <<" " <<screen[3] <<" | " <<screen[4] << " | " <<screen[5] ;
cout << "\n =========\n" ;
cout <<" "<< screen[6] <<" | " <<screen[7] << " | " <<screen[8] ;
cout << "\n" ;
}
int gamestate(char screen[],char themove,int numbofmvs){

    for(int i=0;i<3;i++){
        if((screen[i]==themove && screen[i]==screen[i+3] && screen[i]==screen[i+6])|| (screen[3*i]==themove && screen[3*i]==screen[3*i+1] && screen[3*i]==screen[3*i+2])||(screen[0]==themove && screen[0]==screen[4] && screen[0]==screen[8])||(screen[2]==themove && screen[2]==screen[4] && screen[2]==screen[6]))
            {
          if(themove=='X')
            return 3 ;
         else if(themove=='O')
            return 1 ;
            }

    }
    if(numbofmvs==9)
        return 2 ;
    else
        return 0 ;
}
// aclosol is a func to deal with the case where the is one last move to an end it either make a win or avoid a close lost
int aclosol(char screen[],char mv){
    // mv is just a var made to replace x and o to avoid dupl work
    for(int i=0;i<3;i++){
        if(screen[3*i]==screen[3*i+1] && screen[3*i+2]=='.' && screen[3*i]==mv){
            screen[3*i+2]='O' ;
            return 1 ;
        }
    }
    for(int i=0;i<3;i++){
        if(screen[3*i]==screen[3*i+2] && screen[3*i+1]=='.' && screen[3*i]==mv){
            screen[3*i+1]='O' ;
            return 1 ;
        }
    }
    for(int i=0;i<3;i++){
        if(screen[3*i+2]==screen[3*i+1] && screen[3*i]=='.' && screen[3*i+1]==mv){
            screen[3*i]='O' ;
           return 1 ;
        }
    }
    for(int i=0;i<3;i++){
        if(screen[i]==screen[i+3] && screen[i+6]=='.' && screen[i]==mv){
            screen[i+6]='O' ;
            return 1 ;
        }
    }
    for(int i=0;i<3;i++){
        if(screen[i]==screen[i+6] && screen[i+3]=='.' && screen[i]==mv){
            screen[i+3]='O' ;
            return 1 ;
        }
    }
    for(int i=0;i<3;i++){
        if(screen[i+6]==screen[i+3] && screen[i]=='.' && screen[i+3]==mv){
            screen[i]='O' ;
            return 1 ;
        }
    }
    if(screen[0]==screen[4] && screen[8]=='.' && screen[0]==mv){
        screen[8]='O' ;
        return 1 ;
    }
    if(screen[0]==screen[8] && screen[4]=='.' && screen[0]==mv){
        screen[4]='O' ;
        return 1 ;
    }
    if(screen[4]==screen[8] && screen[0]=='.' && screen[4]==mv){
        screen[0]='O' ;
        return 1 ;
    }


    return 0 ;

}

void aimove(char screen[]){

        if(screen[4]=='.'){// get the middle
             screen[4]='O' ;
             return ;
        }

        if(aclosol(screen,'O')==1) // putting the func in a con i will call it
        return ;
        if(aclosol(screen,'X')==1)
        return ;

   for(int i=0;i<5;i++){
            if(screen[2*i]=='.' && i!=2){
                screen[2*i]='O' ;
            return ;
            }
             }
             for(int i=0;i<4;i++){
                if(screen[2*i+1]=='.'){
                    screen[2*i+1]='O' ;
                return ;
                 }
            }


    }

int main(){
    int numbofmvs=0 ;
    int chosenpos ;
    char screen[9] ;
    for(int i=0;i<9;i++){
             screen[i] = '.';
    }
    showscreen(screen) ;
   do{

    do{
            cout << "\n enter the coords man (1-9)" ;
        cin >> chosenpos;
        chosenpos-- ;
        }while(!(screen[chosenpos]=='.' && chosenpos <9 && chosenpos>=0 )) ;
    screen[chosenpos] = 'X' ;
    showscreen(screen) ;
    numbofmvs ++ ;

    if(gamestate(screen,'X',numbofmvs)==0){
    cout << "now opponent move \n" ;
    aimove(screen) ;
    showscreen(screen) ;
    numbofmvs ++ ;
    }

    }while(gamestate(screen,'X',numbofmvs)==0 && gamestate(screen,'O',numbofmvs)==0 ) ;

    if(gamestate(screen,'X',numbofmvs)==3)
    cout << "congratulation man you won " ;
     else if(gamestate(screen,'O',numbofmvs)==1)
     cout << "try again " ;
     else
      cout << "a tie great performance maan any but still considered a loss" ;
      
      cout << " made by yanis hassaini in 2025 \n" ;

}
