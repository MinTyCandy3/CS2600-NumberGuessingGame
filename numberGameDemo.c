#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#define DASHES "---------------------------------------\n"

typedef enum { false, true } bool;

char checkChoiceValidInput(char choice, int minNum, int maxNum, bool canQuit);

// code main here
int main()
{
    // Variables here
    char menuChoiceInput;
    int menuChoice;

    int minNum = 1;
    int maxNum = 10;
    
    while(true)
    {
        // Ask for user input for options 1-3
        printf(DASHES);
        printf("Press 1 to play the game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n\n");
        printf("What would you like to do? : ");
        scanf("%i", &menuChoiceInput);   

        menuChoice = (int) checkChoiceValidInput(menuChoiceInput, 1, 3, false);
        printf(DASHES);

        if(menuChoice == 1)
        {
            /* option 1
            - Randomize a number from 1 - [10 or user's chosen max number] 
            - Ask for user input
            - Repeat until they win or enter 'q'
            */
            
            printf("I have my number! Time to guess!\n");
            srand(time(NULL));

            bool leaveGame = false;
            int randomNum = (rand() % maxNum) + 1;
            char userInput;
            int userNum;
            do
            {
            
                fflush(stdin);

                printf("Guess a number between %d-%d: ", minNum, maxNum);
                scanf("%i", &userInput);
                userInput = checkChoiceValidInput(userInput, minNum, maxNum, true);
                userNum = (int) userInput;

                if(!(userInput == 'q'))
                {
                    
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

                }
                else
                {
                    leaveGame = true;
                }

            } while (!(leaveGame));
            
            

            
        }
        else if (menuChoice == 2)
        {
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


char checkChoiceValidInput(char choice, int minNum, int maxNum, bool canQuit)
{
    bool isChoiceValid = false;

    while(!isChoiceValid)
    {
            isChoiceValid = true;

            if(canQuit && choice == 'q')
            {
                fflush(stdin);
                return choice;
            }
            else if((int)choice >= minNum && (int)choice <= maxNum)
            {
                fflush(stdin);
                return choice;
            }
            else
            {
                fflush(stdin);
                isChoiceValid = false;
                printf("INVALID INPUT ~ Please enter the correct number (%d-%d): ", minNum, maxNum);
                scanf("%i", &choice); 
            }

    }
}
