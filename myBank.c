#include <stdio.h> 
#include "myBank.h"
double bank[3][50]={0};

void openAccount() {
    double amount;
    printf("Please enter amount for deposit: ");
    if((scanf("%lf", &amount))!=0)
    {    
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
                    return;
                }
            }
        }
        else if (amount<0)
        {
            printf("Invalid amount\n");
            return;
        }
    }
    else
    {
        printf("Failed to read the amount\n");
        return;
    }    
}

void checkBalance() {
    int accountNum;
    printf("Please enter account number: ");
    if(scanf("%d", &accountNum)!=0)
    { 
        if ((accountNum > 950) || (accountNum < 900))
        {
        printf("Invalid account number\n");
        return;
        }
        for (int i = 0; i < 50; i++)
        {
            if (bank[1][i] != 1)
            {
                bank[1][i] = 0;
            }
        }
    
        if (bank[0][accountNum - 901] == accountNum)
        {
            if (bank[1][accountNum - 901] == 1)
            {
                printf("The balance of account %d is: %.2lf\n", accountNum, bank[2][accountNum - 901]);
                return;
            }
            if (bank[1][accountNum - 901] == 0)
            {
                printf("This account is closed\n");
                return;
            }
        }
    }
    else
    {
    printf("Failed to read the account number\n");
    return;    
    }
    return;
}

void deposit() {
    int accountNum;
    printf("Please enter account number: ");
    if(scanf("%d", &accountNum)!=0)
    {
        if ((accountNum > 950) || (accountNum < 900))
        {
            printf("Invalid account number\n");
            return;
        }
        if (bank[1][accountNum - 901] == 1) 
        {
            double deposit;
            printf("Please enter the amount to deposit: ");
            if(scanf("%lf", &deposit)!=0)
            {
                if (deposit < 0)
                {
                    printf("Cannot deposit a negative amount\n");
                    return;
                }
                else
                {
                bank[2][accountNum - 901] += deposit;
                printf("The new balance is: %.2lf \n", bank[2][accountNum - 901]);
                return;
                }
            }
            else
            {
                printf("Failed to read the amount\n");
                return;
            }
        }
        else
        {
            printf("This account is closed\n");
            return;    
        }
    }
    printf("Failed to read the account number\n");
    return;    
}

void withdraw() {
    int accountNum;
    printf("Please enter account number: ");
    if(scanf("%d", &accountNum)!=0)
    {
        if ((accountNum > 950) || (accountNum < 900))
        {
            printf("Invalid account number\n");
            return;
        }
        if(bank[1][accountNum-901]==1)
        {
            double withdraw;
            printf("Please enter the amount to withdraw: ");
            if(scanf("%lf", &withdraw)!=0)
            {
                if (withdraw < 0)
                {
                    printf("Cannot withdraw a negative number\n");
                    return;
                }
                if (withdraw > bank[2][accountNum - 901])
                {
                    printf("Cannot withdraw more than the balance\n");
                    return;
                }

                bank[2][accountNum - 901] -= withdraw;
                printf("The new balance is: %.2lf\n", bank[2][accountNum - 901]);
                return;
            }
            else
            {
                printf("Failed to read the amount\n");
                return;
            }
        }
        else
        {
            printf("This account is closed\n");
            return;
        }
    }
    else
    {
        printf("Failed to read the account number\n");
        return;  
    }
}

void closeAccount(){
    int accountNum;
    printf("Please enter account number: ");
    if(scanf("%d", &accountNum)!=0)
    {
        if ((accountNum > 950) || (accountNum < 900))
        {
            printf("Invalid account number\n");
            return;
        }
        if (bank[1][accountNum - 901] == 1) 
        {
            bank[0][accountNum - 901] = 0;
            bank[1][accountNum - 901] = 0;
            bank[2][accountNum - 901] = 0;
            printf("Closed account number %d\n", accountNum );
            return;
        }
        else
        {
            printf("This account is already closed\n");
            return;
        }
    
    }
    else
    {
        printf("Failed to read the account number\n");
        return;  
    }
    return;
}

void addInterest(){
    int interest_rate;
    printf("Please enter interest rate: ");
    if(scanf("%d", &interest_rate)!=0)
    {
        if (interest_rate < 0)
        {
            printf("Invalid interest rate\n");
            return;
        }
        for (int i = 0; i < 50; i++)
        {
        bank[2][i] *= (interest_rate / 100) + 1;
        }
    }
    else
    {
        printf("Failed to read the interest rate\n");
        return;  
    } 
    return;   
}

void printAccount(){
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i] == 1)
        {
            printf("The balance of account %d is: %.2lf\n",(int)bank[0][i],bank[2][i]);
        }
    }
    return;
}

void closeAccounts(){
    for (int i = 0; i < 50; i++)
    {
        if (bank[1][i] == 1)
        {
            bank[0][i] = 0;
            bank[1][i] = 0;
            bank[2][i] = 0;
        }
    }
    return;
}



