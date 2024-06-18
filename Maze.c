#include<stdio.h>
#define SIZE 12
void printarray(const char maze[SIZE][SIZE]);
void recursivemaze(char maze[][SIZE],int x,int y);

//These constants are defined just to make the program more readable
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
//This 'cd' varaible store the current direction
int cd=RIGHT;


int main(){
    char maze[SIZE][SIZE]={{'#','#','#','#','#','#','#','#','#','#','#','#'},
                           {'#','.','.','.','#','.','.','.','.','.','.','#'},
                           {'.','.','#','.','#','.','#','#','#','#','.','#'},
                           {'#','#','#','.','#','.','.','.','.','#','.','#'},
                           {'#','.','.','.','.','#','#','#','.','#','.','.'},
                           {'#','#','#','#','.','#','.','#','.','#','.','#'},
                           {'#','.','.','#','.','#','.','#','.','#','.','#'},
                           {'#','#','.','#','.','#','.','#','.','#','.','#'},
                           {'#','.','.','.','.','.','.','.','.','#','.','#'},
                           {'#','#','#','#','#','#','.','#','#','#','.','#'},
                           {'#','.','.','.','.','.','.','#','.','.','.','#'},
                           {'#','#','#','#','#','#','#','#','#','#','#','#'},};
    
    
    
    
    recursivemaze(maze,2,0);
   
    
}

void printarray(const char maze[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%c ", maze[i][j]);
        }
        puts("");
    }
    puts("\n");

}

void recursivemaze(char maze[SIZE][SIZE],int x,int y){
   
   //storing x in current location 
   maze[x][y]='x';
   printarray(maze);   //printing the maze
   maze[x][y]='.';  //removing x from current location

   
   if(x==4 && y==11){  //if maze has finished ending the program
    printf("Maze has Completed!\n");
    return;
   } 
   

   //handling the case according to the conditon and current direction
   switch(cd){
    case UP:
     {
       if(maze[x][y+1]=='.'){
        y++;
        cd=RIGHT;
       } 
       else if(maze[x-1][y]=='.'){
        x--;
       }
       else if(maze[x][y-1]=='.'){
        y--;
        cd=LEFT;
       }
       else{
        x++;
        cd=DOWN;
       }
     }
     break;
    case RIGHT:
      {
       if(maze[x+1][y]=='.'){
        x++;
        cd=DOWN;
       } 
       else if(maze[x][y+1]=='.'){
        y++;
       }
       else if(maze[x-1][y]=='.'){
        x--;
        cd=UP;
       }
       else{
        y--;
        cd=LEFT;
       }
      }
      break;
    case DOWN:
      {
       if(maze[x][y-1]=='.'){
        y--;
        cd=LEFT;
       } 
       else if(maze[x+1][y]=='.'){
        x++;
       }
       else if(maze[x][y+1]=='.'){
        y++;
        cd=RIGHT;
       }
       else{
        x--;
        cd=UP;
       }
      }
      break;
    case LEFT:
      {
       if(maze[x-1][y]=='.'){
        x--;
        cd=UP;
       } 
       else if(maze[x][y-1]=='.'){
        y--;
       }
       else if(maze[x+1][y]=='.'){
        x++;
        cd=DOWN;
       }
       else{
        y++;
        cd=RIGHT;
       }
      }
      break;
   }

   recursivemaze(maze,x,y);  //recursive call to function
}