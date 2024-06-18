#include<stdio.h>
void printboard(int board[]);
int check(int arr[]);

//main function begins here
int main(){
   //Defining 'arr' array which will store users' inputs and will also display the numbers on board of game
   int arr[]={'0','1','2','3','4','5','6','7','8','9'};
   //Calling printboard function
   printboard(arr);
   //'i' variable is used as loop countrol varaible
   int i=1;

   int player;
   //'same' array will store no. of those boxes which are filled by players          
   int same[9];
   //while loop starts here
   while(i<=9){
    //Deciding it's 1st player's turn or 2nd
    if(i%2==0){
        player=2;
    }
    else{
        player=1;
    }

    //if it's player1's turn then mark=X otherwise mark=O
    char mark=(player==1) ? 'X' : 'O';
    
    //Taking input from  players
    int n;
    printf("Player%d's Turn:  ", player);
    scanf("%d", &n);
    
    //'input' variable check either input box number is new or equals to earlier ones
    int input=1;
    //This logic will check new input number 'n' is not inputed by users earlier with help of 'same' array and will store decision in 'input' variable
    for(int j=0; j<i-1; j++){
        if(n==same[j]){
           input=0;
        }
    }
    
    //if statment for checking n is btw given no. of boxes
    if(n>=1 && n<=9){
        //if statment for checking 'input' varaible validation
        if(input){
            arr[n]=mark;         //assigning inputted box no. the mark of current player
            printboard(arr);    
            same[i-1]=n;
            //checking if anyplayer has won or not
            if (check(arr)==1){
               printf("PLAYER%d HAS WON THE GAME!\n", player);
               i=9;
            }
            i++;
        }//2nd if end
        else{
            printf("\n\nInvalid Input!This box is already filled!\n\n\n");
        }
    }//1st if ends here
    else{
      printf("\n\nInvalid Input!This box doesn't exist!\n\n\n");
    }
    //if this is last iteration, then printing game has ended
    if(i==10){
        printf("GAME HAS ENDED!\n");
    }
   }
   return 0;
}//main function ends here

//printboard function is used to print the pattern(board) of game
void printboard(int board[]){
    printf("\n\n\n===TIC TAC TOE===\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7],board[8],board[9]);
    printf("     |     |     \n\n");
}

//check function will return 1 if any player has won otherwise it will return 0
int check(int arr[]){
    if ((arr[1]==arr[2] && arr[1]==arr[3]) || (arr[4]==arr[5] && arr[4]==arr[6]) || (arr[7]==arr[8] && arr[7]==arr[9]) || (arr[1]==arr[4] && arr[1]==arr[7]) || (arr[2]==arr[5] && arr[2]==arr[8]) || (arr[3]==arr[6] && arr[3]==arr[9]) || (arr[1]==arr[5] && arr[1]==arr[9]) ||(arr[3]==arr[5] && arr[3]==arr[7])){
        return 1;
    }
    else{
        return 0;
    }
}

