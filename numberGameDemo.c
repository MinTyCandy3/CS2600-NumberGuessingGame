#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#define DASHES "---------------------------------------\n"

typedef enum { false, true } bool;

bool checkChoiceValidInput(int choice, int minNum, int maxNum);

// code main here
int main()
{
    // Variables here

    int menuChoice;
    int minNum = 1;
    int maxNum = 10;

    const int MAXIMUM_MAXNUM = 20;
    
    while(true)
    {
        // Ask for user input for options 1-3
        menuChoice = 0;

        printf(DASHES);
        printf("Current Range: %i - %i\n", minNum, maxNum);
        printf("Press 1 to play the game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n\n");

        do
        {
            printf("What would you like to do? : ");
            scanf("%i", &menuChoice);
        }
        while(!checkChoiceValidInput(menuChoice, 1, 3));
        printf(DASHES);

        if(menuChoice == 1)
        {
            /* option 1
            - Randomize a number from 1 - [10 or user's chosen max number] 
            - Ask for user input
            - Repeat until they win or enter 'q'
            */
            
            printf("I have my number! Time to guess! (Enter 'q' if you want to leave the game.)\n\n");
            srand(time(NULL));

            bool leaveGame = false;
            int randomNum = (rand() % maxNum) + 1;
            char userInput[10];
            int userNum;
            do
            {
            
                printf("Guess a number between %d-%d: ", minNum, maxNum);
                gets(userInput);

                if ( userInput[0] == 'q' )
                {
                    break;
                }
                
                userNum = atoi(userInput);
                if(!checkChoiceValidInput(userNum, minNum, maxNum))
                {
                    continue;
                }

                if(userNum == randomNum)
                {
                    printf("Good job! The number was %d!\n", randomNum);
                    break;
                }
                else if (userNum > randomNum)
                {
                    printf("Lower!\n\n");
                }
                else
                {
                    printf("Higher!\n\n");              
                }

            } while (true);
            
            

            
        }
        else if (menuChoice == 2)
        {
            /* option 2
            - Allow user to change the maximum number
            - the maxiumum number the user can pick will be 20 (cannot be <= 0)
            *** - in a separate branch -> save_user_max_number, save the user's choice of max num
            */
            int maxChoice;

            do
            {
                printf("What is the maximum number you would like to pick? (note: Max number is 20!)\n");
                printf("Set max number: ");
                scanf("%i", &maxChoice);
            }
            while(!checkChoiceValidInput(maxChoice, minNum, MAXIMUM_MAXNUM));

            maxNum = maxChoice;
        }
        else if (menuChoice == 3)
        {
            /* option 3
            - Display nice message then end program with EXIT SUCCESS
            */
            printf("Goodbye! Thank you for playing!\n");
            printf(DASHES);
            return EXIT_SUCCESS;
        }
        else
        {
            printf("ERROR: Something went wrong when checking input of menuChoice.\n");
            printf(DASHES);
            return EXIT_FAILURE;
        }

    }

    return EXIT_FAILURE;
}


bool checkChoiceValidInput(int choice, int minNum, int maxNum)
{
    bool isChoiceValid = false;

    while(!isChoiceValid)
    {
            isChoiceValid = true;

            if(choice >= minNum && choice <= maxNum)
            {
                fflush(stdin);
                return true;
            }
            else
            {
                fflush(stdin);
                printf("INVALID INPUT ~ Please enter the correct number (%d-%d)\n\n", minNum, maxNum);
                return false;
            }

    }
}
