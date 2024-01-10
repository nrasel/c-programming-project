#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int userScore = 0, comScore = 0;
void checkOptions(int user, int comp)
{
    // 1=scissor 2=paper 3=rock
    if (user == comp)
    {
        printf(" ----------------- \n");
        printf("|   Its a tie     |\n");
        printf(" ----------------- \n");
    }
    else if (user == 1)
    {
        if (comp == 2)
        {
            printf(" -------------------- \n");
            printf("|   You Won :        |\n");
            printf("| You : Scissor      |\n");
            printf("| Computer : Paper   |\n");
            printf(" -------------------- \n");
            userScore++;
        }
        else
        {
            printf(" ------------------------ \n");
            printf("|      You Lose :        |\n");
            printf("|    You : Scissor       |\n");
            printf("|   Computer : Rock      |\n");
            printf(" ------------------------ \n");
            comScore++;
        }
    }
    else if (user == 2)
    {
        if (comp == 1)
        {
            printf(" ----------------------- \n");
            printf("|       You Lose :       |\n");
            printf("|     You : Paper       |\n");
            printf("|   Computer : Scissor  |\n");
            printf(" ----------------------- \n");
            comScore++;
        }
        else
        {
            printf(" ----------------------- \n");
            printf("|       You Win :       |\n");
            printf("|     You : Paper        |\n");
            printf("|   Computer : Rock      |\n");
            printf(" ------------------------ \n");
            userScore++;
        }
    }
    else if (user == 3)
    {
        if (comp == 1)
        {
            printf(" --------------------\n");
            printf("|      You Won :)    |\n");
            printf("| You : Rock        |\n");
            printf("| Computer : Scissor |\n");
            printf(" --------------------\n");
            userScore++;
        }
        else
        {
            printf(" --------------------\n");
            printf("|     You Lose :(    |\n");
            printf("| You : Rock         |\n");
            printf("| Computer : Paper    |\n");
            printf(" --------------------\n");

            comScore++;
        }
    }
    else if (user = 4)
    {
        printf(" --------------------\n");
        if (userScore > comScore)
            printf("|   You Won :   |");
        else if (userScore < comScore)
            printf("|    You Lose :    |\n");
        else
            printf("|    It's a tie    |\n");
        printf("|    Final Score    |\n");
        printf("|   You : %d    |", userScore);
        printf("|   Computer : %d    |", comScore);
        printf(" --------------------\n");
        printf("\a");
    }
    else
    {
        Beep(750, 500);
        printf("\nInvalid Option");
    }
}
int main()
{
    int userChoice, compChoice;
    srand(time(0));
    printf("user=%d", userChoice);
    printf("\t\t\t\t==========*Welcome to Rock, Paper & Scissor Game*==========");
    while (userChoice != 4)
    {
        printf("\nPlease select the option: ");
        printf("\n1.Scissor");
        printf("\n2.Paper");
        printf("\n3.Rock");
        printf("\n4.Quit\n");
        scanf("%d", &userChoice);
        printf("user=%d", userChoice);

        compChoice = (rand() % 3) + 1;
        checkOptions(userChoice, compChoice);
    }
    return 0;
}