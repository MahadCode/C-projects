//C program for turtle graphics
#include<stdio.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define ROW 50
#define COL 50
void processCommand(int,int);
void forwardSteps(int);
void printingFloor();


int arrayfloor[ROW][COL] = {0};
int penposition = 1;
int current_direction = UP;
int x = 0, y = 0;


int main() {
    int command, steps;
    
    int check=1;
    printf("1 Pen up\n2 Pen down\n3 Turn right\n4 Turn left\n5, 10 Move forward 10 spaces (or a number other than 10)\n6 Print the 50-by-50 array\n9 End of data (sentinel)!\nElse are Invalid!\n");
    while (check) {
        printf("Enter Command: ");
        scanf("%d", &command);
        if (command == 9) {
            check=0;
        }

        if (command == 5) {
            int check=1;
            while(check){
            printf("Enter steps: ");
            scanf("%d", &steps);
            if(steps<=50){
                check=0;
            }
            }
        } else {
            steps = 0;
        }

        processCommand(command, steps);
    }

    return 0;
}


void processCommand(int command, int steps){
    switch (command) {
        case 1:
            penposition = 1;
            break;
        case 2:
            penposition = 2;
            break;
        case 3:
            current_direction = (current_direction + 1) % 4;
            break;
        case 4:
            current_direction = (current_direction + 3) % 4;
            break;
        case 5:
            forwardSteps(steps);
            break;
        case 6:
            printingFloor();
            break;
        default:
            break;
    }
}


void forwardSteps(int steps) {
    for (int i = 0; i < steps; i++) {
    switch (current_direction) {
        case UP:
            if (x > 0) 
                {x--;}
            break;
        case RIGHT:
            if (y < ROW - 1) 
                {y++;}
            break;
        case DOWN:
            if (x < ROW - 1) 
                {x++;}
            break;
        case LEFT:
             if (y > 0) 
                {y--;}
            break;
    }
    if (penposition == 2) {
        arrayfloor[x][y] = 1;
    }

}
}

void printingFloor() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arrayfloor[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}