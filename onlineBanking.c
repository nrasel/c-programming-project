#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};
int main()
{
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pwd[50];
    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\n What do you want to do?");
    printf("\n\n1.Register an account");
    printf("\n2.Login to an account");

    printf("\n\nYour choice : \t");
    scanf("%d", &opt);
    if (opt == 1)
    {
        system("cls");
        printf("Enter your account no: ");
        scanf("%s", &usr.ac);
        printf("Enter your phone no: ");
        scanf("%s", &usr.phone);
        printf("Enter your password: ");
        scanf("%s", &usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount successfull register");
        }
        else
        {
            printf("\n\nSomething went wrong!");
        }
        fclose(fp);
    }
    if (opt == 2)
    {
        system("cls");
        printf("Phone number : ");
        scanf("%s", phone);
        printf("Password : ");
        scanf("%s", &pwd);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("Account number not registered");
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pwd, usr.password))
            {
                printf("hello");
                while (cont == 'y')
                {
                    system("cls");
                    printf("\nPress 1 to check balance ");
                    printf("\nPress 2 to deposite an ammount ");
                    printf("\nPress 3 to withdraw balance ");
                    printf("\nPress 4 to transfer the balance ");
                    printf("\nPress 5 to to chance the password ");

                    printf("\n\nYour choice");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current balance is Rs.%.2f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount : ");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("successfully deposite");
                            fclose(fp);
                        }
                        break;
                    case 3:
                        printf("\nEnter the amount : ");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("successfully withdraw");
                            fclose(fp);
                        }
                        break;
                    case 4:
                        printf("\nPlease enter the phone number to transfer the balance:\t");
                        scanf("%s", phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f", &amount);
                        strcpy(filename, phone);
                        fp = fopen(strcat(filename, ".dat"), "r");
                        if (fp == NULL)
                            printf("\nAccount number not registered");
                        else
                        {
                            fread(&usr1, sizeof(struct user), 1, fp);

                            fclose(fp);
                            if (amount > usr.balance)
                                printf("\nInsufficient balance");
                            else
                            {

                                fp = fopen(filename, "w");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1, fp);

                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nYou have succesfully transfered Rs.%.2f to %s", amount, phone);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                            break;
                        case 5:
                            printf("\nPlease enter your new password:\t");
                            scanf("%s", pwd);
                            fp = fopen(filename, "w");
                            strcpy(usr.password, pwd);
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if (fwrite != NULL)
                                printf("\nPassword succesfully changed");
                        }
                        break;
                    default:
                        printf("\nInvalid option");
                        break;
                    }

                    printf("\nDo you want to continue the transaction [y/n]\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\nInvalid password");
            }
        }
    }

    return 0;
}