//  Created by Zach Wilcox on 11/7/16.
//  Copyright © 2016 Zach Wilcox. All rights reserved.

#include <stdio.h>
#include <stdlib.h>


/*
    This program allows the user to play Rock, Paper,
 Scissors against the computer. The game will continue
 until the user inputs a 4. The score will be posted
 at the end of each round.
 
 */


// initialize global variables
int choice,h,c, human_score =0, computer_score=0, tie_score = 0;
// ints h for human, c for computer.

//initialize functions
int DetermineWinner(), ComputerPlay(), HumanPlay();
void DisplayScore();

//begin
int main(){
    
    //Prints the welcome and rules for play.
    printf("Rock, Paper, Scissors \n");
    printf("Rock beats Scissors and loses to Paper. \n");
    printf("Paper beats Rock and loses to Scissors. \n");
    printf("Scissors beats Paper and loses to Rock. \n\n");
    while (1){
        
        /*This loop 'keeps the game going' and allows for
         input until the user inputs a 4, or until 
         unaccepted numbers are inputted. */
        
        printf("Press 1 for Rock. \n");
        printf("Press 2 for Paper. \n");
        printf("Press 3 for Scissors. \n");
        printf("Press 4 to exit.\n ");
        scanf(" %d", &choice);
        switch(choice){
            case 1:
                
                // user chose Rock.
                
                h = HumanPlay(1);
                c = ComputerPlay();
                DetermineWinner(h, c);
                DisplayScore();
                break;
                
            case 2:
                
                //user chose Paper.
                
                h = HumanPlay(2);
                c = ComputerPlay();
                DetermineWinner(h, c);
                DisplayScore();
                break;
                
            case 3:
                
                //user chose Scissors.
                
                h = HumanPlay(3);
                c = ComputerPlay();
                DetermineWinner(h, c);
                DisplayScore();
                break;
                
            case 4:
                
                //User chose to end the program.
                
                return 0;
                
            default:
                
                //If the number from the user is not supported
                
                printf("\nInvalid input! Accepted values: 1,2,3,4. \n\n");
                
        }
        
    }
}

int DetermineWinner(h,c){
    
    /* This program takes the results of HumanPlay() and 
     ComputerPlay() and determines which player won that 
     round of play. The global variables are updated for
     DisplayScore() to use. */
    
    //If human picks Rock.
    if(h == 1){
        switch(c){
            case 1:
                printf("It's a tie!! \n");
                tie_score = tie_score+1;
                return 3;
            case 2:
                printf("Computer wins! Paper beats Rock. \n");
                computer_score = computer_score +1;
                return 1;
            case 3:
                printf("You win! Rock beats Scissors. \n");
                human_score = human_score+1;
                return 2;
                
        }
        
    }else if(h == 2){ //If human picks Paper.
        switch(c){
            case 1:
                printf("You win! Paper beats Rock. \n");
                computer_score = computer_score+1;
                return 2;
            case 2:
                printf("It's a tie!! \n");
                tie_score = tie_score+1;
                return 3;
            case 3:
                printf("Computer wins! Scissors beat Paper.\n");
                computer_score=computer_score+1;
                return 1;
                
        }
    }else{ //If human picks Scissors.
        switch(c){
            case 1:
                printf("Computer wins! Rock beats Scissors. \n");
                computer_score = computer_score+1;
                return 1;
            case 2:
                printf("You win! Scissors beats Paper. \n");
                return 2;
            case 3:
                printf("It's a tie!! \n");
                tie_score = tie_score +1;
                return 3;
                
        }
    }
    return 0;
}

int ComputerPlay(){
    
    /* This function generates a random choice to be played by
     the computer. If the computer chooses 1, that's processed
     as Rock. 2 is processed as Paper. 3 is processed as 
     Scissors. */
    
    int computerChoice = rand() % 3;
    switch(computerChoice){
        case 0:
            puts("Computer chose Rock.\n");
            return 1;
        case 1:
            puts("Computer chose Paper. \n");
            return 2;
        case 2:
            puts("Computer chose Scissors. \n");
            return 3;
    }return 0;
}

int HumanPlay(h){
    
    /* This function takes the user input and processes it as
     either Rock, Paper, or Scissors. */
    
    switch(h){
        case 1:
            printf("You chose Rock. \n");
            return 1;
        case 2:
            printf("You chose Paper. \n");
            return 2;
        case 3:
            printf("You chose Scissors. \n");
            return 3;
    }
    return 0;
}

void DisplayScore(){
    
    /* This function displays the scores for the computer, player, and number
    of ties. */
    
    printf("\nYou have %d points, computer has %d points, and %d ties. \n\n\n", human_score, computer_score,tie_score);
}
