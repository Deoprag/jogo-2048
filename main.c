#include <stdio.h>
#include <stdlib.h>

int main()
{
    char playerNickname[20];
    int gameDifficulty[1] = 2;

    printf ("==========================================\n");
    printf ("\n");
    printf ("             WELCOME TO 2048              \n");
    printf ("\n");
    printf ("==========================================\n");

    printf ("Type a nickname: ");
    scanf ("%s", &playerNickname);

    printf ("Hi, %s, choose your difficulty:\n", playerNickname);
    printf ("---------------------------------------------------------------\n");
    printf ("| Type [1] for EASY | Type [2] for MEDIUM | Type [3] for HARD |\n");
    printf ("          |  Note that if you type any character  |            \n");
    printf ("          | your difficulty will be set as MEDIUM |            \n");
    printf ("---------------------------------------------------------------\n");
    printf ("Enter the value here: ");
    scanf ("%i", &gameDifficulty);
    if (gameDifficulty == 1) {
        printf("Your difficulty has been set to EASY\n");
        } else if (gameDifficulty == 2){
            printf ("Your difficulty has been set to MEDIUM\n");
        } else if (gameDifficulty == 3){
            printf ("Your difficulty has been set to HARD\n");
        } else {
            printf ("Choose a valid value between 1 - 3\n");
        }


}
