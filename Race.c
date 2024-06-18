//C program to start race between hare and tortoise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 70
void movementTortoise(char t[],int *tortiseptr);
void movementHare(char t[],int *hareptr);
int getpercentage();

int main(){
    srand(time(NULL));

    char track[SIZE];

    for(size_t i=0; i<SIZE; i++){
        track[i]=' ';
    }

    int finish=1;

    while(finish){  //this loop will iterate again if both contender didn't finish the race

    //both tortise and hare are intialized to square 1
    int trackTortise=0;  
    int trackHare=0;

    printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");
    for(int i=0; i<SIZE; i++){
        movementTortoise(track,&trackTortise);

        movementHare(track,&trackHare);
        
        //if both reach the finish line i am favouring the tortise 
        if(trackTortise>=70){
            printf("TORTOISE WINS!!!YAY!!!\n");
            finish=0;
            break;
        }
        else if(trackHare>=70){
            printf("Hare wins. Yuch.\n");
            finish=0;
            break;
        }
        
        //if both are at same position then printing OUCH
        if(trackTortise==trackHare){
         printf("OUCH!!\n");    
        }
        else{   //otherwise printing the track
         //printf("%s\n", track);
          for(size_t i=0; i<SIZE; i++){
             printf("%c", track[i]);
          }
          puts("");
        }


        track[trackTortise]=' ';
        track[trackHare]=' ';
    }
    
    if(finish){
        printf("Both contender didn't finish the race!\nRACE AGAIN!!!!\n");
    }

    }
}

//it will determine the movement of Hare
void movementTortoise(char t[],int *tortiseptr){
    int percentage=getpercentage(); //it will determine percentage depend on random number it get

    if(percentage<=4){
        *tortiseptr+=3;
    }
    else if(percentage<=6){
        *tortiseptr-=6;
    }
    else{
        *tortiseptr+=1;
    }

    if(*tortiseptr<=0){
        *tortiseptr=1;
    }

    t[*tortiseptr]='T';
}

//it will determine the movement of Hare
void movementHare(char t[],int *hareptr){
    int percentage=getpercentage(); //it will determine percentage depend on random number it get

    if(percentage<=1){
    }
    else if(percentage<=3){
        *hareptr+=9;
    }
    else if(percentage<=4){
        *hareptr-=12;
    }
    else if(percentage<=7){
        *hareptr+=1;
    }
    else{
        *hareptr-=2;
    }

    if(*hareptr<=0){
        *hareptr=1;
    }

    t[*hareptr]='H';
}

//This function gives a random range from 0 to 9
int getpercentage(){
   return rand()%10;
}
