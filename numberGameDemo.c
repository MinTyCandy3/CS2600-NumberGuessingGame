#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>

typedef enum { false, true } bool;

int checkChoiceValidInput(int choice, int minNum, int maxNum);

// code main here
int main()
{
    
    // Variables here
    int menuChoice;
    bool invalidInput = false;

    int minNum = 1;
    int maxNum = 10;

    // Ask for user input for options 1-3

        /*

        example output:
        ---------------------------------------
        Press 1 to play a game
        Press 2 to change the max number
        Press 3 to quit

        What would you like to do? : [user input]
        ---------------------------------------
        */

    printf("---------------------------------------\n");
    printf("Press 1 to play the game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n\n");
    printf("What would you like to do? : ");
    scanf("%i", &menuChoice);   

    menuChoice = checkChoiceValidInput(menuChoice, 1, 3);
    printf("---------------------------------------\n");

    

    /* option 1
    - Randomize a number from 1 - [10 or user's chosen max number] 
    - Ask for user input
    - Repeat until they win or enter 'q'
    */

        /*

        test case: number is 7

        example output:
        ---------------------------------------
        Guess a number between 1-10: 5
        Higher!

        Guess a number between 1-10: 11
        INVALID INPUT: Number is not within the bounds!

        Guess a number between 1-10: 7
        Good job! The number was 7!
        ---------------------------------------
        [go back to menu output]

        */


    

    /* option 2
    - Allow user to change the maximum number
    - the maxiumum number the user can pick will be 20 (cannot be <= 0)
    *** - in a separate branch -> save_user_max_number, save the user's choice of max num
    */

        /*

        example output:
        ---------------------------------------
        What is the maximum number you would like to pick? (note: Max number is 20!)
        19

        Okay! The range is now 1 - 19
        ---------------------------------------
        [go back to menu output]
        
        */

   /* option 3
   - Display nice message then end program with EXIT SUCCESS
   */

}


int checkChoiceValidInput(int choice, int minNum, int maxNum)
{
    bool isChoiceValid = false;

    while(!isChoiceValid)
    {
            isChoiceValid = true;
            if(choice >= minNum && choice <= maxNum)
            {
                fflush(stdin);
                return choice;
            }
            else
            {
                fflush(stdin);
                isChoiceValid = false;
                printf("INVALID INPUT ~ Please enter the correct choice (%d-%d): ", minNum, maxNum);
                scanf("%i", &choice); 
            }

    }
}
