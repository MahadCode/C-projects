//C program to move of Tower of hanoi
#include<stdio.h>
void move(int,int,int,int);

int main(){

int disk;
printf("Enter the number of disks:\n");
scanf("%d", &disk);

if(disk>0){  //input validation

int check=1;
while(check){  
  int initial_peg;
  printf("Enter Initial Peg:\n");
  scanf("%d", &initial_peg);

  int final_peg;
  printf("Enter Final Peg:\n");
  scanf("%d", &final_peg);

  int temporary_peg;
  printf("Enter Temporary Peg:\n");
  scanf("%d", &temporary_peg);

  if((initial_peg>0 && initial_peg<4) && (final_peg>0 && final_peg<4) && (temporary_peg>0 && temporary_peg<4) && (initial_peg!=final_peg) && (initial_peg!=temporary_peg) && (final_peg!=temporary_peg)){
     printf("\nSeries of Moves:\n");
     move(disk,initial_peg,final_peg,temporary_peg);
     check=0;
  }
  else{
     printf("Invalid Input!\nInputs for three pegs are same or not in range(1 to 3)!\nTry Again!\n\n");
  }  
}
}
else{
  printf("Invalid Disk Number!\nAgain Run the program\n");
}
  
}


void move(int disk,int ip,int fp,int tp){
   if(disk==0){
    return;
   }
   move(disk-1,ip,tp,fp);
   printf("%d --> %d\n", ip,fp);
   move(disk-1,tp,fp,ip);
}