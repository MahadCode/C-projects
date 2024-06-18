#include<stdio.h>
//These constants are defined just to make the program more readable
#define SIZE 10
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
void load(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr);
int execute(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr,int *branchptr,int *xptr,int *yptr);
void dump(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr);
int validinput(int n);

int main(){
     int accumulator = 0;
     int instructionCounter = 0;
     int instructionRegister = 0;
     int operationCode = 0;
     int operand = 0;

     int memory[SIZE][SIZE]={0};

     load(memory,&accumulator,&instructionCounter,&instructionRegister,&operationCode,&operand);

}


//load function takes input of dialog and also update registors
void load(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr){
    int input[100];
    while(*instructionCounterptr<=99){

      int branch=0; // if branching is performed is used to skip the sequential increament of instrucntion counter

      int hold;
      printf("%02d ? ", *instructionCounterptr);
      scanf("%d", &input[*instructionCounterptr]);

      //if user has entered the sentinal breaking the loop
      if(input[*instructionCounterptr]==(-99999)){    
        printf("*** You have entered Sentinal ***\n*** Simpletron execution terminated ***\n\n");
        dump(memory,accumulatorptr,instructionCounterptr,instructionRegisterptr,operationCodeptr,operandptr);
        break;
       }

       //updating the registors
       *instructionRegisterptr=input[*instructionCounterptr];
       *operationCodeptr=input[*instructionCounterptr]/100;
       *operandptr=input[*instructionCounterptr]%100;
       //These variable is used for purpose of 2d array 
       int x=(*operandptr)/10;   
       int y=(*operandptr)%10;
      
       //stop will check there is a fatal error or not      
       int stop=execute(memory,accumulatorptr,instructionCounterptr,instructionRegisterptr,operationCodeptr,operandptr,&branch,&x,&y);
       
       //if user face some fatal error
       if(stop==1){
        printf("*** Fatal Error ***\n*** Simpletron program execution abnormally terminated ***\n\n");
        dump(memory,accumulatorptr,instructionCounterptr,instructionRegisterptr,operationCodeptr,operandptr);
       }
       else if(stop==2){
        printf("*** Program loading completed ***\n*** Program execution begins ***\n\n");
        dump(memory,accumulatorptr,instructionCounterptr,instructionRegisterptr,operationCodeptr,operandptr);
       }


       if(branch==0){
       (*instructionCounterptr)++;}
      }
}

//execute function decode the dialog i.e command the user has entered and also update the memory and accumulator
int execute(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr,int *branchptr,int *xptr,int *yptr){
     int fatal=0;
     int temp;  //temporary holding place
     switch(*operationCodeptr){
         case READ:  //Read a number terminal
            printf("Enter an integer: ");
            scanf("%d", &temp);
            int check=validinput(temp);
             while(!check){
               printf("Number out of Range!\nEnter Again: ");
               scanf("%d", &temp);
               check=validinput(temp);
             }
            memory[*xptr][*yptr]=temp; 
           break;

         case WRITE:   //Display number from terminlal
           printf("%d\n", memory[*xptr][*yptr]);
           break;
           
         case LOAD: //load number from specific memory to accumulator
           (*accumulatorptr)=memory[*xptr][*yptr];
           break;

         case STORE:   //store number from accumulator to specific memory
           memory[*xptr][*yptr]=(*accumulatorptr);
           break;

         case ADD:  //add number to accumulator
           temp=(*accumulatorptr)+memory[*xptr][*yptr];
           if(validinput(temp))  (*accumulatorptr)=temp;
           else  fatal=1;
           break;

         case SUBTRACT:  //subtract number from accumulator
           temp=(*accumulatorptr)-memory[*xptr][*yptr];
           if(validinput(temp))  (*accumulatorptr)=temp;
           else  fatal=1;
           break;

         case MULTIPLY:  //multiply number to accumulator
           temp=(*accumulatorptr)*memory[*xptr][*yptr];
           if(validinput(temp))  (*accumulatorptr)=temp;
           else  fatal=1;
           break;
           
         case DIVIDE:  //Divide number to accumulator
           temp=(*accumulatorptr)/memory[*xptr][*yptr];
           if(validinput(temp))  (*accumulatorptr)=temp;
           else if(memory[*xptr][*yptr]==0){  
            printf("*** Attempt to divide by zero ***\n");
            fatal=1;}
           else  fatal=1;
           break;

         case BRANCH:    //branch
           (*instructionCounterptr)=(*operandptr);
           (*branchptr)=1;
           break;

         case BRANCHNEG:  //branch if accumulator is negative
           if(*accumulatorptr<0){
            (*instructionCounterptr)=(*operandptr);
            (*branchptr)=1;
           }
           break;

         case BRANCHZERO:  //branch if accumulator is zero
           if(*accumulatorptr==0){
            (*instructionCounterptr)=(*operandptr);
            (*branchptr)=1;
           }
           break;
        
         case HALT:  //if user enter halt
           fatal=2;
           break;
          
          default:   //if user has entered the invalid instruction or operation code
           printf("*** Invalid Operation Code ***\n");
           fatal=1;
           break;
       }
       return fatal;
}

//dump function is used to print the computer dump i.e memory on the screen
void dump(int memory[SIZE][SIZE],int *accumulatorptr,int *instructionCounterptr,int *instructionRegisterptr,int *operationCodeptr,int *operandptr){
      printf("REGISTERS:\naccumulator\t%+05d\n",  *accumulatorptr);
      printf("instructionCounter\t%02d\n", *instructionCounterptr);
      printf("instructionRegister\t%+05d\n",*instructionRegisterptr);
      printf("operationCode\t%02d\n",*operationCodeptr);
      printf("operand\t%02d\n\n", *operandptr);
      printf("Memory:\n");
      printf("\n");
      printf("%9d%7d%7d%7d%7d%7d%7d%7d%7d%7d\n", 0,1,2,3,4,5,6,7,8,9);
      for(size_t i=0; i<SIZE; i++){
        printf("%d0  ", i);
        for(size_t j=0; j<SIZE; j++){
          printf("%+05d  ", memory[i][j]);
        }
        puts("");
      }
      puts("\n");
}

//This is used to for input validation
int validinput(int n){
    if(n>9999 || n<(-9999)) return 0;
    else return 1;
}