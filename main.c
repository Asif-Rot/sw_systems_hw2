#include <stdio.h>
#include <string.h>
#include "myBank.h"

int main()
{
  char Transaction[9999];
  Transaction[1] = '\0';
  while (1)
  {
    printf("\nPlease choose a transaction type: \n");
    printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    scanf("%s", Transaction);
    if(Transaction[1]!='\0')
    {
      Transaction[0]='\0';
      Transaction[1]='\0';
      printf("you wrote too many arguments!\n");
    }
    if (Transaction[0] == 'O')
    {
      double amount;
      printf("Please enter amount for deposit: \n");
      scanf("%lf", &amount);
      openAccount(amount);
    }
    if (Transaction[0] == 'B')
    {
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      checkBalance(accountNum);
    }
    if (Transaction[0] == 'D')
    {
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      deposit(accountNum);
    }

    if (Transaction[0] == 'W')
    {
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      withdraw(accountNum);
    }

    if (Transaction[0] == 'C')
    {
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      closeAccount(accountNum);
    }

    if (Transaction[0] == 'I')
    {
      addInterest();
    }

    if (Transaction[0] == 'P')
    {
      printAccount();
    }

    if (Transaction[0] == 'E')
    {
      closeAccounts();
      break;
    }

    if (Transaction[0] != 'O' && Transaction[0] != 'B' && Transaction[0] != 'D' && Transaction[0] != 'W' && Transaction[0] != 'C' && Transaction[0] != 'I' && Transaction[0] != 'P' && Transaction[0] != 'E')
    {
      printf("invalid command!\n");
    }
  }

  return 0;
}