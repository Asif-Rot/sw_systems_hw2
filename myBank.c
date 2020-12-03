#include <stdio.h>
#include "myBank.h"
double bank[3][50];

void openAccount() {
    double amount;
    printf("Please enter amount for deposit: \n");
    scanf("%lf", &amount);

    if(amount > 0)
    {
    int i;
    for (i = 0; i < 50; i++)
    {
        if (bank[1][i] != 1)
        {
            bank[0][i] = i + 901;
            bank[1][i] = 1;
            bank[2][i] = amount;
            printf("New account number is: %d\n", i + 901);
        }
    }
    }
    else
    {
        printf("Invalid amount\n");
        return;
    }
    
    printf("Failed to read the amount\n");
}

void checkBalance() {
    int accountNum;
    printf("Please enter account number: \n");
    scanf("%d", &accountNum);

    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i] != 1)
        {
            bank[1][i] = 0;
        }
    }
    if ((accountNum > 950) || (accountNum < 900))
    {
        printf("illegal account");
        return;
    }
    if (bank[0][accountNum - 901] == accountNum)
    {
        if (bank[1][accountNum - 901] == 1)
        {
            printf("The balance of account number %d is : %.2lf \n", accountNum, bank[2][accountNum - 901]);
            return;
        }
        if (bank[1][accountNum - 901] == 0)
        {
            printf("something is wrong with your account, it's close.\n");
            return;
        }
    }
    printf("no such account!\n");
}

void deposit() {
    int accountNum;
    printf("Please enter account number: \n");
    scanf("%d", &accountNum);

    if ((accountNum > 950) || (accountNum < 900))
    {
        printf("illegal account");
        return;
    }

    double deposit;
    printf("Please enter the amount to deposit: \n");
    scanf(" %lf", &deposit);
    if (deposit < 0)
    {
        printf("You can't deposit a negative number \n");
        return;
    }

    if (bank[1][accountNum - 901] == 1) 
    {
        bank[2][accountNum - 901] += deposit;
        printf("The new balance is: %.2lf \n", bank[2][accountNum - 901]);
        return;
    }
    else
    {
        printf("something is wrong with your account, it's close.\n");
        return;
    }
}

void withdraw() {
    int accountNum;
    printf("Please enter account number: \n");
    scanf("%d", &accountNum);
    if ((accountNum > 950) || (accountNum < 900))
    {
        printf("illegal account");
        return;
    }

    double withdraw;
    printf("Please enter the amount to withdraw: \n");
    scanf(" %lf", &withdraw);
    if (withdraw < 0)
    {
        printf("You can't withdraw a negative number \n");
        return;
    }
    
    if (bank[1][accountNum - 901] == 1) 
    {
        if (withdraw < bank[2][accountNum - 901])
        {
        printf("Your withdraw is too large\n");
        return;
        }

        bank[2][accountNum - 901] -= withdraw;
        printf("The new balance is: %.2lf \n", bank[2][accountNum - 901]);
        return;
    }
    else
    {
        printf("This account is closed.\n");
        return;
    }
        
}

void closeAccount()
{
    int accountNum;
    printf("Please enter account number: \n");
    scanf("%d", &accountNum);

    if ((accountNum > 950) || (accountNum < 900))
    {
        printf("illegal account");
        return;
    }
    if (bank[1][accountNum - 901] == 1) 
    {
        bank[0][accountNum - 901] = 0;
        bank[1][accountNum - 901] = 0;
        bank[2][accountNum - 901] = 0;
        printf("This account is closed \n");
        return;
    }
    else
    {
        printf("Your account is already closed.\n");
        return;
    }
    
}

void addInterest()
{
    double interest_rate;
    printf("Please enter interest rate: \n");
    scanf("%lf", &interest_rate);

    if (interest_rate < 0)
    {
        printf("Interest rate can't be negative\n");
        return;
    }

    for (int i = 0; i < 50; i++)
    {
        bank[2][i] *= (interest_rate / 100) + 1;
    }
    printf("The new balance is increased by: %.2lf", interest_rate);
}

void printAccount()
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i] == 1)
        {
            printf("account number: %d", (int)bank[0][i]);
            printf(", The balance is: %.2lf \n", bank[2][i]);
        }
    }
}

void closeAccounts()
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i] == 1)
        {
            bank[0][i] = 0;
            bank[1][i] = 0;
            bank[2][i] = 0;
        }
    }
    printf("All accounts are closed! \n");
}



