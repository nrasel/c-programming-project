#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
int main()
{
    // system("color 3f");
    int pin = 1234, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;

    // current date and time
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t%s", ctime(&now));
    printf("\n\t\t\t=========*Welcome to naimru ATM*==========");

    while (pin != enteredPin)
    {
        printf("\nPlease enter your pin : ");
        scanf("%d", &enteredPin);
        if (enteredPin != pin)
        {
            Beep(610, 500);
            printf("Invalid pin!!!");
        }
        count++;
        if (count == 3 && pin != enteredPin)
        {
            exit(0);
        }
    }

    while (continueTransaction != 0)
    {
        printf("\n\t===========*Available Transaction*===========");
        printf("\n\n\t1.Withdrawl");
        printf("\n\n\t2.Deposit");
        printf("\n\n\t3.Check Balance");
        printf("\n\n\tPlease select the option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            while (amount % 500 != 0)
            {
                printf("\n\t\tEnter the amount : ");
                scanf("%d", &amount);
                if (amount % 500 != 0)
                {
                    printf("\n]t The amount should be multiple of 500");
                }
            }
            if (balance < amount)
            {
                printf("\n\t Sorry insufficient balance");
                amount = 1;
                break;
            }
            else
            {
                balance = balance - amount;
                printf("\n\tYou have withdraw Rs.%d. your new balance is %.2f", amount, balance);
                amount = 1;
                break;
            }
        case 2:
            printf("\n\t\t Please enter the amount : ");
            scanf("%d", &amount);
            balance = balance + amount;

            printf("\n\tYou have Deposite Rs.%d. your new balance is %.2f", amount, balance);
            printf("\n\t=========Thank's for choosing us========");
            amount = 1;
            break;
        case 3:
            printf("\n\t\t Your Balance Rs. %.2f", balance);
            break;
        default:
            Beep(610, 500);
            printf("\n\t\tInvalid Option!!");
        }
        printf("\n\t\tDo you wish to perform another transaction?Press 1[Yes],0[No]");
        scanf("%d", &continueTransaction);
    }

       return 0;
}